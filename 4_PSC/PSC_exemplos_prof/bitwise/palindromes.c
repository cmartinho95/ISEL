#include <stdio.h>
#include <string.h>
#include <limits.h>

#define UINT_BITS	(CHAR_BIT * sizeof(unsigned int))
#define USHORT_BITS	(CHAR_BIT * sizeof(unsigned short))
#define HEX_MASK    (~(~0U << 4))

int is_bin_palindrome(unsigned short v)
{
	int i, j;
    
	for (i = 0, j = USHORT_BITS - 1; i < j; ++i, --j)
        if (((v & (1 << j)) >> (j - i)) ^ (v & (1 << i)))
            return 0;
	return 1;
}

int is_hex_palindrome(unsigned n)
{
    int i, j;
    
    for (i = 0, j = UINT_BITS/4 - 1; i < j; ++i, --j)
        if ((((HEX_MASK << (j * 4)) & n) >> ((j - i) * 4)) ^ ((HEX_MASK << (i * 4)) & n))
        return 0;
    return 1;
}


int main()
{
	printf("0x8001: %d\n", is_bin_palindrome((unsigned short)0x8001));
	printf("0xc813: %d\n", is_bin_palindrome((unsigned short)0xc813));
	printf("0x23455432: %d\n", is_hex_palindrome(0x23455432));

	return 0;
}
