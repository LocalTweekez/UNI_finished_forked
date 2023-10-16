/*Program Example 8.11: Bitmap header file flower.h
*/
#ifndef treedude_H
#define treedude_H
#include "C12832.h"

static char treedude[] = {
    0x00, 0x03, 0xE0, 0x00, // ____ ____X____ ____
    0x00, 0x07, 0xF0, 0x00, // ____ ___XXX___ ____
    0x00, 0x06, 0x30, 0x00, // ____ __XXXXX__ ____
    0x03, 0xC4, 0x18, 0x00, // ____ _XX*_*XX_ ____ 
    0x07, 0xF4, 0x0D, 0xE0, // ____ X__X X__X ____ 
    0x0E, 0x1C, 0x0F, 0xF8, // ___X ___X X___ X___ 
    0x0C, 0x0C, 0x0E, 0x1C, // ____ _X__ __X_ ____
    0x0C, 0x00, 0x00, 0x0C, // ____ _X__ __X_ ____
    0x0C, 0x01, 0xE0, 0x0C, // ____ _X__ __X_ ____
};

Bitmap bitmTreedude = {
10, // XSize
10, // YSize
2, // Bytes in each line
treedude, // Pointer to picture data
};
#endif
