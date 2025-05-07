#include "io.h"

#include <string>
#include <iostream>

std::string getUserLineInput()
{
    std::string line{};
    std::getline(std::cin >> std::ws, line);
    return line;
}

int getUserNum()
{
    int num{};
    std::cin >> num;
    return num;
}
