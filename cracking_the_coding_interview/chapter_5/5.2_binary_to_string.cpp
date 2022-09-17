#include "../../ALL_H_FILES.h"

// =============================================================

// First implementation
std::string printBinary1(double num)
{
    if (num > 1 || num < 0) { return "ERROR"; }
    if (num == 1) { return "1"; }
    if (num == 0) { return "0"; }

    std::stringstream ss;
    ss << "0.";

    while (num != 0)
    {
        if (ss.tellp() > 32) { return "ERROR"; }

        double tmp = 2 * num;
        if (tmp >= 1) 
        { 
            ss << '1'; 
            num = tmp - 1;
        }
        else
        {
            ss << '0';
            num = tmp;
        }

    }
    return ss.str();
}

// Second implementation
std::string printBinary2(double num)
{
    if (num > 1 || num < 0 ) { return "ERROR"; }
    if (num == 1) { return "1"; }
    if (num == 0) { return "0"; }

    std::stringstream ss;
    ss << "0.";
    double mantissaBit = 0.5;
    
    while (num != 0)
    {
        if (ss.tellp() > 32) { return " ERROR"; }

        if (num >= mantissaBit) 
        {
            ss << '1';
            num -= mantissaBit;
        }
        else
        {
            ss << '0';
        }

        mantissaBit /= 2;
    }
    return ss.str();
}  

// =============================================================
// int main()
// {
//     double value = 0;
//     double frac = 1.0 / 2 + 1.0 / 8;

//     std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);

//     for (int i = 0; i < 10; ++i)
//     {
//         std::cout << value << ": " << printBinary1(value) << "(b), " << printBinary2(value) << "(b)\n";
//         value += frac;
//         frac /= 16;
//     }
// }