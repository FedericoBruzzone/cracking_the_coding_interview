#include "../ALL_H_FILES.h"

// First implemetation
// bool oneEditAway(std::string first, std::string second)
// {
//     if (first.size() == second.size())
//     {
//         return oneEditReplace(first, second);
//     } 
//     else if (first.size() + 1 == second.size())
//     {
//         return oneEditInsert(first, second);
//     }
//     else if (first.size() - 1 == second.size())
//     {
//         return oneEditInsert(second, first);
//     }
// }

// bool oneEditReplace(std::string first, std::string second)
// {
//     bool foundDifference = false;
//     for (int i = 0; i < first.size(); i++)
//     {
//         if (first.at(i) != second.at(i))
//         {
//             if (foundDifference)
//             {
//                 return false;
//             }
//             else
//             {
//                 foundDifference = true;
//             }
//         }
//     }
//     return true;
// }

// bool oneEditInsert(std::string first, std::string second)
// {
//     int index1 = 0;
//     int index2 = 0;

//     while (index1 <= first.size() && index2 <= second.size())
//     {
//         if (first.at(index1) != second.at(index2))
//         {
//             if (index1 != index2) return false;
//             index2++;
//         }
//         else
//         {
//             index1++;
//             index2++;
//         }
//     }
//     return true;
// }

// Second implementation
bool oneEditAway(std::string first, std::string second)
{
    if (std::abs(static_cast<int>(first.size() - second.size())) > 1) return false; 

    std::string s1 = first.size() < second.size() ? 
                     first :
                     second;

    std::string s2 = first.size() < second.size() ? 
                     second :
                     first;
    
    
    int index1 = 0;
    int index2 = 0;
    bool foundDifference = false;

    while (index1 <= s1.size() && index2 <= s2.size())
    {
        if (s1.at(index1) != s2.at(index2))
        {
            if (foundDifference) return false;
            foundDifference = true;

            if (s1.size() == s2.size()) index1++;
        } 
        else
        {
            index1++;
        }
        index2++;
    }

}