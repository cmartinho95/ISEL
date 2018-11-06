#include <stdio.h>
#include <string.h>

#define MAXLINE	1000

int _getline(char *line, int limit);

/* find: print lines that math pattern from 1st argument */
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int found = 0;
	
	if (argc != 2) {
		printf("Usage: find pattern\n");
		return 0;
	}
	while (_getline(line, MAXLINE) > 0)
		if (strstr(line, argv[1]) != NULL) {
			printf("%s", line);
			found++;
		}
	return found;
}

/* _getline: get line into s, return length */
int _getline(char line[], int maxlen)
{
	int c, len;
	
	for (len = 0; len < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; len++)
		line[len] = c;
	if (c == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return len;
}
