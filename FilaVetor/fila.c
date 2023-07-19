#include "fila.h"

size_t filaQuantidade(Fila *fila)
{
	if(fila->tras > fila->frente)
		return fila->tras - fila->frente;
	else if(fila->tras <  fila->frente)
		return (MAXFILA - abs(fila->frente - fila->tras));
	else 
		return 0;
}

bool filaEhVazia(Fila *fila)
{
	return (fila->frente == fila->tras);
}

bool filaEhCheia(Fila *fila)
{
	return ((fila->tras + 1)%MAXFILA == fila->frente );
}

uint8_t filaDesemfila(Fila *fila, filaItem *retorno)
{
	if(filaEhVazia(fila))
	{
		printf("filaDesemfila(): Fila está vazia!\n");
		return 0;
	}
	// printf("aqui %zu\n", fila->itens[fila->frente--].valor);
	*retorno = fila->itens[fila->frente];
	if(fila->frente < fila->tras)
		fila->frente = (fila->frente+1)%MAXFILA;
	else
		fila->frente = (fila->frente-1)%MAXFILA;
	return 1;
}

uint8_t filaEmfila(Fila *fila, filaItem *novo)
{
	if(filaEhCheia(fila))
	{
		printf("filaEmfila(): fila cheia!\n");
		return 0;
	}
	fila->itens[fila->tras] = *novo;
	fila->tras = (fila->tras+1)%MAXFILA;
	return 1;
}

uint8_t filaImprime(Fila *fila)
{
	if(filaEhVazia(fila))
	{
		printf("filaImprime(): Fila está vazia!\n");
		return 0;
	}
	for (size_t i = fila->frente; (i%MAXFILA) != (fila->tras); ++i) 
	{
		// filaImprimeItem
		printf("%d\n", fila->itens[i].valor);
	}
	return 1;
}

uint8_t filaCria(Fila *fila)
{
	fila->frente = 0;
	fila->tras = 0;
	return 1;
}
