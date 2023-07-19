#include "stdstd.h"

int main(void)
{
	Fila fila;
	filaCria(&fila);
	printf("Fila eh vazia: %d\n",filaEhVazia(&fila));


	filaItem item1,item2,item3;
	item1.valor = 10;
	item2.valor = 20;
	item3.valor = 30;
	filaEmfila(&fila,&item1);
	filaEmfila(&fila,&item2);
	filaDesemfila(&fila,&item1);
	filaImprime(&fila);
	filaDesemfila(&fila,&item1);
	filaEmfila(&fila,&item3);
	filaImprime(&fila);
	return 0;
}