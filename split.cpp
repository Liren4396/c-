#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> split(std::string text, std::string delimiter) {
    std::vector<std::string> ret;
    int curr_pos = 0;
    int n = delimiter.size();
    int prev = curr_pos;
    while (curr_pos < text.size()) {
        if (text.compare(curr_pos, n, delimiter) == 0) {
            
            ret.emplace_back(text.substr(prev, curr_pos-prev));
            curr_pos += n;
            prev = curr_pos;
        } else ++curr_pos;
    }
    if (curr_pos != prev) {
        ret.emplace_back(text.substr(prev, curr_pos - prev));
    }
    return ret;
}

int main() {
    std::string text = "hello##world##this##is##a##test";
    std::string delimiter = "##";
    std::vector<std::string> ret = split(text, delimiter);
    for (std::string str : ret) {
        std::cout << str << std::endl;
    }
    std::cout << "size: " << ret.size() << std::endl;
}           