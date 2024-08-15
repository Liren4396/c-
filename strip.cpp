
#include <iostream>
#include <string>

void strip(std::string& ret, std::string specified_str = " ") {
    int curr_pos = 0;
    while (curr_pos < ret.size() && ret.substr(curr_pos, specified_str.size()) == specified_str) 
        curr_pos += specified_str.size();
    ret = ret.substr(curr_pos, ret.size()-curr_pos);
    curr_pos = ret.size()-1;
    while (curr_pos >= 0 && ret.substr(curr_pos, specified_str.size()) == specified_str)
        curr_pos -= specified_str.size();
    ret = ret.substr(0, curr_pos+1);

}

int main() {
    std::string ret = " ddabcd  ";
    strip(ret);
    std::cout << "|" << ret << "|" << std::endl;
}