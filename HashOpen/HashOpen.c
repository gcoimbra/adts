#include "HashOpen.h"

int hashOpenTransfromConstant(hashOpen *table, char *reg)
{
	int index = 0;

  // Zobrist
	for (size_t i = 0; i < strlen(reg); i++)
		index += table->weights[(int)reg[i] % 65 - 32];

	return index % MAX_HASH;
}

int hashOpenTransfrom1(hashOpen *table, char*reg)
{
	int index = hashOpenTransfromConstant(table, reg);
	return index % MAX_HASH;
}

int hashOpenTransfrom2(hashOpen *table,char *reg)
{
	int index = hashOpenTransfromConstant(table,reg);
	return 1 + (index % (MAX_HASH-1));
}

int hashOpenTransfromReHash(int h1, int h2, int iteration)
{
	return (h1 + iteration*h2)%MAX_HASH;
}

void hashOpenCria(hashOpen *table)
{
	for (size_t i = 0; i < MAX_HASH; i++)
		table->itens[i][0] = 0;
	for (size_t i = 0; i < 26; i++)
		table->weights[i] = rand()%MAX_HASH;
}

void hashOpenInsere(hashOpen *table,char *reg)
{
	int h1 = hashOpenTransfrom1(table,reg);

	if(table->itens[h1][0] != 0)
	{
		int iteration = 0;
		int h2 = hashOpenTransfrom2(table, reg);
		int rh = hashOpenTransfromReHash(h1, h2, iteration+2);

		while(table->itens[rh][0] != 0)
		{
			rh = hashOpenTransfromReHash(h1, h2, iteration+1);
			iteration++;
			if(iteration > MAX_HASH)
			{
				printf("hashOpenInsere(): sem memória!\n");
				exit(-1);
			}
		}

		strcpy(table->itens[rh],reg);
	}
	else
		strcpy(table->itens[h1],reg);
}

void hashOpenPesquisa(hashOpen *table, char *reg)
{
	int h1 = hashOpenTransfrom1(table,reg);

	if(strcmp(&table->itens[h1][0],reg) != 0)
	{
		int iteration = 0;
		int h2 = hashOpenTransfrom2(table, reg);
		int rh = hashOpenTransfromReHash(h1, hashOpenTransfrom2(table, reg), iteration+1);

		while(strcmp(&table->itens[rh][0],reg) != 0)
		{
			rh = hashOpenTransfromReHash(h1, h2, iteration+1);
			iteration++;
			if(iteration > MAX_HASH)
			{
				printf("hashOpenPesquisa(): item não econtrado!\n");
				exit(-1);
			}
		}
		puts("hashOpenPesquisa(): item encontrado!");
	}
	puts("hashOpenPesquisa(): item encontrado!");
}
