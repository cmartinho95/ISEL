/***
 * ISEL, LEIC, Programação de Sistemas Computacionis (PSC)
 * 
 * Resolução das questões 5 e 8 do Teste Global de 1ª Época
 * do semestre de Inverno de 2013/14
 *
 * Carlos Martins, Junho 2017
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * 5. [1] Os processadores Intel Core i7 usam uma cache de nível 2 por core, cada uma com organização
 *    8 ­way set associative e capacidade de 256 KiB com linhas de 64 bytes. Apresentando os cálculos
 *    apropriados, determine qual é a menor distância possível entre os endereços de dois bytes armazenados
 *    em linhas distintas do mesmo set da cache indicada.
 *
 */
/***
Resolução:

C = 256 * 2^10 = 2^18
E = 8 = 2^3
B = 64 = 2^6
b = 6
C = S * B * E
S = C / (B * E) = 2^18/(2^3 * 2^6) = 2^9 = 512
s = 9
tag bits: 32 - (b + s) = 32 - 15 = 17, bits A15..A31

RECTIFICAÇÂO:
Para que duas linhas fiquem no mesmo set têm que ter tags diferente.
Assim, para bytes na mesma posição nas linhas (primeiro, segundo, ..., ordem B-1) a distância será
exactamente 2^15.
Contudo, e de acordo com a observação da aluna Bárbara Pires, se considerarmos bytes em posições
diferentes nos blocos associados às linhas, a distância menor será inferior a 2^15. A distância
menor será entre o byte na posição B - 1 da linha com uma tag onde A15 é zero, com o byte na posição
0 da linha do mesmo set e com uma tag em que A15 seja 1 e os bits restantes sejam iguais.
Rigorosamente, a distância mínima será 2^15 - (B - 1).
Exemplo:
Consideremos uma cache com os seguintes parâmetros (S, E, B, m) = (8, 2, 8, 8).
Neste caso o bit de menor peso da tag será A16.
Consideremos o 1º byte da linha do set 0 cuja tag é 01, ou seja com o endereço 01.000.000 e o último
byte de uma linha do mesmo set cujo endereço será 00.000.111.
01.000.000 - 00.000.111 = 00.111.001 (57 decimal) ou seja 2^6 - (B - 1).

**/

/**
 * 8. [4] A função readInt lê um valor inteiro do standard input, deixando­o no endereço apontado por pval,
 *    retornando false se a leitura falhar por algum motivo. Uma instância do tipo ValCounts armazena em
 *    counters um array de len instâncias do tipo ValCounter. Cada instância de ValCounter armazena um
 *    valor inteiro (val) e uma contagem associada (count). A função countsForDistinctVals lê inteiros
 *    com readInt até que esta função retorne false e devolve uma instância de ValCounts com o número
 *    de ocorrências de cada valor distinto lido.
 *    A função freeValCounts liberta todo(s) o(s) espaço(s) de memória associado(s) a uma instância de
 *    ValCounts alocada dinamicamente. Implemente as funções countsForDistinctVals e freeValCounts.
 *    Se julgar necessário,pode criar funções auxiliares e o array de ValCounters pode consumir espaço extra.
 *
 *    Nota: se readInt ler 7 3 4 7 -1 7 3, o retorno poderá ser:
 *          { len = 4, counters = { { 7, 3 }, { 3, 2 }, { 4, 1 }, { -1, 1 } } }
 *
 *    bool readInt(int * pval) { return scanf("%d", pval) == 1; }
 *
 *    typedef struct val_counter { int val; size_t count; } ValCounter;
 *
 *    typedef struct val_counts { size_t len; ValCounter * counters; } ValCounts;
 *
 *    ValCounts * countsForDistinctVals();
 *
 *    void freeValCounts(ValCounts * vc);
 */

int readInt(int * pval)
{
	return scanf("%d", pval) == 1;
}

typedef struct val_counter {
	int val;
	size_t count;
} ValCounter;

typedef struct val_counts {
	size_t len;
	ValCounter *counters;
} ValCounts;

/* we allocate CHUNK_SIZE ValCounter at once */
#define CHUNK_SIZE	10

ValCounts *countsForDistinctVals()
{
	ValCounts *vcs;
	size_t allocated_size = 0, i;
	int val;
	
	/* allocate ValCounts structure and initialize it */
	vcs = (ValCounts *)malloc(sizeof(ValCounts));
	/* validate allocation with assert */
	assert(vcs != NULL);
	vcs->len = 0;
	vcs->counters = NULL;
next:	
	while (readInt(&val)) {
		/* check if we have already record val */
		for (i = 0; i < vcs->len; i++)
			if (vcs->counters[i].val == val) {
				vcs->counters[i].count += 1;
				goto next;
			}
		/* The next val is not recorded yet; if we do not have counters allocate more CHUNK_SIZE */
		if (vcs->len >= allocated_size) {		
			allocated_size += CHUNK_SIZE;
			vcs->counters = (ValCounter *)realloc(vcs->counters, allocated_size * sizeof(ValCounter));
		}
		/* create e new entry for value */
		vcs->counters[vcs->len].val = val;
		vcs->counters[vcs->len].count = 1;
		vcs->len += 1;
	}
	return vcs;
}

void freeValCounts(ValCounts *vcs)
{
	free(vcs->counters);	/* free() can accept a NULL pointer */
	free(vcs);
}

void printValCounts(ValCounts *vcs)
{
	size_t i;
	
	printf("{ len: %lu, counters: {", vcs->len);
	for (i = 0; i < vcs->len; i++)
		printf(" {%d, %lu}", vcs->counters[i].val, vcs->counters[i].count);
	printf("}\n"); 
}

int test_8() {
	ValCounts *vcs;
	
	vcs = countsForDistinctVals();
	printValCounts(vcs);
	freeValCounts(vcs);
	return 0;
}

int main()
{
	test_8();
	return 0;
}
