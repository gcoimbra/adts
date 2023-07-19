#include "../VetorProcura/stdstd.h"
#define MAXPILHA 10

typedef struct
{
	char valor;
} pilhaItem;

typedef struct 	
{
	pilhaItem itens[MAXPILHA];
	size_t topo;
} Pilha;

uint8_t pilhaDesempilha(Pilha *pilha, pilhaItem *retorno);
uint8_t pilhaEmpilha(Pilha *pilha, pilhaItem *novo);
uint8_t pilhaImprime(Pilha *pilha);
uint8_t pilhaCria(Pilha *pilha);
size_t pilhaQuantidade(Pilha *pilha);	
bool pilhaEhVazia(Pilha *pilha);	
bool pilhaEhCheia(Pilha *pilha);