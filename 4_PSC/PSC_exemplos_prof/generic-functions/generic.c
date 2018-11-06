/***
 *
 * ISEL, LEIC, Computer Systems Programming (PSC)
 *
 * Usage of generic-functions available in C runtime library
 *
 * Generate the executable with: gcc -o generic -g generic.c
 *
 * Carlos Martins, May 2017
 *
 ***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/* Returns the number of elements of the specified array */
#define ELEMS(array)	(sizeof(array) / sizeof(*(array)))

/**
 * Data is an integer array
 */

#define COUNT	50
int int_array[COUNT];

/* random_fill_int_array: fill int_data array with random integers */
static void random_fill_int_array()
{
	size_t i;
	
	/* initialize random seed with an always different random value */
	srand(clock());
	for (i = 0; i < COUNT; i++) {
		int_array[i] = rand();
		/* transform 50% of the integers into negative numbers */ 
		if (rand() % 100 >= 50)
			int_array[i] *= -1;
 	}
}

/* print_int_data: print the array of integers */
static void print_int_array()
{
	size_t i;
	
	for (i = 0; i < COUNT; i++)
		printf("%d\n", int_array[i]);
}

/* int_compare: compare the two integers pointed by first and second */
static int int_compare(const void *first, const void *second)
{
	int f = *(int *)first, s = *(int *)second;

	/* we can not simply subtract the integers because overflow can occur! */
	return (f < s) ? -1 : ((f > s) ? 1 : 0);
}

/**
 * Data is pointer to integer array
 */

int *int_ptr_array[COUNT];

/* random_fill_int_array: fill int_data array with random integers */
static void random_fill_int_ptr_array()
{
	size_t i;
	
	/* initialize random seed with an always different random value */
	srand(clock());
	for (i = 0; i < COUNT; i++) {
		int_array[i] = rand();
		/* transform 50% of the integers into negative numbers */ 
		if (rand() % 100 >= 50)
			int_array[i] *= -1;
		int_ptr_array[i] = &int_array[i];
 	}
}

/* print_int_data: print the array of integers */
static void print_int_ptr_array()
{
	size_t i;
	
	for (i = 0; i < COUNT; i++)
		printf("%d\n", *int_ptr_array[i]);
}

/* int_compare: compare the two integers pointed by first and second */
static int int_ptr_compare(const void *firstp, const void *secondp)
{
	int f = **(int **)firstp, s = **(int **)secondp;

	/* we can not simply subtract the integers because overflow can occur! */
	return (f < s) ? -1 : ((f > s) ? 1 : 0);
}

/**
 * Ordering integer array
 */

/* order_int_array: order integer data using quicksort */
static void order_int_array()
{
	random_fill_int_array();
	/* sort integer array using qsort (quick sort) generic function */
	qsort(int_array, ELEMS(int_array), sizeof(int), int_compare);
	print_int_array();
}


/**
 * Ordering pointer to integer array
 */

/* order_int_array: order integer data using quicksort */
static void order_int_ptr_array()
{
	random_fill_int_ptr_array();
	/* sort integer array using qsort (quick sort) generic function */
	qsort(int_ptr_array, ELEMS(int_ptr_array), sizeof(int *), int_ptr_compare);
	print_int_ptr_array();
}

/**
 * search in an integer array using binary search
 */

static void search_int_array()
{
	size_t index;
	int search_value;
	void *search_ptr;
	
	/* fill int array with random data and sort it using qsort */
	random_fill_int_array();
	qsort(int_array, ELEMS(int_array), sizeof(int), int_compare);

	/* select a random item of the array to search */
	index = rand() % COUNT;
	search_value = int_array[index];

	/* using generic function bsearch (binary search) to search the selected item */
	search_ptr = bsearch(&search_value, int_array, ELEMS(int_array), sizeof(int), int_compare);

	/* this assertion must be true */
	assert(search_ptr == &int_array[index]);
	
	printf("target value: %d held at position %zd was found by bsearch at position %zd\n",
			search_value, index, (int *)search_ptr - int_array);
}

/**
 * search in an pointer to integer array using binary search
 */

static void search_int_ptr_array()
{
	size_t index;
	int *search_value_ptr;
	void *search_ptr;
	
	/* fill int array with random data and sort it using qsort */
	random_fill_int_ptr_array();
	qsort(int_ptr_array, ELEMS(int_ptr_array), sizeof(int *), int_ptr_compare);
	
	/* select a random item of the array to search */
	index = rand() % COUNT;
	search_value_ptr = int_ptr_array[index];

	/* using generic function bsearch (binary search) to search the selected item */
	search_ptr = bsearch(&search_value_ptr, int_ptr_array, ELEMS(int_ptr_array), sizeof(int *), int_ptr_compare);

	/* this assertion must be true */
	assert(search_ptr == &int_ptr_array[index]);
	
	printf("target value: %d held at position %zd was found by bsearch at position %zd\n",
			*search_value_ptr, index, (int **)search_ptr - int_ptr_array);
}

