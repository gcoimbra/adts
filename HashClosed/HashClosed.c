#include "HashClosed.h"

int hashClosedTransfrom(hashClosed *table, char *reg)
{
	int index = 0;

  // Zobrist
	for (size_t i = 0; i < strlen(reg); i++)
		index += table->weights[(int)reg[i] % 65 - 32];

	return index % MAX_HASH;
}

void hashClosedCria(hashClosed *table)
{
	srand(time(NULL));

	for (size_t i = 0; i < MAX_HASH; i++)
	{
		lista l;
		listaCria(&l);
		table->itens[i] = l;
	}
	for (size_t i = 0; i < 26; i++)
		table->weights[i] = rand()%MAX_HASH;
}

void hashClosedInsere(hashClosed *table,char *reg)
{
	listaItem item;
	strcpy(item.reg,reg);
	int index = hashClosedTransfrom(table,reg);
	listaInsere(&table->itens[index],&item);

}

void hashClosedPesquisa(hashClosed *table, char *reg)
{
	listaItem item;
	strcpy(item.reg,reg);
	int index = hashClosedTransfrom(table,reg);
	if(listaVerifica(&table->itens[index],&item))
	{
		printf("Item encontrado!\n");
		return;
	}
	puts("Não encontrado!");
}
