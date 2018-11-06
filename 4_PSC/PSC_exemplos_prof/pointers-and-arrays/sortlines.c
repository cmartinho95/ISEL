/**
 *
 * Linguagem C, Section 5.6
 * Pointer arrays: Pointers to Pointers
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES	5000			/* max #lines to eb stored */

static char *lineptr[MAXLINES];		/* pointers to text lines */

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void bsort(char *lineptr[], int left, int right);
void isort(char *lineptr[], int left, int right);
void _qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
	int nlines;
	
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		bsort(lineptr, 0, nlines - 1);
//		isort(lineptr, 0, nlines - 1);
//		_qsort(lineptr, 0, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("***error: input too big to sort\n");
		return 1;
	}
}

#define MAXLEN	1000	/* max length of any input line */

int _getline(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines = 0;
	char *p, line[MAXLEN];
	
	while ((len = _getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = (char *)malloc(len)) == NULL)
			return -1;
		else {
			line[len - 1] = '\0';	/* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	while (nlines-- > 0)
		printf("%s\n", *lineptr++);
}

void swap(char *v[], int i, int j);

/* bsort: sorts lines using the bubble sort algorithm */
void bsort(char *lineptr[], int left, int right)
{
	int i, j, swapped;

	do {
		swapped = 0;
		for (i = left; i < right - 1; i++)
			if (strcmp(lineptr[i], lineptr[i + 1]) > 0) {
				swap(lineptr, i, i + 1);
				swapped = 1;
			}
		right--;
	} while (swapped);	
}

/* isort: sorts lines using the insertion sort algorithm */
void isort(char *lineptr[],  int left, int right)
{
	int i, j;
	
	for (i = left + 1; i < right; i++)
		for (j = i; j > 0 && strcmp(lineptr[j - 1], lineptr[j]) > 0; j--)
			swap(lineptr, j - 1, j);
}

/* _qsort: sort v[left]...v[right] into increasing order */
void _qsort(char *v[], int left, int right)
{
	int i, last;
	
	if (left >= right)		/* do nothing if array contains fewer than two elems */
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	_qsort(v, left, last - 1);
	_qsort(v, last + 1, right);
}


/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *tmp = v[i];
	
	v[i] = v[j];
	v[j] = tmp;
}
