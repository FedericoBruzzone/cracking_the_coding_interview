#include "../../ALL_H_FILES.h"
#include "bitutils.cpp"

// =============================================================

int swapOddEvenBits(int x)
{
    int n1 = x & 0xaaaaaaaaaaaaaaaa >> 1;
    int n2 = x & 0x5555555555555555 << 1;
    return (n1 | n2);
}

// =============================================================

int main()
{
    // (10_d)1010_b => (5_d)0101_b
    LOG(bits(10))
    LOG(bits(swapOddEvenBits(10)))
}