#include <stdio.h>
#include <limits.h>

#define	INT_BIT			(sizeof(int) * CHAR_BIT)
#define UINT_BIT		(sizeof(unsigned int) * CHAR_BIT)
#define	HIGH_INT_BIT	(1 << (INT_BIT - 1))
#define	LOW_BIT			(1 << 0)

/* getbits: get n bits from position p */
unsigned getbits(unsigned int x, int p, int n)
{
	return (x >> (p - n + 1)) & ~(~0 << n);
}

/* getbits: get n bits from position p */
unsigned getbits2(unsigned int x, int p, int n)
{
	return (x << (32 - p - 1)) >> (UINT_BIT - n);
}

/* setbits: returns x with the n bits that begin at position p
   set to the rightmost n bits of y, leaving the other bits unchanged */

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	return (x & ~(~(~0 << n) << (p - n + 1))) | ((~(~0 << n) & y) << (p - n + 1));
}

/* invert: returns x with the n bits that begin at position p inverted,
   leaving the others unchanged. */

unsigned invert(unsigned x, int p, int n)
{
	return x ^  (~(~0 << n) << (p - n + 1));
}

/* rightrot: returns the value of the integer x rotated to the right by n positions. */

unsigned rightrot(unsigned x, int n)
{
	unsigned r;

	for (r = x; n > 0; x >>= 1, --n) {
		r >>= 1;
		if (x & 1)
			r |= HIGH_INT_BIT;
	}
	return r;
}

unsigned rightrot2(unsigned int x, int n)
{
	return (x >> n) | (x << (UINT_BIT - n));
}

/* reverse: return x with bits reversed, i.e., lower bit on higher bit, etc. */

unsigned reverse(unsigned x)
{
	unsigned r, low_mask = LOW_BIT, high_mask = HIGH_INT_BIT;
	int i;
	
	for (r = 0, i = 0; i < INT_BIT / 2; low_mask <<= 1, high_mask >>= 1, i++) {
		if (x & low_mask)
			r |= high_mask;
		if (x & high_mask)
			r |= low_mask;
	}
	return r;
}

unsigned reverse2(unsigned x)
{
	unsigned r;
	int i;
	
	for (r = 0, i = 0; i < INT_BIT / 2; i++) {
		if (x & (1 << i))
			r |= 1 << (INT_BIT - i - 1);
		if (x & (1 << (INT_BIT - i - 1)))
			r |= 1 << i;
	}
	return r;
}

int main()
{
	double d = 5;
	int i = 5.0;
	
	printf("getbits(0xff000000, 27, 4): 0x%08x\n", getbits(0xff000000, 27, 4));
	printf("getbits2(0xff000000, 27, 4): 0x%08x\n", getbits2(0xff000000, 27, 4));
	printf("setbits(0x33333333, 31, 8, 0xff): 0x%08x\n", setbits(0x33333333, 31, 8, 0xff));
	printf("invert(0xaa333333, 31, 8): 0x%08x\n", invert(0xaa333333, 31, 8));
	printf("rightrot(0x55000000, 8): 0x%08x\n", rightrot2(0x55000000, 8));
	printf("reverse(0xaa0000aa): 0x%08x\n", reverse(0xaa0000aa));
	printf("reverse2(0xaa0000aa): 0x%08x\n", reverse2(0xaa0000aa));
	

	return 0;
}