#include "../VetorProcura/stdstd.h"
#define MAXFILA 3

typedef struct
{
	int valor;
} filaItem;

typedef struct 	
{
	filaItem itens[MAXFILA];
	size_t frente,tras;
} Fila;

uint8_t filaDesemfila(Fila *fila, filaItem *retorno);
uint8_t filaEmfila(Fila *fila, filaItem *novo);
uint8_t filaImprime(Fila *fila);
uint8_t filaCria(Fila *fila);
size_t filaQuantidade(Fila *fila);	
bool filaEhVazia(Fila *fila);