/**
 *
 *  Resolution of question 7 of the final test of 1617v_1
 *
 * Carlos Martins, May 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

typedef struct dblock {
	size_t length;
	unsigned char *raw_data;
} DBlock;

typedef struct dblock_node {
	struct dblock_node *next;
	DBlock dblock;
} DBlockNode;

DBlockNode *split_dblock(DBlock *dblock, size_t size)
{
	DBlockNode *first = NULL, *last;
	size_t data_off = 0, actual_size;
	while (dblock->length > 0) {		
		actual_size = dblock->length >= size ? size : dblock->length;
		DBlockNode *np = (DBlockNode *)malloc(sizeof(DBlockNode));
		assert(np != NULL);
		dblock->length -= actual_size;
		np->dblock.length = actual_size;
		np->dblock.raw_data = (unsigned char *)malloc(actual_size);
		assert(np->dblock.raw_data != NULL);
		memcpy(np->dblock.raw_data, dblock->raw_data + data_off, actual_size);
		data_off += size;
		np->next = NULL;
		if (first != NULL) {
			last->next = np;
			last = np;			
		} else
			first = last = np;
	}
	/* free input data */
	free(dblock->raw_data);
	free(dblock);
	
	return first;
}

DBlock *join_dblocks(DBlockNode *dblist)
{
	DBlock *result = (DBlock *)malloc(sizeof(DBlock));
	assert(result != NULL);
	result->length = 0;
	result->raw_data = NULL;
	
	while (dblist != NULL) {
		DBlockNode *next = dblist->next; 
		result->raw_data = (unsigned char *)realloc(result->raw_data,
			 									    result->length + dblist->dblock.length);
		assert(result->raw_data != NULL);
		memcpy(result->raw_data + result->length, dblist->dblock.raw_data,
			   dblist->dblock.length);
		result->length += dblist->dblock.length;
		free(dblist->dblock.raw_data);
		free(dblist);
		dblist = next;
	}
	return result;
}

void print_dblock(DBlock *dblock) {
	size_t i;
	printf("block: {\n\tlength: %zd\n\traw_data: [\n\t\t", dblock->length);
	for (i = 0; i < dblock->length; i++) {
		if (i != 0 && i % 8 == 0)
			printf("\n\t\t");
		printf("%02x ", dblock->raw_data[i]);
	}
	printf("\n\t]\n}\n");
}

void print_dblist(DBlockNode *dblist) {
	size_t i;
	printf("list:\n");
	for (; dblist != NULL; dblist = dblist->next) {
		printf("\t{ ");
		for (i = 0; i < dblist->dblock.length; i++) {
			if (i != 0 && i % 16 == 0)
				putchar('\n');
			printf("%02x ", dblist->dblock.raw_data[i]);
		}
		printf("}\n");
	}
}

DBlock *build_dblock()
{
	size_t i;
	DBlock *dblock = (DBlock *)malloc(sizeof(DBlock));
	
	srand(time(NULL));
	dblock->length = rand() % 100;
	dblock->raw_data = (unsigned char *)malloc(dblock->length);
	for (i = 0; i < dblock->length; i++)
		dblock->raw_data[i] = rand() & 0xff;
		return dblock;
}

void free_dblist(DBlockNode *dblist)
{
	while (dblist != NULL) {
		DBlockNode *next = dblist->next;
		free(dblist->dblock.raw_data);
		free(dblist);
		dblist = next;
	}
}

void free_dblock(DBlock *dblock)
{
	free(dblock->raw_data);
	free(dblock);	
}

void test_7()
{
	DBlock *dblock = build_dblock();
	print_dblock(dblock);
	DBlockNode *dblist = split_dblock(dblock, 4);
	print_dblist(dblist);
	dblock = join_dblocks(dblist);
	print_dblock(dblock);
	free_dblock(dblock);
}

int main()
{
	test_7();
}