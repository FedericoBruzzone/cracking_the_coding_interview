#include "../ALL_H_FILES.h"

// First implementation
// bool isPermutationOfPalindrome(std::string s)
// {
//     std::vector<int> table = buildCharFrequencyTable(s);
//     return checkMaxOneOdd(table);
// }

// std::vector<int> buildCharFrequencyTable(std::string s)
// {
//     std::vector<int> table(static_cast<int>('z') - 
//                            static_cast<int>('a') + 1);
//     int count = 0;

//     for (char c : s)
//     {
//         int index = getCharNumber(c);
//         if (index != -1) table[index]++;
//     }

//     return table;
// }

// bool checkMaxOneOdd(std::vector<int> table)
// {
//     bool foundOdd = false;

//     for (int i = 0; i < table.size(); i++)
//     {
//         if (table[i] % 2 != 0)
//         {
//             if (foundOdd)
//             {
//                 return false;
//             }
//             else
//             {
//                 foundOdd = true;
//             }
//         }
//     }
//     return true;
// }

// Second implementation
// int getCharNumber(char c)
// {
//     int a = static_cast<int>('a');
//     int z = static_cast<int>('z');
//     int val = static_cast<int>(c);

//     if (val <= z && val >= a)
//     {
//         return val - a;
//     }
//     return -1;
// }

// bool isPermutationOfPalindrome(std::string s)
// {
//     std::vector<int> table(static_cast<int>('z') - 
//                            static_cast<int>('a') + 1);
//     int countOdd = 0;

//     for (char c : s)
//     {
//         int index = getCharNumber(c);
//         if (index != -1)
//         {
//             table[index]++;
//             if (table[index] % 2 == 1)
//             {
//                 countOdd++;
//             }
//             else
//             {
//                 countOdd--;
//             }
//         }
//     }

//     return countOdd <= 1;
// }

// Third implementation
int toggle(int bitVector, int index)
{
    if (index == 0) return bitVector;

    int mask = 1 << index;
    bitVector ^= mask; //XOR
    return bitVector;
}

int createBitVector(std::string s)
{
    int bitVector = 0;
    for (char c : s)
    {
        bitVector = toggle(bitVector, static_cast<int>(c));
    }
    return bitVector;
}

bool checkAtMostOneBitSet(int bitVector)
{
    return (bitVector & (bitVector - 1)) == 0;
}

bool isPermutationOfPalindrome(std::string s)
{
    int bitVector = createBitVector(s);
    return checkAtMostOneBitSet(bitVector);
}