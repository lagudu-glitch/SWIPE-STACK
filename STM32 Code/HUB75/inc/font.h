/*
 * font.h
 *
 * Vishnu Lagudu
 * vlagudu@purdue.edu
 *
 * Pixel maps for game fonts
 */

#include <stdint.h>

// colors
#define BLACK  0x0
#define RED    0x1
#define GREEN  0x2
#define YELLOW 0x3
#define BLUE   0x4
#define PINK   0x5
#define TEAL   0x6
#define WHITE  0x7


// Pixel maps
const uint8_t A [] =
{
    0b0010000,
    0b0101000,
    0b1000100,
    0b1111100,
    0b1000100,
    0b1000100,
    0b1000100
};

const uint8_t B [] =
{
    0b1111000,
    0b1000100,
    0b1000100,
    0b1111000,
    0b1000100,
    0b1000100,
    0b1111000
};

const uint8_t C [] =
{
    0b0111100,
    0b1000000,
    0b1000000,
    0b1000000,
    0b1000000,
    0b1000000,
    0b0111100
};

typedef struct _Font
{
	uint8_t        w;    // width
	uint8_t        h;    // height
	const uint8_t* pmap; // pixel map
} Font;

const Font fonts[] =
{
	{5, 7, A},
	{5, 7, B},
	{5, 7, C}
};