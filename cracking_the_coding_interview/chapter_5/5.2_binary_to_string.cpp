#include "../../ALL_H_FILES.h"

// =============================================================

std::string printBinary(double num)
{
    if (num > 1 || num < 0) { return "ERROR"; }
    if (num == 1) { return "1"; }
    if (num == 0) { return "0"; }

    std::stringstream s;
    s << "0.";

    while (num != 0)
    {
        if (s.tellp() > 32) { return "ERROR"; }

        double tmp = 2 * num;
        if (tmp >= 1) 
        { 
            s << '1'; 
            num = tmp - 1;
        }
        else
        {
            s << '0';
            num = tmp;
        }

    }
    return s.str();
}

// =============================================================
int main()
{
    double value = 0;
    double frac = 1.0 / 2 + 1.0 / 8;

    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1);

    for (int i = 0; i < 10; ++i)
    {
        std::cout << value << ": " << printBinary(value) << "(b), " << printBinary(value) << "(b)\n";
        value += frac;
        frac /= 16;
    }
}