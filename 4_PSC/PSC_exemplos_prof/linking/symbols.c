/**
 *
 *  ISEL, LEIC, Computer Systems Programming (PSC)
 *
 *  Demonstrates declaration of all the types of linker symbols
 *
 *  To generate the relocatable object file, execute: gcc -c -o symbols.o symbols.c
 *  To observer the linker symbols, execute: nm symbols.o
 *    or: readelf -s symbols.o
 *    or: objdump -t symbols.o
 *
 *  To generate an executable, execute: gcc -o symbols symbols.c symbols_extern.c
 *
 *  To observe the symbols defined in the generated executable, execute: nm symbols
 *    or: readelf -s symbols
 *    or: objdump -t symbols
 *
 *  Carlos Martins, May 2017
 *
 **/

#include <stdio.h>

/* defines */
#define BUF_SIZE	32

/* functions */
void non_called(void);
void called(void);

/* external variables */
extern int non_referenced_extern;
extern int referenced_extern;

/* global variables */
int global_common[BUF_SIZE];
int global_bss = 0;
int *global_data = &referenced_extern;

/* local variables */
static int local_bss;
static int local_bss_2 = 0;
static int local_data = 1;

/* local function */
static void local_function() {}

/* global function */
int main()
{
	/* if compiled without -fno-stack-protector calls the __stack_chk_fail function */
	/* function external */
	extern void same_as_non_called();
	extern void same_as_called();
	extern int same_as_non_referenced_extern;
	extern int same_as_referenced_extern;
	
	/* function locals */
	int func_local;
	int *func_local_2 = global_common;
	
	/* static function locals */
	static int static_func_local_bss;			/* symbol name: static_func_local_bss.2306 */ 
	static int static_func_local_bss_2 = 0;		/* symbol name: static_func_local_bss_2.2305 */
	static int static_func_local_data = 1;		/* symbol name: static_func_local_data.2305 */
	
	/* addresses of normal local variables */
	printf("&func_local: %p, &func_local_2: %p\n", &func_local, &func_local_2);

	/* addresses of static local variables */
	
	printf("&func_static_local_bss: %p, &func_static_local_bss_2: %p, &func_static_local_data: %p\n",
		 	&static_func_local_bss, &static_func_local_bss_2, &static_func_local_data);
	
	local_function();
	called();
	same_as_called();
	referenced_extern = 1;
	same_as_referenced_extern = 2;
	
	return 0;
}