#include "../../ALL_H_FILES.h"

// =============================================================

// First implementation
char toLowerCase(char c)
{
    return static_cast<char>(static_cast<int>(c) + 32); 
}

bool isUnique(std::string s) // ASCII string
{
    if (s.empty()) return 0; // s = ""
    if (s == " ") return 0;

    std::array<bool, 128> aus = {};

    for (auto c : s)
    {
        if (static_cast<int>(c) >= 65 && static_cast<int>(c) <= 90)
            c = toLowerCase(c);
        if (aus[static_cast<int>(c)]) 
        {
            return false;
        }
        aus[c] = true;
    }
    return true;
}

// =============================================================

// Second implementation
bool isUnique(std::string s) // ASCII string ('a' to 'z')
{
    // c++ int has 4-bytes (32-bit)
    int check = 0; //bit vector => 0000 0000 0000 0000 0000 0000 0000 0000
    for (auto c : s)
    {
        int aus = static_cast<int>(c - 'a'); // lead back into the range 0 - 32
                                             // if c is 'a' => 0000 0000 0000 0000 0000 0000 0000 0001
        int leftShift = (1 << aus); // left shift by aus position of 1
        if ((check & leftShift) > 0) return false; // logic and between check and left shift
                                                   // 0000 0000 0000 0000 0000 0000 0000 0000 &
                                                   // 0000 0000 0000 0000 0000 0000 0000 0001 = 
                                                   // 0000 0000 0000 0000 0000 0000 0000 000 
                                                   // (because there are not two ones in the same position) 
        
        check = check | leftShift;                 // 0000 0000 0000 0000 0000 0000 0000 0000 |
                                                   // 0000 0000 0000 0000 0000 0000 0000 0001 = 
                                                   // 0000 0000 0000 0000 0000 0000 0000 0001
                                                   // (push 1 in the relative position)
    }
    return true;

}

// =============================================================

// int main()
// {
//     std::string s1("ciao");
//     std::string s2("ciaoo");
//     std::string val1 = isUnique(s1) ? "true" : "false";
//     std::cout << s1 << " is unique? " << val1 << std::endl;
//     std::string val2 = isUnique(s2) ? "true" : "false";
//     std::cout << s2 << " is unique? " << val2 << std::endl;
// }