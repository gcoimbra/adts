#include "PilhaEncadeada.h"

void PilhaCria(Pilha *pilha)
{
  pilha->topo = (PilhaCelula *) malloc(sizeof(PilhaCelula));
  pilha->fundo = pilha->topo;
  pilha->topo->prox = NULL;
  pilha->tamanho = 0;
}

int PilhaEhVazia(Pilha *pilha)
  {
		return (pilha->topo == pilha->fundo);
	}

void PilhaEmpilha(Pilha *pilha, PilhaCelulaItem x)
{
  PilhaCelula *aux;
  aux = (PilhaCelula *) malloc(sizeof(PilhaCelula));
  pilha->topo->item = x;
  aux->prox = pilha->topo;
  pilha->topo = aux;
  pilha->tamanho++;
}

void PilhaDesempilha(Pilha *pilha, PilhaCelulaItem *item)
{
  PilhaCelula *aux;
  if (PilhaEhVazia(pilha))
  {
    printf("Erro: lista vazia\n");
    return;
  }

  aux = pilha->topo;
  pilha->topo = aux->prox;
  *item = aux->prox->item;
  free(aux);
  pilha->tamanho--;
}

int PilhaTamanho(Pilha *pilha)
{
		return (pilha->tamanho);
}
