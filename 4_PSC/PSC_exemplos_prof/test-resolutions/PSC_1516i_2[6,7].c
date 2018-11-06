/***
 * ISEL, LEIC, Programação de Sistemas Computacionis (PSC)
 * 
 * Resolução das questões 6 e 7 do Teste Global de 2ª Época
 * do semestre de Inverno de 2015/16
 *
 * Carlos Martins, Junho 2017
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/**
 * 6. [1] Considere uma cache com topologia N-way set associative com uma capacidade de 4 MiB (m = 32).
 *    Nesta cache são utilizados os 14 bit de maior peso do endereço para definir a tag e os 12 bit
 *    seguintes para identificar o set.  Justificando adequadamente, indique o número de bytes por linha
 *    e o número de vias (ways) por set.
 *
 *  C = 4 MiB = 2 ^ 22
 *  m = 32
 *  t = 14
 *  s = 12
 *  b = m - (s + t) = 32 - (14 + 12) = 6 bits para definir o offset dentro do bloco, logo B = 2 ^ 6 = 64
 *  E = C / (S * B) = 2 ^ 22 / (2 ^ 12 * 2 ^ 6) = 2 ^ 4 = 16 vias por set
 *
 */

/**
 * 7. [3] O tipo Data representa um item de dados composto por array elementos do tipo double identificados
 *    por uma chave; o array é definido pelos campos length e values, dimensão e endereço, respectivamente.
 *    O tipo DataNode é um tipo auxiliar destinado a organizar em lista conjuntos de instâncias do tipo Data.
 *    A função array_to_list constrói uma lista simplesmente ligada com as instâncias de Data passadas através
 *    dos parâmetros array e length; toda a memória utilizada para construir a lista devolvida por esta função
 *    deve ser alocada dinamicamente. A função free_list liberta toda a memória alocada dinamicamente pela
 *    função array_to_list. Implemente, em linguagem C, estas duas funções.
 *
 *    typedef struct data { char key[8]; size_t length; double *values; } Data;
 *    typedef struct data_node {struct data_node *next; Data *data; } DataNode;
 *    DataNode *array_to_list(Data array[], size_t length);
 *    void free_list(DataNode *list);
 *
 */

typedef struct data {
	char key[8];
	size_t length;
	double *values;
 } Data;
 
 typedef struct data_node {
	 struct data_node *next;
	 Data *data;
 } DataNode;
 
DataNode *array_to_list(Data data[], size_t length)
{
	DataNode *first = NULL, *last;
	size_t i;
	
	for (i = 0; i < length; i++) {
		Data *d = (Data *)malloc(sizeof(Data));
		DataNode *dn = (DataNode *)malloc(sizeof(DataNode));
		
		memcpy(d->key, data[i].key, sizeof(d->key));	/* key */
		d->length = data[i].length;						/* values */
		d->values = (double *)malloc(sizeof(double) * d->length);
		memcpy(d->values, data[i].values, d->length * sizeof(double));
		dn->data = d;
		/* insert the node at the end of the list */
		dn->next = NULL;
		if (first == NULL)
			first = dn;
		else
			last->next = dn;
		last = dn;
	}
	return first;
}

void free_list(DataNode *dlist)
{
	while (dlist != NULL) {
		DataNode *next = dlist->next;
		free(dlist->data->values);
		free(dlist->data);
		free(dlist);
		dlist = next;
	}
}

Data *build_array(size_t *length)
{
	size_t i, j, len = (rand() % 8) + 1;	/* a random vector length */
	Data *vector = (Data *)malloc(len * sizeof(Data));
	
	for (i = 0; i < len; i++) {
		sprintf(vector[i].key, "%07zd", i + 1);
		vector[i].length = (rand() % 4) + 1;
		vector[i].values = (double *)malloc(vector[i].length * sizeof(double));
		for (j = 0; j < vector[i].length; j++)
			vector[i].values[j] = rand() % 1000;
	}
	*length = len;
	return vector;
}

void print_array(Data *array, size_t length)
{
	size_t i, j;
	
	printf("array:\n");
	for (i = 0; i < length; i++) {
		printf("{ key: %*s, length: %zd, values:", 8, array[i].key, array[i].length);
		for (j = 0; j < array[i].length; j++)
			printf(" %.1f", array[i].values[j]);
		printf("}\n");
	}
}

void print_list(DataNode *dlist)
{
	size_t j;
	
	printf("list:\n");
	for (; dlist != NULL; dlist = dlist->next ) {
		Data *d = dlist->data;
		printf("{ key: %*s, length: %zd, values:", 8, d->key, d->length);
		for (j = 0; j < d->length; j++)
			printf(" %.1f", d->values[j]);
		printf("}\n");
	}
}

void test_7()
{
	size_t len;
	Data *a = build_array(&len);
	print_array(a, len);
	DataNode *list = array_to_list(a, len);
	print_list(list);
	free_list(list);
}


int main() {
	test_7();
	return 0;
}
