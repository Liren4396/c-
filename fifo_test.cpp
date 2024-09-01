#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define FIFO_PATH "./test1.cpp"
// 进程间通信 命名管道
int fifo_read() {
    int ret = mkfifo(FIFO_PATH, 0644);
    if ((ret == -1) && (errno != EEXIST)) 
    {
        perror("mkfifo");
        return -1;
    }
    int fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }
    while (1) {
        char buf[1024] = {0};
        read(fd, buf, 1024);
        printf("buf: %s\n", buf);
    }
    return 0;

}

int fifo_write(const char *buf) {
    int ret = mkfifo(FIFO_PATH, 0644);
    if ((ret == -1) && (errno != EEXIST)) 
    {
        perror("mkfifo");
        return -1;
    }
    int fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("open failed");
        return -1;
    }
    while (1) {
        write(fd, buf, strlen(buf));
        // sleep(1);
    }
    return 0;
}

int test() {
    int ret = mkfifo(FIFO_PATH, 0644);
    if ((ret == -1) && (errno != EEXIST)) 
    {
        perror("mkfifo");
        return -1;
    }
    
    ret = fork();
    if (ret == 0) {
        int fd = open(FIFO_PATH, O_RDONLY);
        if (fd == -1) {
            perror("open failed");
            return -1;
        }
        while (1) {
            char buf[1024] = {0};
            read(fd, buf, 1024);
            printf("buf: %s\n", buf);
        }

    } else if (ret > 0) {
        int fd = open(FIFO_PATH, O_WRONLY);
        if (fd == -1) {
            perror("open failed");
            return -1;
        }
        while (1) {
#define TEST_STRING "12345678"
            write(fd, TEST_STRING, strlen(TEST_STRING));
            sleep(1);
        }
    } else {

    }
    return 0;
}

int main(int argc, char *argv[]) {
#if 1
    test();
#else

#endif
/*
    int mode = atoi(argv[1]);
    char *buf = argv[2];
    if (mode == 0) {
        fifo_read();
    } else {
        fifo_write(buf);
    }
*/
    return 0;
}