/**
 * structure array order
 */

typedef struct student {
	int number;
	const char *name;
} Student;

Student student_items[] = {
	{ 38779, "Rafael Loureiro Nunes" },
	{ 38866, "Manuel Filipe Marques de Almeida Dias" },
	{ 39091, "Eduardo Miranda Martins" },	
	{ 39129, "Filipa Pereira Fernandes" },
	{ 41885, "Luís Filipe Ferreira da Silva" },
	{ 42121, "Hugo Pires Pina Fora" },
	{ 42125, "Marco Daniel Rodrigues Batista" },
	{ 42128, "Miguel Francisco Oliveira Nunes" },
	{ 42132, "Hugo Alexandre Resende da Rocha" },
	{ 42142, "Ana Rita Ferreira dos Santos" },
	{ 42153, "Francisco Ribeiro Farinha" },
	{ 42155, "Sergiu Cozma" },
	{ 42392, "DIOGO RODRIGUES LOUREIRO" },
	{ 42393, "DIOGO ANDRÉ MARINHO MARTINS" },
	{ 42396, "BRUNO CÉSAR ANICETO CARDOSO" },
	{ 42400, "BRUNO MIGUEL LEANDRO LOURENÇO" },
	{ 42932, "Leonardo Duarte Rodrigues Alexandre" },
	{ 26093, "Nuno Jorge Gouveia Patrício Miguel" },
	{ 31743, "Ricardo Nuno Fonseca Cacheira" },
	{ 36936, "Daniel Doe Silva" },
	{ 37540, "Cláudio Alexandre Coelho Faustino" },
	{ 37685, "André Salgado Casadinho" },
	{ 37831, "André Batoreu Policarpo" },
	{ 37832, "André Mauro da Silva Filipe" },
	{ 39396, "Helena Sofia Barai Formoso Gomes" },
	{ 40539, "Rui Miguel Marques Garcia" },
	{ 40605, "Tejal Yogesh Amratlal" },
	{ 40626, "Inês Ferreira Simões" },
	{ 40688, "Ruben Filipe Da Silva Miranda" },
	{ 41381, "Francisco Malaquias Falcato Alves" },
	{ 41412, "Valter Hugo de Sousa e Andrade Esteves" },
	{ 41457, "Pedro José Correia Raminhos" },
	{ 41465, "Gonçalo Jorge Bettencourt Caldeira" },
	{ 41470, "António Luís Pereira Amorim" },
	{ 41471, "Pedro Alexandre Sousa de Almeida" },
	{ 41504, "Diogo Gonçalves Bicho" },
	{ 41531, "Francisco Miguel Gusmão Coelho Loureiro" },
	{ 41557, "Tiago Daniel Fernandes Ribeiro" },
	{ 42161, "Miguel Ângelo Rocha Moreira Arroja" },
	{ 42162, "Inês Lima Amil Soares" },
	{ 42171, "Tiago Mourão Lopes" },
	{ 42174, "Beatriz Plácido Ferreira" },
	{ 42177, "Nuno Filipe Gabriel de Sousa" },
	{ 42183, "Renato Filipe Cunha Carvalho" },
	{ 42184, "Diogo Simões Lã Branca" },
	{ 42185, "Carlos Mauricio Castaneda Moreno" },
	{ 42189, "Luana Bernardino da Silva" },
	{ 42200, "Rui Diogo Tomaz Lima" },
};

static int student_compare_name(const void *first, const void *second)
{
	Student *f = (Student *)first, *s = (Student *)second;
	return strcmp(f->name, s->name);
}

static int student_compare_number(const void *first, const void *second)
{
	Student *f = (Student *)first, *s = (Student *)second;
	return (f->number < s->number) ? -1 : ((f->number > s->number) ? 1 : 0);
}

static void print_students()
{
	int i;
	for (i = 0; i < ELEMS(student_items); i++)
		printf("number: %d, name: %s\n", student_items[i].number, student_items[i].name);

}

static void order_student_by_name()
{
	qsort(student_items, ELEMS(student_items), sizeof(Student), student_compare_name);
	print_students();
}

static void order_student_by_number()
{
	qsort(student_items, ELEMS(student_items), sizeof(Student), student_compare_number);
	print_students();
}

/**
 * test code
 */

int main()
{	
//	order_int_array();
//	order_int_ptr_array();
//	search_int_array();
//	search_int_ptr_array();
//	order_student_by_name();
	order_student_by_number();
	return 0;
}