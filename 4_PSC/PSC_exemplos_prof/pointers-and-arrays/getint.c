#include <stdio.h>
#include <ctype.h>

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getc(stdin)))	/* skip white space */
		;
	/* check if it is a number and consider signal, if exits */
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetc(c, stdin);	/* it is not a number, put read char back */ 
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		if (!isdigit(c = getc(stdin))) {
			ungetc(c, stdin);	/* it is not a number, put read char back */
			return 0;
		}
	for (*pn = 0; isdigit(c); c = getc(stdin))
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetc(c, stdin);
	return c;
}

int main()
{
	int n, i, ints[20];
		
	for (n = 0; n < 20 && getint(&ints[n]) > 0; n++)
		;
	for (i = 0; i < n; i++)
		printf("ints[%d]: %4d\n", i, ints[i]);
	
	return 0;
}