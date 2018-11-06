#include <stdio.h>
#include <stdlib.h>

/* the entry point symbol */
void _start();

int data = 0x12345678;
int data2 = 0x9abcdef0;
int bss[4];
int bss2[1];


int main()
{
	const char *rostr = "hello";
	unsigned char *codep;
	size_t i;
	void *heap;
	
	printf("program entry point: %p\n", _start);

	printf(".text address(main):  %p\n", &main);
	
	printf("some binary bytes at &main: ");
	for (codep = (unsigned char *)&main, i = 0; i < 16; codep++, i++) 
		printf("%02x ", *codep);
	putchar('\n');

	printf(".rodata address: %p\n", (void *)rostr);	
	printf(".data address:  %p\n", (void *)&data);
	printf("next .data address: %p\n", (void *)&data2);
	printf(".bss address:   %p\n", (void *)&bss);
	printf("next .bss address:  %p\n", (void *)&bss2);
	heap = malloc(1);
	printf("heap address: %p\n", heap);
	free(heap);
	printf("stack address: %p\n", &heap);

	return 0;
}