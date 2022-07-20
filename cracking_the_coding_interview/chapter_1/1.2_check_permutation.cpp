#include "../../ALL_H_FILES.h"

// First implementation
// void sortString(std::string &s)
// {
//     std::sort(s.begin(), s.end());
// }

// bool permutation(std::string s, std::string t)
// {
//     if (s.size() != t.size()) return false;
//     sortString(s);
//     sortString(t);
//     return (s == t);
    
// }

// Second implementation
bool permutation(std::string s, std::string t) // ASCII string
{
    std::array<int, 128> aus = {};

    for (char c : s)
    {
        aus[static_cast<int>(c)]++;
    }
    for (char c : t)
    {
        aus[static_cast<int>(c)]--;
        if (aus[static_cast<int>(c)] < 0) return false;
    }
    return true;
}

int main()
{
    std::string s1 = "ciao";
    std::string s2 = "oaic";
    std::string aus1 = permutation(s1, s2) ? "true" : "false";
    std::cout << aus1 << std::endl;

    std::string s3 = "ciao";
    std::string s4 = "oaicc";
    std::string aus2 = permutation(s3, s4) ? "true" : "false";
    std::cout << aus2 << std::endl;
}