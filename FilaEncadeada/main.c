#include "filaEncadeada.h"
# define MAX 10

int main()
{
  FilaCelulaItem vet[4];
  vet[0].Chave=1;
  vet[1].Chave=8;
  vet[2].Chave=2;
  vet[3].Chave=5;

  Fila fila;

  criaVazia(&fila);
  printf("vazia %d\n",vazia(&fila));
  enfileira(&vet[0],&fila);
  enfileira(&vet[1],&fila);
  enfileira(&vet[3],&fila);
  imprime(fila);
  desenfileira(&fila,&vet[1]);
  printf("item apagado %d\n",vet[1].Chave);
  printf("vazia %d\n",vazia(&fila));
  imprime(fila);
  desenfileira(&fila,&vet[1]);
  printf("item apagado %d\n",vet[1].Chave);

  return 0;
}
