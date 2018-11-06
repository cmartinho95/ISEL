/***
 *
 * ISEL, LEIC, Computer Systems Programming (PSC)
 *
 * Implementation in Assembly x86-64 of some string utility functions: C versions and test code
 *
 * Generate the executable with: gcc -o string -g -Og string.c _string.s
 *
 * Carlos Martins, April 2017
 *
 ***/

#include <stdio.h>
#include <string.h>

/* prototype for C versions */
int _strncmp_(const char s1[], const char s2[], size_t n);
int _strncmp2_(const char *s1, const char *s2, size_t n);
char *_strcat_(char dst[], const char src[]);
char *_strcat2_(char *dst, const char *src);
char *_strncpy_(char *dst, const char *src, size_t len);
char *_strstr_(const char *big, const char *little);
char *_strrstr_(const char *big, const char *little);
int _strend_(const char *s, const char *t);
int _strend2_(const char *s, const char *t);

/* prototype for assembly versions */
int _strncmp(const char *s1, const char *s2, size_t n);
int _strncmp2(const char *s1, const char *s2, size_t n);
char *_strcat(char dst[], const char src[]);
char *_strcat2(char *dst, const char *src);
char *_strncpy(char *dst, const char *src, size_t len);
char *_strstr(const char *big, const char *little);
char *_strrstr(const char *big, const char *little);
int _strend(const char *s, const char *t);
int _strend2(const char *s, const char *t);

/**
 * C versions
 */

/* _strncmp: compare strings (array version) */ 
int _strncmp_(const char s1[], const char s2[], size_t n)
{
	size_t i;
	
	for (i = 0; i < n && s1[i] == s2[i]; i++)
		if (s1[i] == '\0')
			return 0;
	return s1[i] - s2[i];
}

/* _strncmp: compare strings (pointer version) */ 
int _strncmp2_(const char *s1, const char *s2, size_t n)
{
	for (; n > 0 && *s1 == *s2; s1++, s2++, n--)
		if (*s1 == '\0')
			return 0;
	return *s1 - *s2;
}

/* _strcat: concatenate strings (array version)*/ 
char *_strcat_(char dst[], const char src[])
{
	size_t i, j;

	for (i = 0; dst[i] != '\0'; i++)
		;
	for (j = 0; (dst[i] = src[j]) != '\0'; i++, j++)
		;
	return dst;
}

/* _strcat2: concatenate strings (pointer version)*/ 
char *_strcat2_(char *dst, const char *src)
{
	char *ret = dst;
	while (*dst != '\0')
		dst++;
	while ((*dst++ = *src++) != '\0')
		;
	return ret;
}

/* _strncpy: copy strings */
char *_strncpy_(char *dst, const char *src, size_t len)
{
	size_t n;
	char *p;
	for (p = dst, n = 0; n < len && (*p++ = *src++) != '\0'; n++)
		;
	for (; n < len; n++)
		*p++ = '\0';
	return dst;
}

/* _strstr: locate the first occurrence of a substring in a string */ 
char *_strstr_(const char *big, const char *little)
{
	size_t i;
	for (; *big != '\0'; ++big) {
		if (*big == *little) {
			for (i = 1; little[i] != '\0' && big[i] == little[i]; i++)
				;
			if (little[i] == '\0')
				return (char *)big;
		}
	}
	return NULL;
}

/* _strrstr: locate the last occurrence of a substring in a string */ 
char *_strrstr_(const char *big, const char *little)
{
	size_t i;
	char *last = NULL;
	for (; *big != '\0'; ++big) {
		if (*big == *little) {
			for (i = 1; little[i] != '\0' && big[i] == little[i]; i++)
				;
			if (little[i] == '\0') {
				last = (char *)big;
				big += i;
			}
		}
	}
	return last;
}

/* _strend: check if a string ends with another string */
int _strend_(const char *s, const char *t)
{
	size_t slen = strlen(s);
	size_t tlen = strlen(t);
	if (tlen > slen)
		return 0;
	const char *p;
	for (p = s + slen - tlen; *t != '\0' && *t == *p; p++, t++)
		;
	return *t == '\0';
}

/* _strend2: check if a string ends with another string */
int _strend2_(const char *s, const char *t)
{
	char *p = _strrstr_(s, t);
	return p == NULL ? 0 : strcmp(p, t) == 0;
}

/**
 * selected implementations
 */
#define __strncmp	_strncmp	/* asm: _strncmp, C: _strncmp_ */
#define __strncmp2	_strncmp2	/* asm: _strncmp2, C: _strncmp2_ */
#define __strcat	_strcat		/* asm: _strcat, C: _strcat_ */
#define __strcat2	_strcat2	/* asm: _strcat2, C: _strcat2_ */
#define __strncpy	_strncpy	/* asm: _strncpy, C: __strncpy_ */
#define __strstr	_strstr		/* asm: _strstr, C: _strstr_ */
#define __strrstr	_strrstr	/* asm: _strrstr, C: _strrstr_ */
#define __strend	_strend		/* asm: _strend, C: _strend_ */
#define __strend2	_strend2	/* asm: _strend2, C: _strend2 */

int main()
{
	char str[100];
	char *p;
	
	/* test _strncmp */
	printf("\"aaa\" : \"bbb\" = %d\n", __strncmp("aaa", "bbb", 3));
	printf("\"bbb\" : \"aaa\" = %d\n", __strncmp("bbb", "aaa", 3));
	printf("\"aaa\" : \"aaa\" = %d\n", __strncmp("aaa", "aaa", 3));

	printf("\n\"aaa\" : \"bbb\" = %d\n", __strncmp2("aaa", "bbb", 3));
	printf("\"bbb\" : \"aaa\" = %d\n", __strncmp2("bbb", "aaa", 3));
	printf("\"aaa\" : \"aaa\" = %d\n", __strncmp2("aaa", "aaa", 3));
	
	/* test _strcat */
	strcpy(str, "first string");
	printf("\n%s\n", __strcat(str, " + second string"));
	printf("%s\n", __strcat(str, " + third string"));

	strcpy(str, "first string");	
	printf("\n%s\n", __strcat2(str, " + second string"));
	printf("%s\n", __strcat2(str, " + third string"));

	/* test _strncpy */
	memset(str, 0, sizeof(str));
	__strncpy(str, "123456", 10);
	printf("\n%s\n", str);
	memset(str, 0, sizeof(str));
	__strncpy(str, "123456", 2);
	printf("%s\n", str);
	
	/* test _strstr */
	p = __strstr("aabcda--aefgha--a", "a--a");	
	printf("\n%s\n", p ? p : "not found");

	/* test _strrstr */
	p = __strrstr("aabcda--aefgha--a", "a--a");	
	printf("\n%s\n", p ? p : "not found");

	/* test _strend */
	printf("\n%d\n", __strend("aaaaaa", "aa"));
	printf("%d\n", __strend("aaaaaa", "ab"));
		
	/* test _strend2 */
	printf("\n%d\n", __strend2("aaaaab", "aa"));
	printf("%d\n", __strend2("aaaaab", "ab"));
	return 0;
}
