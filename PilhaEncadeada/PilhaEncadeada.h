// As bibliotecas que o TAD precisa
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct
{
  int chave;
} PilhaCelulaItem;

typedef struct PilhaCelula PilhaCelula;
typedef struct PilhaCelula
{
  PilhaCelulaItem item;
  PilhaCelula *prox;
} PilhaCelula;

typedef struct
{
  PilhaCelula *fundo, *topo;
  uint tamanho;
} Pilha;
