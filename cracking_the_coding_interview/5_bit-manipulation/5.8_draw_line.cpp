#include "../../ALL_H_FILES.h"

// =============================================================

// y = 1
// x1 = 3
// x2 = 7
// screen = [
//    [00000000 00000000 00000000 00000000],
//    [00000000 00000000 00000000 00000000],
//    [00000000 00000000 00000000 00000000],
//    [00000000 00000000 00000000 00000000]
// ]

// screen = [
//    [00000000 00000000 00000000 00000000],
//    [00011111 00000000 00000000 00000000],
//    [00000000 00000000 00000000 00000000],
//    [00000000 00000000 00000000 00000000]
// ]

uint8_t singleByteLine(uint8_t x1, uint8_t x2);

void drawLine(uint8_t* screen, uint32_t width, uint32_t height, uint32_t x1, uint32_t x2, uint32_t y)
{
    assert
    (
        (x1 > 0) &&
        (x1 < width) &&
        (x2 > 0) &&
        (x2 < width) &&
        (x2 >= x1) &&
        (y*width + x1 <= height) &&
        (y*width + x2 <= height)
    );

    uint32_t x1 = y * width / 8 + x1 / 8;
    uint32_t x2 = y * width / 8 + x2 / 8;
    if (x1 == x2)
    {
        screen[x1] = singleByteLine(x1 % 8, x2 % 8);
    }
    else
    {
        screen[x1] = singleByteLine(x1 % 8, 7);
        screen[x2] = singleByteLine(0, x2 % 8);
        for (int i = x1 + 1; i < x2; ++i)
        {
            screen[i] = 255;
        }        
    }
}

uint8_t singleByteLine(uint8_t x1, uint8_t x2) 
{
    assert
    (
        (x1 >= 0) && 
        (x1 < 8) && 
        (x2 >= 0) && 
        (x2 < 8) && 
        (x2 >= x1)
    );
    
    uint8_t numOnes = x2 - x1 + 1;
    uint8_t byte = (static_cast<uint8_t>(1) << numOnes) - 1;
    byte <<= static_cast<uint8_t>(8 - x2 - 1);
    return byte;
}


// =============================================================

// int main()
// {

// }