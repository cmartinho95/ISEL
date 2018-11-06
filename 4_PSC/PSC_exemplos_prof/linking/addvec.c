/**
 * Module that belongs to libraries libvector.a and libvector.so
 */

#include "vector.h"

int addcnt = 0;

void addvec(int *x, int *y, int *z, int n)
{
	int i;

	addcnt++;
	for (i = 0; i < n; i++)
		z[i] = x[i] + y[i];
}

