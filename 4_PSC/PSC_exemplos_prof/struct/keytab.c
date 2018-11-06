#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* evaluates to the number of elements of the  "array" */
#define NELEMS(array)	(sizeof(array) / sizeof((*array)))

/* structure used to hold each keyword */
struct key {
	char *word;
	int count;
};

/* the keyword table */
struct key keytab[] = {
	{ "auto", 0 },
	{ "break", 0 },
	{ "case", 0 },
	{ "char", 0 },
	{ "const", 0 },
	{ "continue", 0 },
	{ "default", 0 },
	{ "do", 0 },
	{ "double", 0 },
	{ "else", 0 },
	{ "enum", 0 },
	{ "extern", 0 },
	{ "float", 0 },
	{ "for", 0 },
	{ "goto", 0 },
	{ "if", 0 },
	{ "int", 0 },
	{ "long", 0 },
	{ "register", 0 },
	{ "return", 0 },
	{ "short", 0 },
	{ "signed", 0 },
	{ "sizeof", 0 },
	{ "static", 0 },
	{ "struct", 0 },
	{ "switch", 0 },
	{ "typedef", 0 },
	{ "union", 0 },
	{ "unsigned", 0 },
	{ "void", 0 },
	{ "volatile", 0 },
	{ "while", 0 }
};

/* the number of keywords in keytab  */
#define NKEYS			(NELEMS(keytab))

/* auxiliary functions */
int getword(FILE *, char *, size_t limit);
int binsearch(char *, struct key *, size_t nelems);				/* using array subscription */ 
struct key *binsearch2(char *, struct key *, size_t nelems);	/* using pointers */

/* maximum word size */
#define MAXWORD	100

/* count C keywords - version with arrays */
int main(int argc, char *argv[])
{
	char word[MAXWORD];
	FILE *instream;
	const char *fname;
	int i;

    fname = argc > 1 ? argv[1] : "./keytab.c";

    if ((instream = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "**error: can't open file \"%s\"\n", fname);
        return -1;
    }
	while (getword(instream, word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((i = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[i].count++;

	for (i = 0; i < NKEYS; i++)
		if (keytab[i].count > 0)
			printf("%4d %s\n", keytab[i].count, keytab[i].word);
	return 0;
}

/* count C keywords : pointer version */
int _main(int argc, char *argv[])
{
    struct key *p;
	char word[MAXWORD];
    FILE *instream;
    const char *fname;

    fname = (argc > 1) ? argv[1] : "./keytab.c";

    if ((instream = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "**error: can't open file \"%s\"\n", fname);
        return -1;
    }

	while (getword(instream, word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			if ((p = binsearch2(word, keytab, NKEYS)) != NULL)
				p->count++;
	for (p = keytab; p < keytab + NKEYS; p++)
		if (p->count >= 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
}

/* binsearch : find word in tab[0] ... tab[n - 1] */
int binsearch(char *word, struct key tab[], size_t nelems)
{
	int low = 0, high = nelems - 1;

	while (low <= high) {
		int cond, mid = (low + high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

/* binsearch : find word in tab[0] ... tab[n - 1] */
struct key *binsearch2(char *word, struct key *tab, size_t nelems)
{
	struct key *low = &tab[0], *high = &tab[nelems];

	while (low < high) {
		struct key *mid = low + (high - low) / 2;
		int cond;
		if ((cond = strcmp(word, mid->word)) < 0)
			high = mid;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return NULL;
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

