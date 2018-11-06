#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* assembly version */
void bubble_sort(int items[], size_t length);

/* bubble_sort: sorts the integer array in ascending order */
void bubble_sort_(int items[], size_t length)
{
	size_t i;
	int swapped;
	
	do {
		swapped = 0;
		for (i = 0; i < length - 1; i++)
			if (items[i] > items[i + 1]) {
				int tmp = items[i];
				items[i] = items[i + 1];
				items[i + 1] = tmp;
				swapped = 1;
			}
		length -= 1;
	} while (swapped);
}

/* used versions */
#define __bubble_sort	bubble_sort

/*
 * Test program
 */


#define COUNT	1000

int data[COUNT];

//int data[] = {10, 10, 10, -5, +5, -5, 3, 2, 1};

void random_fill()
{
	int i;
	
	srand(clock());
	for (i = 0; i < COUNT; i++) {
		data[i] = rand();
		if ((rand() % 100) > 50)
			data[i] *= -1;
	}
}

int main()
{
	size_t i;
	
	random_fill();
	
	__bubble_sort(data, sizeof(data) / sizeof(*data));
	
	for (i = 0; i < sizeof(data) / sizeof(*data); i++)
		printf("%d\n", data[i]);
	printf("\n");
	
	return 0;
}
