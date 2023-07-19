#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  int chave;
} listaItem;

typedef struct listaCelula listaCelula;
typedef struct listaCelula
{
  listaItem item;
  listaCelula* prox;
} listaCelula;

typedef struct
{
  listaCelula *primeiro, *ultimo;
} lista;

void listaCriaLVazia(lista *lista);
int listaVerificaEhVazia(lista lista);
void listaInsere(listaItem x, lista *lista);
void listaRetira(listaCelula * p, lista *lista, listaItem *item);
void listaImprime(lista *lista);
