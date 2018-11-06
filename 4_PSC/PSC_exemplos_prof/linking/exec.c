/**
 *  Display run-time addresses...
 *
 **/

#include<stdio.h>
#include<stdlib.h>

/* crt1.o _start function, same as program entry point */
extern void _start(void);

/* start of .data section of read/write data segment */
int data_start = 42;

/* start of .bss section of read/write data segment */
int bss_start;

int main()
{
	size_t i;
	int stack_var = 3;
	void *p = malloc(1);
	unsigned long cs_start = (unsigned long)_start & (~0UL << 21);
	unsigned long ds_start = (unsigned long)&data_start & (~0UL << 21);
	printf("code segment base: %lx; data segment base: %lx\n", cs_start, ds_start);
	
	/*
	for (i = 0; i < 8192; i++) {
		volatile unsigned char byte = ((unsigned char *)ds_start)[i];
	}
	*/
	printf("i: %zd\n", i);
	printf("program entry point: %p\n", _start);
	printf("main address: %p\n", main);
	printf("data segment, .data section: %p\n", &data_start);
	printf("data segment, .bss section: %p\n", &bss_start);
	printf("heap address: %p\n", p);
	printf("stack top when main executed: %p\n", &stack_var);
	return 0;
}