/***
 * ISEL, LEIC, Programação de Sistemas Computacionis (PSC)
 * 
 * Resolução das questões 6 e 7 do Teste Global de 2ª Época
 * do semestre de Verão de 2014/15
 *
 * Carlos Martins, Junho 2017
 *
 **/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * 6. [1] Considere uma cache com organização 4-way set associative, cuja capacidade permite armazenar
 *    exactamente um array com 4096 instâncias de Info, quando o endereço do array é alinhado a 64 bytes
 *    (i.e., é múltiplo de 64). Indique, apresentando os cálculos necessários, quantos sets tem a cache,
 *    e quantas instâncias de Info são armazenadas numa linha.
 *
 *    typedef struct {unsigned int id; char key[4]; double factors[3]; } Info;
 *
 * Resolução:
 * E = 4
 * sizeof(Info) = 32
 * C = 4096 * 32 = 2 ^ 12 * 2 ^ 5 = 2 ^ 17 = 128 KiB
 * B = 64 = 2 ^ 6	<- obtido a partir da informação do alinhamento
 *
 * S = C / (E * B) = 2 ^ 17 / (2 ^ 2 * 2 ^ 6) = 2 ^ (17 - 8) = 2 ^ 9 = 512 sets
 * São armazenadas duas instâncias de Info por linha.
 */
	
/**
 * 7. [3.5] Considere o conjunto de blocos de dados opacos, armazenados numa lista simplesmente ligada,
 *    com nós do tipo LNode, e representada pelo ponteiro para o primeiro nó da lista. Cada bloco de
 *    dados é armazenado numa instância do tipo Info. Implemente a função listOfInfoToArray que,
 *    a partir dos dados armazenados numa lista, constrói um array cujos elementos são do tipo ponteiro
 *    para Info, que definem o endereço da respectiva instância de Info. Toda a memória usada para armazenar
 *    o array deverá ser alocada dinamicamente; a função devolve, por valor, o ponteiro para o primeiro
 *    elemento do array, sendo o seu número de elementos devolvido através do parâmetro elemsPtr.
 *    Implemente também a função freeInfoArray, cuja responsabilidade é libertar toda a memória alocada
 *    pela função listOfInfoToArrayaquando da construção do array.
 *
 *    typedef struct info Info;
 *    typedef struct list_node LNode;
 *    struct info { const char *tag; unsigned count; unsigned data[32]; };
 *    struct list_node{ LNode *next; Info *info; };
 *    Info **listOfInfoToArray(LNode *list, unsigned *elemsPtr);
 *    void freeInfoArray(Info **array, unsigned nelems);
 *
 */

typedef struct info_node {
	const char *tag;
	size_t count;
	unsigned int data[32];
} INode;

typedef struct list_node {
	struct list_node *next;
	INode *info;	
} LNode;

/**
 * version 1 - computing in advance the number of list nodes
 */

INode **listOfInfoToArray(LNode *list, size_t *elemsPtr) {
	size_t nelems, i;
	LNode *lptr;
	INode **array;
	
	// compute the number of nodes in the list
	for (nelems = 0, lptr = list; lptr != NULL; nelems++, lptr = lptr->next)
		;
	if (nelems == 0)
		return NULL;
	array = (INode **) malloc(sizeof(INode *) * nelems);
	
	assert(array != NULL);
	
	// copy info from the list into the array
	for (i = 0, lptr = list; i < nelems; i++, lptr = lptr->next) {		
		array[i] = (INode *)malloc(sizeof(INode));
		assert(array[i] != NULL);
		array[i]->tag = strdup(lptr->info->tag);
		array[i]->count = lptr->info->count;
		memcpy(array[i]->data, lptr->info->data, lptr->info->count * sizeof(unsigned));
	}
	*elemsPtr = nelems;
	return array;
}

/**
 * version 2 - using realloc 
 */

INode **listOfInfoToArray2(LNode *list, size_t *elemsPtr) {
	size_t i;
	INode **array = NULL;
	
	// copy info from the list into the array
	for (i = 0; list != NULL; i++, list = list->next) {
		array = (INode **)realloc(array, (i + 1) * sizeof(INode *));
		assert(array != NULL);
		array[i] = (INode *)malloc(sizeof(INode));
		assert(array[i] != NULL);	
		array[i]->tag = strdup(list->info->tag);
		array[i]->count = list->info->count;
		memcpy(array[i]->data, list->info->data, list->info->count * sizeof(unsigned));
	}
	*elemsPtr = i;
	return array;
}

void freeArray(INode **array, size_t nelems)
{
	size_t i;
	
	if (array == NULL)
		return;
	for (i = 0; i < nelems; i++) {
		free(array[i]->key);	/* allocated by strdup() */
		free(array[i]);
	}
	free(array);
}

/* the Info nodes */
INode info_0 = { .tag = "tag 0", .count = 3, .data = { 1, 2, 3 } };
INode info_1 = { .tag = "tag 1", .count = 4, .data = { 1, 2, 3, 4 } };
INode info_2 = { .tag = "tag 2", .count = 5, .data = { 1, 2, 3, 4, 5 } };
INode info_3 = { .tag = "tag 3", .count = 6, .data = { 1, 2, 3, 4, 5, 6 } };
INode info_4 = { .tag = "tag 4", .count = 7, .data = { 1, 2, 3, 4, 5, 6, 7 } };
INode info_5 = { .tag = "tag 5", .count = 8, .data = { 1, 2, 3, 4, 5, 6, 7, 8 } };

/* the list nodes */
LNode lnode_5 = { .next = NULL,     .info = &info_5 };
LNode lnode_4 = { .next = &lnode_5, .info = &info_4 };
LNode lnode_3 = { .next = &lnode_4, .info = &info_3 };
LNode lnode_2 = { .next = &lnode_3, .info = &info_2 };
LNode lnode_1 = { .next = &lnode_2, .info = &info_1 };
LNode lnode_0 = { .next = &lnode_1, .info = &info_0 };

int main()
{
	size_t nelems, i;
	INode **array = listOfInfoToArray2(&lnode_0, &nelems);
	printf("n: %zd\n", nelems);
	for (i = 0; i < nelems; i++) {
		size_t j;
		printf(".tag: %s, .count: %zd, .data: ", array[i]->tag, array[i]->count);
		for (j = 0; j < array[i]->count; j++)
			printf("%d%s", array[i]->data[j], (j < array[i]->count - 1 )  ? ", " : "\n");
	}
	freeArray(array, nelems);
	return 0;
}
