#include <iostream>
#include "StringBuilder.h"
#include "StringBuilder.cpp"

int main()
{
    StringBuilder stringBuilder;

    stringBuilder.append("10");

    std::cout << stringBuilder.toString() << std::endl;
}