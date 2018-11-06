#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



/* assembly version */
void quick_sort(void *base, size_t nel, size_t width,
                int (*compar)(const void *, const void *));

/* memswap: swap the contents of two blocks of memory */
void memswap(void *one, void *other, size_t width) {
	char tmp[width];
	memcpy(tmp, one, width);
	memcpy(one, other, width);
	memcpy(other, tmp, width);
}

void quick_sort_(void *data, size_t nel, size_t width, int (*compar)(const void *, const void *))
{
 	char *limit, *last, *ptr;

    if (nel < 2)
        return;
	limit = (char *)data + (nel * width);
	memswap(data, (char *)data + (nel >> 1) * width, width);
	for (last = data, ptr = (char *)data + width; ptr < limit; ptr += width)	/* partition */
		if ((*compar)(ptr, data) < 0)
			memswap(ptr, last += width, width);
	memswap(data, last, width);
	quick_sort_(data, (last - (char *)data) / width, width, compar);
	quick_sort_(last + width, ((limit - last) / width) - 1, width, compar);
}

/*
 * Test program
 */


#define COUNT	100

int data[COUNT];

int int_cmp(const void *first, const void *second)
{
//	return *(int *)first - *(int *)second;		// overflows
	if (*(int *)first > *(int *)second)
		return 1;
	else if (*(int *)first < *(int *)second)
		return -1;
	else
		return 0;		
}

void fill_with_random_data()
{
	int i;
	
	srand(clock());
	for (i = 0; i < COUNT; i++) {
		data[i] = rand();
		if ((rand() % 100) > 50)
			data[i] *= -1;
	}
}

/* select implementation */
#define __quick_sort	quick_sort		/* assembly version */

int main()
{
	size_t i;
	
	fill_with_random_data();
	
	__quick_sort(data, sizeof(data) / sizeof(*data), sizeof(int), int_cmp);
	
	for (i = 0; i < sizeof(data) / sizeof(*data); i++)
		printf("%d\n", data[i]);
	printf("\n");
	
	return 0;
}

