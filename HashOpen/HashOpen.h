#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HASH 10
#define MAX_STRING 10

typedef struct hashOpen
{
	int weights[26];
	char itens[MAX_HASH][MAX_STRING];
} hashOpen;

int hashOpenTransfrom(char *reg);
void hashOpenCria(hashOpen *table);
void hashOpenInsere(hashOpen *table,char *reg);
void hashOpenPesquisa(hashOpen *table, char *reg);
int hashOpenTransfromConstant(hashOpen *table, char *reg);
int hashOpenTransfrom1(hashOpen *table, char *reg);
int hashOpenTransfrom2(hashOpen *table,char *reg);
int hashOpenTransfromReHash(int h1, int h2, int iteration);
