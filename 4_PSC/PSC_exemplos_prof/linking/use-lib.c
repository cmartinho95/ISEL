/*
 * Test program that uses libvector.*
 */

#include <stdio.h>
#include "vector.h"

int main()
{
	int x[2] = {1, 2};
	int y[2] = {3, 4};
	int z[2];

	addvec(x, y, z, 2);
	printf("addvec({%d, %d}, {%d, %d}) = {%d, %d}\n", x[0], x[1], y[0], y[1], z[0], z[1]);
	multvec(x, y, z, 2);
	printf("multvec({%d, %d}, {%d, %d}) = {%d, %d}\n", x[0], x[1], y[0], y[1], z[0], z[1]);
	printf("addcnt: %d, multcnt: %d\n", addcnt, multcnt);
	return 0;
}


