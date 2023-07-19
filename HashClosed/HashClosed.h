#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ListaEncadeada/ListaEncadeada.h"

#define MAX_HASH 10

typedef struct hashClosed
{
	int weights[26];
	lista itens[MAX_HASH];
} hashClosed;

int hashOpenTransfrom(hashClosed *table, char *reg);
void hashClosedCria(hashClosed *table);
void hashClosedInsere(hashClosed *table,char *reg);
void hashClosedPesquisa(hashClosed *table, char *reg);
