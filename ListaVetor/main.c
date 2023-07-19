#include "stdstd.h"
#include "ListaVetor.h"

int main()
{
	Lista lista1,a,lista2;
	ListaCria(&lista1);
	ListaCria(&a);
	Item primeiro;
	for(int i = 1; i < 11; i++)
	{
		primeiro.valor = i*10;
		ListaInsira(&lista1, &primeiro, ListaRetornaFim(&lista1));
		primeiro.valor = i;
		ListaInsira(&a, &primeiro, ListaRetornaFim(&a));
		printf("\n");
	}
	ListaImprima(&lista1);
	ListaImprima(&a);
	ListaIntercala(&lista1,&lista1,&a);
	ListaImprima(&lista1);
	return 0;
}
