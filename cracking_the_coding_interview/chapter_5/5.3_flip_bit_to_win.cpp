#include "../../ALL_H_FILES.h"
#include "bitutils.cpp"

// =============================================================

template <typename T>
int flipBit(T bits)
{
    static_assert(std::is_unsigned<T>::value, "T must be unsigned integral type");

    int currentLength = 0;
    int previusLength = 0;
    int maxLength = 1;

    while (bits != 0)
    {
        if (bits & 1) // (bits & 1) == 1
        {
            ++currentLength;
        }
        else // (bits & 1) == 0
        {
            previusLength = currentLength;
            currentLength = 0;
        }
        maxLength = std::max(previusLength + currentLength + 1, maxLength);
        bits >>= 1;
    }
    return std::min(maxLength, std::numeric_limits<T>::digits);
}   

// =============================================================
int main()
{
    for (auto testValue : { 0b11011101111U,
                            0b110111001111U,
                            0b1100111001111U,
                            0U,
                            ~0U })
        std::cout << bits(testValue) << ": " << flipBit(testValue) << std::endl;
}