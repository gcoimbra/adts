#include "ListaEncadeada.h"

void listaCriaLVazia(lista *lista)
{
  lista -> primeiro = (listaCelula *) malloc(sizeof(listaCelula));
  lista -> ultimo = lista -> primeiro;
  lista -> primeiro -> prox = NULL;
}

int listaVerificaEhVazia(lista lista)
{
  return (lista.primeiro == lista.ultimo);
}

void listaInsere(listaItem x, lista *lista)
{
  lista -> ultimo -> prox = (listaCelula *) malloc(sizeof(listaCelula));
  lista -> ultimo = lista -> ultimo -> prox;
  lista -> ultimo -> item = x;
  lista -> ultimo -> prox = NULL;
}

void listaRetira(listaCelula * p, lista *lista, listaItem *item)
{
  listaCelula * q;
  if (listaVerificaEhVazia(*lista) || p == NULL || p -> prox == NULL)
  {
    printf("listaRetira(): Erro lista vazia \n");
    return;
  }
  q = p -> prox;
  *item = q -> item;
  p -> prox = q -> prox;
  if (p -> prox == NULL)
    lista -> ultimo = p;
  free(q);
}

void listaImprime(lista lista)
{
  listaCelula * aux;
  aux = lista.primeiro -> prox;
  while (aux != NULL)
    { printf("%d\n", aux -> item.chave);
      aux = aux -> prox;
    }
}
