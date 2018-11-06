#include <stdio.h>
#include <ctype.h>
#include <string.h>


int getword(FILE *instream, char *word, size_t limit);

#define MAXWORD	5

int main()
{
	char word[MAXWORD];
	int i, r;
	
	memset(word, 'a', MAXWORD);
	r = getword(stdin, word, MAXWORD);
	printf("word: %s\n", word);
	for (i = 0; i < MAXWORD + 1; i++)
		printf("[%d]: %d\n", i, word[i]);
	return 0;
}


/* getword: get next word or characters from the specified stream */
int getword(FILE *instream, char *word, size_t limit)
{
	int c;
	char *w = word;

	while (isspace(c = getc(instream)))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --limit > 1; w++)
		if (!isalnum(*w = getc(instream))) {
			ungetc(*w, instream);
			break;
		}
	*w = '\0';
	return word[0];		/* return first character of the word */
}
