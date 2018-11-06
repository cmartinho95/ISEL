/**
 *
 *  Resolution of question 7 of the final test of 1617v_2
 *
 * Carlos Martins, May 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct node {
	struct node *next;
	struct node *prev;
	void *data;
} Node;

typedef struct queue {
	size_t count;
	Node *first;
	Node *last;
} Queue;

Queue *array_to_queue(void *array[], size_t nelems)
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	size_t i;
	
	assert(queue != NULL);
	
	queue->count = 0;
	queue->first = queue->last = NULL;	
	for (i = 0; i < nelems; i++) {
		Node *node = (Node *)malloc(sizeof(Node));
		
		assert(node != NULL);

		node->data = array[i];
		node->next = NULL;
		if (queue->count == 0) {
			node->prev = NULL;
			queue->first = queue->last = node;
		} else {
			node->prev = queue->last;
			queue->last->next = node;
			queue->last = node;
		}
		queue->count += 1;
	}
	free(array);
	return queue;
}

void **queue_to_array(Queue *queue, size_t *pnelems)
{
	void **array;
	Node *ptr;
	
	*pnelems = 0;
	if (queue->count == 0)
		return NULL;
	array = (void **)malloc(queue->count * sizeof(void *));

	assert(array != NULL);
	
	for (ptr = queue->first; ptr != NULL; *pnelems += 1) {
		Node *next = ptr->next;
		array[*pnelems] = ptr->data;
		free(ptr);
		ptr = next;
	}
	free(queue);
	return array;
}

void print_queue(Queue *queue)
{
	Node *p;
	
	printf("--queue = {\n\tcount: %zd\n", queue->count);	
	for (p = queue->first; p != NULL;) {
		printf("\tnode[%p]: \"%s\"", p, (char *)p->data);
		if ((p = p->next) != NULL)
			putchar(',');
		putchar('\n');
	}
	printf("}\n");
}


void print_parray(void *parray[], size_t nelems)
{
	size_t i;
	printf("parray = [\n");
	for (i = 0; i < nelems; i++) {
		printf("\t\"%s\"", (char *)parray[i]);
		if (i < nelems - 1)
			putchar(',');
		putchar('\n');
	}
	printf("]\n");
}

/* the data */
void *test_data[] = {
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten"	
};

#define NELEMS(array)		(sizeof(array) / sizeof(*(array)))

void test_7()
{
	Queue *queue;
	void **parray;
	size_t i, size = NELEMS(test_data);
	
	parray = (void **)malloc(sizeof(void *) * size);
	printf("data = [\n");
	for (int i = 0; i < size; i++) {
		printf("\t\"%s\"", (char *)test_data[i]);
		parray[i] = test_data[i];
		if (i < size - 1)
			putchar(',');
		putchar('\n');
	}
	printf("]\n");
	queue = array_to_queue(parray, NELEMS(test_data));
	print_queue(queue);
	parray = queue_to_array(queue, &i);
	print_parray(parray, i);
}

int main()
{
	test_7();
}