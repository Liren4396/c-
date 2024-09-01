#include <unistd.h>
#include <stdio.h>
#include <string.h>
// 进程间通信 无名管道
int pipe_test() {
    int fd[2] = {0};
    int ret = pipe(fd);
    if (ret == -1) {
        perror("pipe");
        return -1;
    }
    ret = fork();
    if (ret == 0) {
        printf("child\n");
        close(fd[0]);
#define Test_String "123456789"
        while (1) {
            write(fd[1], Test_String, strlen(Test_String));
            sleep(1);
            
        }
    } else if (ret > 0) {
        printf("parent\n");
        close(fd[1]);
        int r = fork();
        if (r == 0) {
            while (1) {
                char buf[128] = {0};
                read(fd[0], buf, 128);
                printf("buf: %s\n", buf);
            }
        }
        
    } else {

    }
    return 0;
}

int main(int argc, char* argv[]) {
    pipe_test();
    return 0;
}