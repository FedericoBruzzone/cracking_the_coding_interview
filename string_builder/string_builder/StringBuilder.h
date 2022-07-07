#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iterator>

class StringBuilder
{
private:
    std::vector<std::string> stringBuilder;

public:
    StringBuilder();
    ~StringBuilder();

    void append(std::string newString);

    std::string toString();
};