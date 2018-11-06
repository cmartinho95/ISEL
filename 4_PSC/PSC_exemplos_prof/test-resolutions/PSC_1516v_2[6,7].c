/***
 * ISEL, LEIC, Programação de Sistemas Computacionis (PSC)
 * 
 * Resolução das questões 6 e 7 do Teste Global de 2ª Época
 * do semestre de Verão de 2015/16
 *
 * Carlos Martins, Junho 2017
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * 6. [1,5] Considere uma cache com dimensão 128 KiB e organização em mapeamento direto (E = 1).
 *    Admitindo que a dimensão do bloco é de 32 byte, indique, justificando, dois endereços que
 *    colidam na mesma linha da cache. 
 *
 * Raciocínio: Colidem na mesma linha de cache os endereços que tenham o mesmo valor nos bits
 * que definem o set index.
 *
 * C = 128 KiB = 2 ^ 17
 * E = 1
 * B = 32 = 2 ^ 5, b = 5
 * S = C / (E * B) = 2 ^ 12 / ( 2 ^ 0 * 2 ^ 5) = 2 ^ 7 = 128, s = 7
 * bits 0..4: definem o byte offset dentro do block
 * bits 5..11: definem o set index
 * bits 12..31: definem a tag
 *
 * Dois endereços que colidem na mesma linha: (0x80000000 | (0x20 << 5) | 0x1f)  e
 * (0xffff0000 | (0x20 << 5) | 0x4)
 * 
 */

/**
 * 7. [3] O tipo Chunk representa um bloco de dados identificados por uma chave e composto por
 *    um número arbitrário de valores do tipo long; os valores são armazenados num array, com
 *    dimensão length, cujo endereço é armazenado no campo values. O tipo ChunkNode é um tipo
 *    auxiliar usado para organizar grupos de blocos de dados em lista ligada.
 *    A função merge_chunks_by_key recebe uma lista de blocos de dados, representado por instâncias
 *    do tipo ChunkNode, e devolve o endereço de uma instância do tipo Chunk, completamente armazenada
 *    em memória alocada dinâmicamente, com os dados associados a todos os nós da lista cuja chave
 *    seja igual ao argumento key, ou NULL se não existir nenhum nó na lista com a chave especificada.
 *    A função free_chunk liberta a memória alocada dinamicamente pela função merge_chunks_by_key
 *    para armazenar a instância de Chunk retornada. Implemente estas duas funções em linguagem C.
 *
 *    typedef struct chunk { char *key; size_t length; long *values; } Chunk;
 *    typedef struct chunk_node {struct chunk_node *next; Chunk chunk; } ChunkNode;
 *    Chunk *merge_chunks_by_key(ChunkNode *clist, const char *key);
 *    void free_chunk(Chunk *chunk);
 */

typedef struct chunk {
	const char *key;
	size_t length;
	long *values;
} Chunk;

typedef struct chunk_node {
	struct chunk_node *next;
	Chunk chunk;
} ChunkNode;

/* merge_chunks_by_key: merge all chunks that have the same key */

Chunk *merge_chunks_by_key(ChunkNode *clist, const char *key)
{
	Chunk *result = (Chunk *)malloc(sizeof(Chunk));
	result->key = strdup(key);
	result->length = 0;
	result->values = NULL;
	
	for (; clist != NULL; clist = clist->next)
		if (strcmp(clist->chunk.key, key) == 0) {
			size_t new_len = result->length + clist->chunk.length;
			result->values = (long *)realloc(result->values, new_len * sizeof(long));
			memcpy(result->values + result->length, clist->chunk.values, clist->chunk.length * sizeof(long));
			result->length = new_len;
		}
	if (result->length != 0)
		return result;
	/* no list nodes have the specified key; so free the allocated memory */ 
	free((void *)result->key);		/* allocated by strdup() */
	free((void *)result);	
	return NULL;
}

/* frees a Chunk struture */
void free_chunk(Chunk *c)
{
	free((void *)c->key);
	free(c->values);
	free(c);	
}

void free_chunk_node(ChunkNode *cn)
{
	free((void *)cn->chunk.key);
	free(cn->chunk.values);
	free(cn);	
}


void free_chunk_list(ChunkNode *clist)
{
	while (clist != NULL) {
		ChunkNode *next = clist->next;
		free_chunk_node(clist);
		clist = next;
	}
}

void show_chunk(Chunk *c)
{
	printf("{ key: \"%s\", length: %zd, values: { ", c->key, c->length);
	for (int i = 0; i < c->length; i++)
		printf("%ld ", c->values[i]);
	printf("}\n");
}

void show_chunk_list(ChunkNode *clist)
{
	for (; clist != NULL; clist = clist->next)
		 show_chunk(&clist->chunk);
}

/* chunk data */

long cv1[] = { 1, 2 };
long cv2[] = { 1, 2, 3, 4 };
long cv3[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

/* a chunk list */
ChunkNode cn3 = {
	.next = NULL,
	.chunk = {
		.key = "third",
		.length = 8,
		.values = cv3
	}
};

ChunkNode cn2 = {
	.next = &cn3,
	.chunk = {
		.key = "third", // "second"
		.length = 4,
		.values = cv2
	}
};

ChunkNode cn1 = {
	.next = &cn2,
	.chunk = {
		.key = "first", // "first"
		.length = 2,
		.values = cv1
	}
};

void test_7()
{
	Chunk *mc = merge_chunks_by_key(&cn1, "third");
	show_chunk(mc);
	free_chunk(mc);
}

int main() {
	test_7();
	return 0;
}

