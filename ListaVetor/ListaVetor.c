#include "stdstd.h"
#include "ListaVetor.h"

void ListaCria(Lista *lista)
{
	lista->Inicio = 0;
	lista->Fim = 0;
}
void ListaZera(Lista *lista)
{
	for(size_t i = lista->Inicio; i <= lista->Fim; i++)
		lista->itens[i].valor = 0;
}
uint8_t ListaEhVazia(Lista *lista)
{
	if(lista->Inicio == lista->Fim)
		return 1;
	return 0;
}
uint8_t ListaImprima(Lista *lista)
{
	if(lista->Fim == lista->Inicio)
	{
		printf("ListaImprima(): lista vazia!\n");
		return 0;
	}
	for(size_t index = 0; index < lista->Fim; index++)
		printf("%zu:\'%d\' ",index,lista->itens[index].valor);
	printf("\n");
	return 1;
}
uint8_t ListaRetira(Lista *lista, Item *item,size_t posicao)
{
	if(posicao < lista->Inicio || posicao >= lista->Fim)
	{
		printf("listaRetira(): Posicao: %zu invalida! Fim da lista: %zu inicio da lista: %zu\n",posicao,lista->Fim,lista->Inicio);
		return 0;
	}
	if(item != NULL)
		*item = lista->itens[posicao];

	#ifdef VERBOSE
	printf("DEBUG ListaRetira(): Removendo item '%u' da posicao %zu\n",lista->itens[posicao].valor, posicao);
	#endif

	for(size_t index = posicao; index < lista->Fim; index++)
		lista->itens[index] = lista->itens[index+1];
	lista->Fim -= 1;
	return 1;

}
uint8_t ListaInsira(Lista *lista, Item *item, size_t posicao)
{
	if(posicao < lista->Inicio || posicao > lista->Fim)
	{
		printf("listaInsira(): Posicao: %zu invalida! Fim da lista: %zu inicio da lista: %zu\n",posicao,lista->Fim,lista->Inicio);
		return 0;
	}
	#ifdef VERBOSE
	printf("DEBUG listaInsira(): Inserindo item '%u' na posicao %zu\n",item->valor, posicao);
	#endif
	Item temp = lista->itens[posicao];
	lista->itens[posicao] = *item;
	for(size_t index = posicao+1; index <= lista->Fim; index++)
	{
		Item temp2 = lista->itens[index];
		lista->itens[index] = temp;
		temp = temp2;
	}
	lista->Fim += 1;
	return 1;
}
uint8_t ListaRetornaElemento(Lista *lista, Item *item, size_t posicao)
{
	if(posicao < lista->Inicio || posicao >= lista->Fim)
	{
		printf("ListaRetornaElemento(): Posicao: %zu invalida! Fim da lista: %zu inicio da lista: %zu\n",posicao,lista->Fim,lista->Inicio);
		return 0;
	}
	*item = lista->itens[posicao];
	return 1;
}

size_t ListaRetornaFim(Lista *lista)
{
	return lista->Fim;
}
size_t ListaRetornaInicio(Lista *lista)
{
	return lista->Inicio;
}
size_t ListaRetornaTamanho(Lista *lista)
{
	return (lista->Fim-1) - lista->Inicio;
}

uint8_t ListaCopia(Lista *destino, Lista *fonte)
{
	if(ListaEhVazia(destino) == 1 || ListaEhVazia(fonte) == 1)
	{
		printf("ERRO listaCopia(): Uma das listas e vazia. Destino: %u Fonte: %u",ListaEhVazia(destino),ListaEhVazia(fonte));
		return 0;
	}
	if((ListaRetornaTamanho(destino)+ListaRetornaTamanho(fonte)) >= MAXLISTA)
	{
		printf("ERRO listaCopia(): O tamanho das listas é maior que o permitido. Destino: %zu Fonte: %zu\n",ListaRetornaTamanho(destino),ListaRetornaTamanho(fonte));
		return 0;
	}
	size_t itemAtual = 0;
	while(itemAtual != fonte->Fim - 1)
	{
		destino->itens[itemAtual] = fonte->itens[itemAtual];
		itemAtual++;
	}
	return 1;
}

uint8_t ListaConcatena(Lista *destino, Lista *fonte)
{
	if(ListaEhVazia(destino) == 1 || ListaEhVazia(fonte) == 1)
	{
		printf("ERRO ListaConcatena(): Uma das listas e vazia. Destino: %u Fonte: %u",ListaEhVazia(destino),ListaEhVazia(fonte));
		return 0;
	}
	if((ListaRetornaTamanho(destino)+ListaRetornaTamanho(fonte)*10000) >= MAXLISTA)
	{
		printf("ERRO ListaConcatena(): O tamanho das listas é maior que o permitido. Destino: %zu Fonte: %zu\n",ListaRetornaTamanho(destino),ListaRetornaTamanho(fonte));
		return 0;
	}
	size_t fonteSize = ListaRetornaTamanho(fonte);
	size_t alvoDestino = destino->Fim;
	size_t alvoFonte = fonte->Inicio;
	while(alvoFonte != fonte->Fim)
	{
		destino->itens[alvoDestino] = fonte->itens[alvoFonte];
		alvoFonte++;
		alvoDestino++;
	}
	destino->Fim += fonteSize + 1;
	return 1;
}

uint8_t ListaIntercala(Lista *resultado, Lista *lista1, Lista *lista2)
{
	if(ListaEhVazia(lista1) == 1 || ListaEhVazia(lista2) == 1)
	{
		printf("ERRO ListaIntercala(): Uma das listas e vazia. Destino: %u Fonte: %u",ListaEhVazia(lista1),ListaEhVazia(lista2));
		return 0;
	}
	if((ListaRetornaTamanho(lista1)+ListaRetornaTamanho(lista2)) >= MAXLISTA)
	{
		printf("ERRO ListaIntercala(): O tamanho das listas é maior que o permitido. Destino: %zu Fonte: %zu\n",ListaRetornaTamanho(lista1),ListaRetornaTamanho(lista2));
		return 0;
	}
	printf("alvo");

	size_t alvo;
	Lista *proxima;
	if(ListaRetornaTamanho(lista1) >= ListaRetornaTamanho(lista2))
	{
		alvo = lista2->Fim;
		proxima = lista1;
	}
	else
	{
		alvo = lista1->Fim;
		proxima = lista2;
	}
	size_t itemAtual = 0;
	while(itemAtual != alvo)
	{
		if(itemAtual%2 == 0)
			resultado->itens[itemAtual] = lista1->itens[itemAtual];
		else
			resultado->itens[itemAtual] = lista2->itens[itemAtual];
		itemAtual++;
	}
	printf("funcionou?%zu\n",proxima->Fim);
	alvo = proxima->Fim;
	while(itemAtual != alvo)
	{
		lista1->itens[itemAtual] = proxima->itens[itemAtual];
		itemAtual++;
	}

	resultado->Fim += ListaRetornaTamanho(lista1) + ListaRetornaTamanho(lista2) + 1;
	return 1;
}
