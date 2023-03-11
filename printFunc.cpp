#include <iostream>

std::string print(std::string str, bool toIncludeEndl) {
    if (toIncludeEndl) { std::cout << str << std::endl; }
    else { std::cout << str; }
    return str;
}