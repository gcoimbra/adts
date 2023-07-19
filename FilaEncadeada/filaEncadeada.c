#include "filaEncadeada.h"

void filaCriaVazia(Fila *fila)
{
  fila->frente = (FilaCelula*) malloc(sizeof(FilaCelula));
  fila->tras = fila->frente;
  fila->frente->prox = NULL;
}

int filaVazia(Fila * fila)
{
  return (fila->frente == fila->tras);
}

void filaEnfileira(FilaCelulaItem * item, Fila *fila)
{
  fila->tras->prox = (FilaCelula *) malloc(sizeof(FilaCelula));
  fila->tras = fila->tras->prox;
  fila->tras->item = *item;
  fila->tras->prox = NULL;
}

void filaDesenfileira(Fila *fila, FilaCelulaItem *item) //guarda o item removido no parametro *item
{
  FilaCelula * aux;
  if (filaVazia(fila)) {
    printf("Erro fila esta vazia\n"); return;
  }
  aux = fila->frente;
  fila->frente = fila->frente->prox;
  *item = fila->frente->item;
  free(aux);
}

void imprime(Fila fila)
{
  FilaCelula * aux;
  aux = fila.frente->prox;
  while (aux != NULL)
    {
      printf("%d\n", aux->item.chave);
      aux = aux->prox;
    }
}
