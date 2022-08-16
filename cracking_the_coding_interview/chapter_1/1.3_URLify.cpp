#include "../../ALL_H_FILES.h"

// =============================================================

int countOfChar(std::string s, int start, int end, char target)
{
    int aus = 0;
    for (int i = start; i < end; i++)
    {
        if (s.at(i) == target) aus++;
    }
    return aus;
}

void replaceSpaces(std::string &s, int trueLength)
{
    int numberOfSpaces = countOfChar(s, 0, trueLength, ' ');
    int newIndex = numberOfSpaces * 2 + trueLength - 1;

    if (newIndex + 1 < s.size()) s[newIndex + 1] = '\0';
    for (int oldIndex = trueLength - 1; oldIndex >= 0; oldIndex--)
    {
        if (s[oldIndex] == ' ')
        {
            s[newIndex] = '0';
            s[newIndex - 1] = '2';
            s[newIndex - 2] = '%';
            newIndex -= 3;
        }
        else
        {
            s[newIndex] = s[oldIndex];
            newIndex--;
        }
    }
}

// =============================================================

// int main() 
// {
//     std::string s1 = "Mr John Smith    ";
//     int trueLength = 13;
//     std::cout << s1 << std::endl;
//     replaceSpaces(s1, trueLength);
//     std::cout << s1 << std::endl;
// }