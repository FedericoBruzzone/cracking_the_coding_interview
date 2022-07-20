#include "../../ALL_H_FILES.h"

// First implementation
// std::string compressionString(std::string s)
// {
//     std::string temp = "";
//     int countConsecutive = 0;

//     for (int i = 0; i < s.size(); i++)
//     {
//         countConsecutive++;

//         if (s.at(i) != s.at(i+1) || i + 1 >= s.size())
//         {
//             temp += s.at(i) + std::to_string(countConsecutive);
//             countConsecutive = 0;
//         }
//     }
//     return temp.size() < s.size() ? temp : s;
// }

// Second implementation
std::string compressionString(std::string s)
{
    std::stringstream ss;
    int countConsecutive = 0;

    for (int i = 0; i < s.size(); i++)
    {
        countConsecutive++;

        if (s.at(i) != s.at(i+1) || i + 1 >= s.size())
        {
            ss.put(s.at(i));
            ss.put(char(countConsecutive));
            countConsecutive = 0;
        }
    }
    return ss.str().size() < s.size() ? ss.str() : s;;
}

int main()
{
    std::string s = compressionString("aaabbbbcccc");
    LOG(s);
}