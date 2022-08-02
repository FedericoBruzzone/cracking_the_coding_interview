#include "../../ALL_H_FILES.h"

// =============================================================

bool isRotation(std::string s1, std::string s2)
{
    int lengthS1 = s1.size();
    int lengthS2 = s2.size();

    if (lengthS1 == lengthS2 && lengthS1 > 0)
    {
        std::string s1s1 = s1 + s1;
        return s1s1.find(s2) != std::string::npos;
    }
    return false;
}

// =============================================================

int main()
{
    std::string s1 = "waterbottle";
    std::string s2 = "erbottlewat";

    LOG(isRotation(s1,s2));
}