#include "../../ALL_H_FILES.h"

// =============================================================

int include(uint32_t &N, uint32_t &M, uint32_t i, uint32_t j)
{
    if (i > j) return -1; 

    // uint32_t allOnes = ~0; // 11111111
    // uint32_t left = allOnes << (j + 1); // 11100000
    // uint32_t right = (1 << i) - 1; // 00000001
    // uint32_t mask = left | right; // 11100001

    // N &= mask;
    // M = M << i;
    // N |= M;
    // return N;
    return (N & (~0 << (j + 1))) | (M << i);
}

// =============================================================

// int main()
// {
//     uint32_t N = 0b10010100;
//     uint32_t M = 0b1101; 
//     uint32_t i = 1;
//     uint32_t j = 4;

//     LOG(std::bitset<8>(include(N, M, i, j)).to_string())

// }