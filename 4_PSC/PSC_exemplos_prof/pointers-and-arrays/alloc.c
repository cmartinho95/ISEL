/**
 *
 * Linguagem C, Section 5.4
 * Address Arithmetic
 *
 **/
 
#include <stdio.h>

#define ALLOC_SIZE	(10 * 1024)		/* size of the allocated space */

/* global variables */
static char allocbuf[ALLOC_SIZE];	/* storage for alloc */
static char *allocp = allocbuf;		/* next free position */

char *alloc(size_t n) {		/* return a pointer to n free bytes */
	if (allocbuf + ALLOC_SIZE - allocp >= n) {	/* it fits */
		allocp += n;
		return allocp - n;		/* old allocp */
	} else
		return NULL;	/* NULL is define as a pointer with a value 0 */
}

void afree(char *p) {		/* free storage pointed by p */
	if (p >= allocbuf && p < allocbuf + ALLOC_SIZE)
		allocp = p;
}


/* test allocator */
#define BLOCK_SIZE		1024
#define BLOCK_COUNT		20

int main()
{
	char *ptrs[BLOCK_COUNT], *p;
	int allocs, i;
	
	/* allocate memory blocks */
	for (allocs = 0; allocs < BLOCK_COUNT && (ptrs[allocs] = alloc(BLOCK_SIZE)) != NULL; allocs++)
		printf("--allocated memory block %d at address %p\n", allocs, ptrs[allocs]);
	
	/* free the allocated block from last to first */
	printf("--free all allocated memory blocks\n");
	for (i = allocs - 1; i >= 0; i--)
		afree(ptrs[i]);
	
	/* allocate all memory at once */
	p = alloc(allocs * BLOCK_SIZE);
	printf("--all memory allocated: %p\n", p);
	return 0;
}
