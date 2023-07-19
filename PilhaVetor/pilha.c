#include "pilha.h"
	
uint8_t pilhaDesempilha(Pilha *pilha, pilhaItem *retorno)
{
	if(pilhaEhVazia(pilha))
	{
		printf("pilhaDesempilha(): Pilha está vazia!\n");
		return 0;
	}
	if(retorno != NULL)
		*retorno = pilha->itens[--pilha->topo];
	else
		pilha->topo--;
	return 1;
}

size_t pilhaQuantidade(Pilha *pilha)
{
	return pilha->topo;
}

uint8_t pilhaEmpilha(Pilha *pilha, pilhaItem *novo)
{
	if(pilhaEhCheia(pilha))
	{
		printf("pilhaEmpilha(): pilha cheia!\n");
		return 0;
	}
	pilha->itens[pilha->topo++] = *novo;
	return 1;
}

bool pilhaEhVazia(Pilha *pilha)
{
	return (pilha->topo == 0);
}

bool pilhaEhCheia(Pilha *pilha)
{
	return (pilha->topo == MAXPILHA);
}

uint8_t pilhaImprime(Pilha *pilha)
{
	if(pilhaEhVazia(pilha))
	{
		printf("pilhaImprime(): Pilha está vazia!\n");
		return 0;
	}
	for (size_t i = 0; i < pilha->topo; ++i)
	{
		//pilhaImprimeItem
		printf("%c\n", pilha->itens->valor);
	}
	return 1;
}

uint8_t pilhaCria(Pilha *pilha)
{
	pilha->topo = 0;
	return 1;
}
