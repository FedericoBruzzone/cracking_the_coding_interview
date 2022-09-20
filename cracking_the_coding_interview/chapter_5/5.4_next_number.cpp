#include "../../ALL_H_FILES.h"

// =============================================================

// Bit manipulation implementation
int getNext(int n)
{
    int c = n;
    int c0 = 0;
    int c1 = 0;

    while (((c & 1) == 0) && (c != 0))
    {
        ++c0;
        c >>= 1;
    }

    while ((c & 1) == 1)
    {
        ++c1;
        c >>= 1;
    }

    if (c0 + c1 == 31 || c0 + c1 == 0) { return -1; }

    int p = c0 + c1;

    n |= (1 << p); // Flip rightmost non-trailing zero
    
    {
        int a = 1 << p;
        int b = a - 1;
        int mask = ~b;
        n &= mask;
        // n &= ~((1 << p) - 1)
    } // Clear all bits to the right of p

    {
        int a = 1 << (c1 - 1);
        int b = a - 1;
        n |= b;
        // n |= (1 << (c1 - 1)) - 1
    } // Insert (c1 - 1) ones on the right

    return n;
}

int getPrevious(int n)
{
    int c = n;
    int c0 = 0;
    int c1 = 0;

    while ((c & 1) == 1)
    {
        c >>= 1;
        ++c1;
    }

    if (c == 0) { return -1; }

    while((c & 1) == 0 && (c != 0))
    {
        c >>= 1;
        ++c0;
    }

    int p = c0 + c1;
    
    {
        int a = ~0;
        int b = a << (c1 + 1);
        n &= b;
        // n &= ((~0) << (c1 + 1))
    } // Clears from bit p onwards

    {
        int a = 1 << (c1 + 1);
        int b = a - 1;
        int mask = b << (c0 - 1);
        n |= mask;
        // n |= ((1 << (c1 + 1)) - 1) << (c0 - 1))
    } // Sequence of (c1 + 1) ones
    return n;
}

// =============================================================

// int main()
// {
//     LOG(getNext(100))
//     LOG(getPrevious(100))
// }