#include "Patricia.h"

bool patriciaDirecao(uint *index, char *item, char *pivo)
{
	return (item[*index] == *pivo);
}

short patriciaEhExterno(node *novo_no)
{
	/* Verifica se novo_no^ e nodo externo */
	return (novo_no->kind == Externo);
}

node *patriciaCriaNoInterno(int index, char letra, node **esq,  node **dir)
{
	node *no_atual;
	no_atual = (node *) malloc(sizeof(node));
	no_atual->kind = Interno;
	no_atual->unionNode.insideNode.esq = *esq;
	no_atual->unionNode.insideNode.dir = *dir;
	no_atual->unionNode.insideNode.index = index;
	no_atual->unionNode.insideNode.letra = letra;
	return no_atual;
}

node *patriciaCriaNoExterno(char *item)
{
	node *no_atual;
	no_atual = (node *) malloc(sizeof(node));
	no_atual->kind = Externo;
	strcpy(no_atual->unionNode.item,item);
	return no_atual;
}

void patriciaPesquisa(char *item, node *no_atual)
{
	if (patriciaEhExterno(no_atual))
	{
		if (strcmp(item, no_atual->unionNode.item))
			printf("patriciaPesquisa(): Elemento encontrado! \n");
		else
			printf("patriciaPesquisa(): Elemento não encontrado !\n");
		return;
	}
	if (!patriciaDirecao(&(no_atual->unionNode.insideNode.index), item, &(no_atual->unionNode.insideNode.letra)))
		patriciaPesquisa(item, no_atual->unionNode.insideNode.esq);
	else
		patriciaPesquisa(item, no_atual->unionNode.insideNode.dir);
}

node *patriciaInsereEntre(char *item, node **no_atual, uint index)
{
	node *novo_no;
	if (patriciaEhExterno(*no_atual) || index < (*no_atual)->unionNode.insideNode.index)
	{
		/* cria um novo no externo */
		novo_no = patriciaCriaNoExterno(item);
		if (patriciaDirecao(&index, item, &(*no_atual)->unionNode.insideNode.letra))
			return (patriciaCriaNoInterno(index,(*no_atual)->unionNode.insideNode.letra, no_atual, &novo_no));
		else
			return (patriciaCriaNoInterno(index,(*no_atual)->unionNode.insideNode.letra, &novo_no, no_atual));
	}
	else
	{
		if (patriciaDirecao(&(*no_atual)->unionNode.insideNode.index, item, &(*no_atual)->unionNode.insideNode.letra))
			(*no_atual)->unionNode.insideNode.dir = patriciaInsereEntre(item,&(*no_atual)->unionNode.insideNode.dir,index);
		else
			(*no_atual)->unionNode.insideNode.esq = patriciaInsereEntre(item,&(*no_atual)->unionNode.insideNode.esq,index);
		return (*no_atual);
	}
}

node *patriciaInsere(char *item, node **no_atual)
{
	node *novo_no;
	uint index;
	if (*no_atual == NULL)
		return (patriciaCriaNoExterno(item));
	else
	{
		novo_no = *no_atual;
		while (!patriciaEhExterno(novo_no))
			{
				if (patriciaDirecao(&(novo_no->unionNode.insideNode.index), item, &(novo_no->unionNode.insideNode.letra)))
					novo_no = novo_no->unionNode.insideNode.dir;
				else
					novo_no = novo_no->unionNode.insideNode.esq;
			}
		/* acha o primeiro bit diferente */
		index = 1;
		// while ((index <= D) & (Bit((int)index, item) == Bit((int)index, novo_no->unionNode.Chave)))
			// index++;
		// if (index > D)
		{
			printf("patriciaInsere() Erro: chave ja esta na arvore\n");
			return (*no_atual);
		}
		// else
			return (patriciaInsereEntre(item, no_atual, index));
	}
}
