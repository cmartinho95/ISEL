#include <stdio.h>

void swap(int *, int *);

int main()
{
    int a = 20;
    int b = 11;
    int *p;
    p = &a;
    *p = 10;
    printf("a: %i, b: %i \n", a, b);
    swap(&a,&b);
    printf("a: %i, b: %i \n", a, b);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
