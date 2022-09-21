#pragma once

#include "../../../ALL_H_FILES.h"

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