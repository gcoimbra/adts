//Bibliotecas que o tad precisa
#include <stdlib.h>
#include <sys/time.h>
#include <stdio.h>

typedef struct
{
  int chave;
} FilaCelulaItem;

typedef struct FilaCelula FilaCelula;

typedef struct FilaCelula
{
  node *item;
  FilaCelula *prox;
} FilaCelula;

typedef struct {
  FilaCelula *frente, *tras;
} Fila;

void filaCriaVazia(Fila *fila);
int filaVazia(Fila * fila);
void filaEnfileira(Fila *fila, FilaCelulaItem * item);
void filaDesenfileira(Fila *fila, FilaCelulaItem *item);
void filaImprime(Fila fila);
