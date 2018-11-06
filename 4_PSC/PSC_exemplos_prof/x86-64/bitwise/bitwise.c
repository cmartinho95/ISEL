/***
 *
 * ISEL, LEIC, Computer Systems Programming (PSC)
 *
 * Implementation in Assembly x86-64 of some bitwise utility functions: C versions and test code
 *
 * Generate the executable with: gcc -o bitwise -g -Og bitwise.c _bitwise.s
 *
 * Carlos Martins, April 2017
 *
 ***/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/* prototype for C versions */
unsigned getbits_(unsigned x, int p, int n);
unsigned setbits_(unsigned x, int p, int n, unsigned y);
unsigned invert_(unsigned x, int p, int n);
unsigned rightrot_(unsigned x, int n);
unsigned rightrot2_(unsigned x, int n);

/* prototype for assembly versions */
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);
unsigned rightrot2(unsigned x, int n);

/**
 * C versions
 */

/* getbits: returns n bits of x from the position p */
unsigned getbits_(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* setbits: sets the n bits of x from position p with the n lower bits of y */
unsigned setbits_(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = ~((~(~0 << n)) << (p + 1 - n));
    return (mask & x) | ((y & ~(~0 << n)) << (p + 1 -n));
}

/* invert: invert n bits in x from position p */
unsigned invert_(unsigned x, int p, int n)
{
    unsigned mask = (~(~0 << n)) << (p + 1 - n);
    return x ^ mask;
}

/* rightrot:  returns x right rotated n bits */

#define UINT_BIT		((sizeof(unsigned) * CHAR_BIT))
#define HIGH_UINT_BIT	(1 << (UINT_BIT - 1))
 
unsigned rightrot_(unsigned x, int n)
{
	int i;
    for (i = 0; i < n; ++i) {
        if (x & 1)
            x = (x >> 1) | HIGH_UINT_BIT;
        else
            x >>= 1;
    }
    return x;
}

/* rightrot2:  returns x right rotated n bits */
unsigned rightrot2_(unsigned x, int n)
{
    unsigned y = x << (UINT_BIT - n);
    return (x >> n) | y;
}

/**
 * selected implementations
 */

#define __getbits	getbits		/* asm: getbits, C: getbits_ */
#define __setbits	setbits		/* asm: setbits, C: setbits_ */
#define __invert	invert		/* asm: invert, C: invert_ */
#define __rightrot	rightrot	/* asm: rightrot, C: rightrot_ */
#define __rightrot2	rightrot2	/* asm: rightrot2, C: rightrot2_ */

unsigned long movabsq();

int main()
{
	
	printf("getbits(0x12345678, 31, 16): %08x\n", __getbits(0x12345678, 31, 16));
	printf("setbits(0x12345678, 31, 16, 0xfedc): %08x\n", __setbits(0x12345678, 31, 16, 0xfedc));
    printf("invert(0x12ff5678, 23, 8): %08x\n", __invert(0x12ff5678, 23, 8));
    printf("rightrot(0x12345678, 16): %08x\n", __rightrot(0x12345678, 16));
    printf("rightrot2(0x12345678, 8): %08x\n", __rightrot2(0x12345678, 8));
    return 0;
}