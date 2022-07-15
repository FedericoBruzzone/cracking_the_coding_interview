#include "StringBuilder.h"

StringBuilder::StringBuilder() {}

StringBuilder::~StringBuilder() {}

void StringBuilder::append(std::string newString)
{
    if (newString == "") return;

    stringBuilder.push_back(newString);
}

std::string StringBuilder::toString()
{
    std::stringstream ss;
    for (auto it = stringBuilder.begin(); it != stringBuilder.end(); it++)    
    {
        if (it != stringBuilder.begin()) {
            ss << " ";
        }
        ss << *it;
    }

    return ss.str();
}