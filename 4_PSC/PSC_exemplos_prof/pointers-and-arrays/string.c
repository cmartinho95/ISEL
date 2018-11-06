#include <stdio.h>
#include <string.h>


char *_strcat(char *dst, const char *src)
{
	char *p = dst;
	while (*p != '\0')
		p++;
	while ((*p++ = *src++) != '\0')
		;
	return dst;
}

int _strend(const char *s, const char *t)
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

char *_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	char *p;
	for (p = dst, i = 0; i < len && (*p++ = *src++) != '\0'; i++)
		;
	if (i <= len)
		//memset(p, '\0', len - i);
		for (; i < len; i++)
			*p++ = '\0';
	return dst;
}

int main()
{
	char str[100] = "first string";
	
	//printf("%s\n", _strcat(str, "+second string"));
	//printf("%s\n", _strcat(str, ""));
	//str[0] = '\0';
	//printf("%s\n", _strcat(str, "+second string"));	
	//printf("%d\n", _strend("aaaaab", ""));
	_strncpy(str, "123456", 10);
	printf("%s\n", str);
	
	
	
	return 0;
}