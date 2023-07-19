#include "BST.h"
#include <sys/time.h>

int main()
{
	node *tree;
	bstCria(&tree);
	// #define MAX 20
	// struct timeval t;
	// int vetor[MAX];
	// int i, j, k, n;
	// gettimeofday(&t,NULL);
	// srand((unsigned int)t.tv_usec);
	// /*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
	// for(i = 0; i < MAX; i++) vetor[i] = i + 1;
	// for(i = 0; i < MAX; i++)
	// {
	// 	k =  (int) (10.0*rand()/(RAND_MAX + 1.0));
	// 	j =  (int) (10.0*rand()/(RAND_MAX + 1.0));
	// 	n = vetor[k];
	// 	vetor[k] = vetor[j];
	// 	vetor[j] = n;
	// }
	// /*Empilha cada chave */
	// for (i = 0; i < MAX; i++)
	// {
	// 	bstInsere(&tree, vetor[i]);
	// 	printf("Inseriu: %d \n", vetor[i]);
	// }

	bstInsere(&tree, 100);
	bstInsere(&tree, 99);
	bstInsere(&tree, 10);
	bstInsere(&tree, 50);
	bstInsere(&tree, 25);
	bstInsere(&tree, 12);
	bstInsere(&tree, 6);



	bstImprimeEmOrdem(&tree);

	bstRetira(&tree,6);
	bstImprimeEmOrdem(&tree);

	// reg = 9;
	// bstInsere(&tree, reg);

	return 0;
}

void bstCria(node **alvo)
{
	*alvo = NULL;
}

void bstInsere(node **alvo, int reg)
{
	if(*alvo == NULL)
	{
		node *novo = (node *) malloc(sizeof(node));
		novo->esq = NULL;
		novo->dir = NULL;
		novo->reg = reg;
		*alvo = novo;
	}
	else if((*alvo)->reg > reg)
		bstInsere(&(*alvo)->esq, reg);

	else if((*alvo)->reg <= reg)
		bstInsere(&(*alvo)->dir, reg);
}

void bstImprimeEmOrdemR(node **alvo)
{
	if((*alvo)->esq != NULL)
		bstImprimeEmOrdem(&(*alvo)->esq);
	printf("%d ",(*alvo)->reg);
	if((*alvo)->dir != NULL)
		bstImprimeEmOrdem(&(*alvo)->dir);
}

void bstImprimeEmOrdem(node **alvo)
{
	if((*alvo) == NULL)
	{
		printf("Arvore vazia\n");
		return;
	}
	bstImprimeEmOrdemR(alvo);

	printf("\n");
}


void bstImprimePreOrdemR(node **alvo)
{

	printf("%d ",(*alvo)->reg);
	if((*alvo)->esq != NULL)
		bstImprimeEmOrdem(&(*alvo)->esq);
	if((*alvo)->dir != NULL)
		bstImprimeEmOrdem(&(*alvo)->dir);
}

void bstImprimePreOrdem(node **alvo)
{
	if((*alvo) == NULL)
	{
		printf("Arvore vazia\n");
		return;
	}
	bstImprimeEmOrdemR(alvo);

	printf("\n");
}

void bstImprimePosOrdemR(node **alvo)
{
	if((*alvo)->esq != NULL)
		bstImprimeEmOrdem((node* *)&(*alvo)->esq);
	if((*alvo)->dir != NULL)
	bstImprimeEmOrdem(&(*alvo)->dir);

	printf("%d ",(*alvo)->reg);
}

void bstImprimePosOrdem(node **alvo)
{
	if((*alvo) == NULL)
	{
		printf("Arvore vazia\n");
		return;
	}
	bstImprimePosOrdemR(alvo);
	printf("\n");
}

void bstPesquisa(node **alvo, int reg)
{
	if(*alvo == NULL)
	{
		printf("bstPesquisa(): %d não encontrado!",reg);
		return;
	}
	if((*alvo)->reg == reg)
	{
		printf("bstPesquisa(): %d encontrado!\n",reg);
		return;
	}
	if((*alvo)->reg > reg)
		bstPesquisa(&(*alvo)->esq,reg);

	else if((*alvo)->reg < reg)
		bstPesquisa(&(*alvo)->dir,reg);
}


int bstDFS(node **alvo)
{
	if((*alvo) == NULL)
		return -1;
	if(bstDFS(&(*alvo)->esq) >= bstDFS(&(*alvo)->dir))
		return 1 + bstDFS(&(*alvo)->esq);
	return 1 + bstDFS(&(*alvo)->dir);
}

void bstImprimeNo(node **alvo)
{
	printf("%d\n",(*alvo)->reg);
}

void bstBFS(node **alvo)
{
	Fila fila;
	criaVazia(&fila);

	// Coloca raiz na fila
	FilaCelulaItem item;
	item.node = *alvo;
	enfileira(&item,&fila);

	// 			 10
	//  4					  14
	// 1 5			11
	// 					  12

	while(!vazia(&fila))
	{
		FilaCelulaItem aux;
		desenfileira(&fila,&aux);
		bstImprimeNo(&aux.node);
		if(aux.node->esq != NULL)
		{
			item.node = aux.node->esq;
			enfileira(&item,&fila);
		}
		if(aux.node->dir != NULL)
		{
			item.node = aux.node->dir;
			enfileira(&item,&fila);
		}
	}
}

void bstRetiraAntecessor(node **alvo,node **antecessor)
{
	if((*antecessor)->esq != NULL)
		bstRetiraAntecessor(alvo,antecessor);
	else
	{
		(*alvo)->reg = (*antecessor)->reg;
		node *aux = *antecessor;
		*antecessor = (*antecessor)->esq;
		free(aux);
	}
}

void bstRetira(node **alvo, int reg)
{
	if(*alvo == NULL)
		printf("bstRetira(): Não encontrado !\n");
	else if((*alvo)->reg > reg)
		bstRetira(&(*alvo)->esq, reg);
	else if((*alvo)->reg < reg)
		bstRetira(&(*alvo)->dir, reg);

  // Se não é maior, nem menor, dos dois, é igual
	else
	{
		// Se filho esquerdo é nulo e direito não
		if((*alvo)->esq == NULL && (*alvo)->dir != NULL)
		{
			puts("bstRetira(): Direito não nulo...");

			node *aux = (*alvo)->dir;
			free(*alvo);
			*alvo = aux;
		}

		// Filho direito nulo e esquerdo não
		else if((*alvo)->esq != NULL && (*alvo)->dir == NULL)
		{
			puts("bstRetira(): Esquerdo não nulo...");
			free(*alvo);
			*alvo = NULL;
		}

		// Se os dois são nulos
		else if((*alvo)->esq != NULL && (*alvo)->dir != NULL)
		{
			puts("bstRetira(): Nenhum dos dois nulos..");
			bstRetiraAntecessor(alvo,&(*alvo)->esq);
		}

		// Dois filhos são nulos
		else
		{
			puts("bstRetira(): Filhos nulos...");
			free(*alvo);
			*alvo = NULL;
		}
	}
}
