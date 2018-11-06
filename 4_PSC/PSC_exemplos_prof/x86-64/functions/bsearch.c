#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* assembly version */
void *bsearch_(const void *key, const void *base, size_t nel, size_t width,
               int (*compar) (const void *, const void *));


/* bsearch: binary search:  */
void *bsearch__(const void *key, const void *base, size_t nel, size_t width,
               int (*compar) (const void *, const void *))
{
	size_t low = 0, high = nel - 1;
	while (low <= high) {
		size_t mid = (low + high) / 2;
		char *midp = (char *)base + mid * width;
		int cond;
		if ((cond = (*compar)(midp, key)) < 0)
			low = mid + 1;
		else if (cond > 0)
			high = mid - 1;
		else
			return midp;
	}
	return NULL;
}

/* the data */
			   
int data[] = {1, 2, 3, 4, 5, 6, 7, 10, 27};
int key = 6;

/* int_compare: compare referenced integers */
int int_compare(const void *first, const void *second)
{
	int f = *(int *)first, s = *(int *)second;
	return (f < s) ? -1 : ((f > s) ? 1 : 0);
}

/* used implementation */
#define __bsearch	bsearch_
				   
int main()
{
	void *p = __bsearch(&key, data, sizeof(data) / sizeof(*data), sizeof(int),
					  int_compare);
	if (p != NULL)
		printf("--%d: found\n", *(int *)p); 		
	else
		printf("**%d: not found!\n", key); 
	return 0;
}
