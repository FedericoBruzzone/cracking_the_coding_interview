#include "../../ALL_H_FILES.h"

// =============================================================

// First implementation
int bitSwapRequired(int a, int b)
{
    int count = 0;

    while (a != 0 || b != 0)
    {
        if ((a & 1) != (b & 1)) { ++count; }

        a >>= 1;
        b >>= 1;
    }

    return count;
}

// Second implementation
int bitSwapRequired(int a, int b)
{
    int count = 0;

    int c = a ^ b;

    while (c != 0)
    {
        count += (c & 1);
        c >>= 1;
    }

    return count;
}

// =============================================================
// int main()
// {
//     LOG(bitSwapRequired(29, 15))
// }
