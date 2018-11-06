#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct tnode {		/* the tree node: */
	char *word;		/* points to the text */
	int count;		/* number of occurrences */
	struct tnode *left;	/* left child */
	struct tnode *right;	/* right child */
};

#define MAXWORD	100

struct tnode *addtree(struct tnode *root, const char *word);
void treeprint(struct tnode *root);
int getword(char *, int);

/* word frequency count */
int main()
{
	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, const char *w)
{
	int cond;

	if (p == NULL) {	/* new word is arrived */
		p = talloc();	/* make a new node */
		p->word = strdup(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;	/* repeated word */
	else if (cond < 0)	/* less than into left subtree */
		p->left = addtree(p->left, w);
	else			/* greater than into right subtree */
		p->right = addtree(p->right, w);
	return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}







/* getword: get next word or characters from input */
int getword(char *word, int lim)
{
        int c;
        char *w = word;

        while (isspace(c = getc(stdin)))
                ;
        if (c != EOF)
                *w++ = c;
        if (!isalpha(c)) {
                *w = '\0';
                return c;
        }
        for (; --lim > 0; w++)
                if (!isalnum(*w = getc(stdin))) {
                        ungetc(*w, stdin);
                        break;
                }
        *w = '\0';
        return word[0];
}

/* talloc: make a node */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}


