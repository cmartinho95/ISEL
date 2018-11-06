#include <stdio.h>

/* Test cases */
# define 	CASE1	0xAA018055	/* Expected TRUE */
# define 	CASE2	0xAA011055	/* Expected FALSE */
# define 	CASE3	0xCC0A5033	/* Expected TRUE */

/* Function prototype */
int is_binary_palindrome(unsigned int bits);

/* Run tests */
int main()
{
	printf("0x%x: %s\n", CASE1, is_binary_palindrome(CASE1) ? "TRUE" : "FALSE");
	printf("0x%x: %s\n", CASE2, is_binary_palindrome(CASE2) ? "TRUE" : "FALSE");
	printf("0x%x: %s\n", CASE3, is_binary_palindrome(CASE3) ? "TRUE" : "FALSE");
}


/* is_binary_palindrome: checks if argument is a binary palindrome */
#include <limits.h>
int is_binary_palindrome(unsigned int bits)
{
	size_t h, l;

	for (l = 0, h = CHAR_BIT * sizeof(unsigned int) - 1;  h > l; l++, h--)
		if (((bits & (1 << h)) != 0) != ((bits & (1 << l)) != 0))
			return 0;
	return 1;
}
