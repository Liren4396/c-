#include <iostream>
#include <string>
#include <vector>

std::string join(std::vector<std::string> vec, std::string delimiter) {
    std::string ret;
    for (int i = 0; i < vec.size()-1; ++i) {
        ret += vec[i];
        ret += delimiter;
    }
    ret += vec[vec.size()-1];
    return ret;
}

int main() {
    std::vector<std::string> vec = { "nihao", "wojia", "zaima" };
    std::string delimiter = "123";
    std::string ret = join(vec, delimiter);
    std::cout << ret << std::endl;
}