#include "SBB.h"
int main()
{
	node *tree;
	sbbCria(&tree);
	#define MAX 20
	struct timeval t;
	int vetor[MAX];
	int i, j, k, n;
	gettimeofday(&t,NULL);
	srand((unsigned int)t.tv_usec);
	/*Gera uma permutacao aleatoria de chaves entre 1 e MAX*/
	for(i = 0; i < MAX; i++) vetor[i] = i + 1;
	for(i = 0; i < MAX; i++)
	{
		k =  (int) (10.0*rand()/(RAND_MAX + 1.0));
		j =  (int) (10.0*rand()/(RAND_MAX + 1.0));
		n = vetor[k];
		vetor[k] = vetor[j];
		vetor[j] = n;
	}
	/*Empilha cada chave */
	for (i = 0; i < MAX; i++)
	{
		sbbInsere(&tree, vetor[i]);
		printf("Inseriu: %d \n", vetor[i]);
	}
  //
	// for (i = MAX; i > 12; i--)
	// {
	// 	sbbRetira(&tree, vetor[i]);
	// 	printf("Removeu: %d \n", vetor[i]);
	// }

	// sbbInsere(&tree, 5);
	// sbbInsere(&tree, 6);
	// sbbInsere(&tree, 4);
	// sbbRetira(&tree, 4);
	// sbbImprimeEmOrdem(&tree);
	// sbbImprimePosOrdem(&tree);
	// sbbImprimePreOrdem(&tree);
	// reg = 9;
	// sbbInsere(&tree, reg);
	printf("%d\n", sbbDFS(&tree));

	return 0;
}

void sbbTransformEE(node **no_atual)
{
	node *filho;
	filho = (*no_atual)->esq;
	(*no_atual)->esq = filho->dir;
	filho->dir = *no_atual;
	filho->angle_e = Vertical;
	(*no_atual)->angle_e = Vertical;
	*no_atual = filho;
}

void sbbTransformED(node **no_atual)
{
	node *filho, *neto;
	filho = (*no_atual)->esq;
	neto = filho->dir;
	filho->angle_d = Vertical;
	(*no_atual)->angle_e = Vertical;
	filho->dir = neto->esq;
	neto->esq = filho;
	(*no_atual)->esq = neto->dir;
	neto->dir = *no_atual;
	*no_atual = neto;
}

void sbbTransformDD(node **no_atual)
{
	node *filho;
	filho = (*no_atual)->dir;
	(*no_atual)->dir = filho->esq;
	filho->esq = *no_atual;
	filho->angle_d = Vertical;
	(*no_atual)->angle_d = Vertical;
	*no_atual = filho;
}

void sbbTransformDE(node **no_atual)
{
  // Seta filho e neto
	node *filho, *neto;
	filho = (*no_atual)->dir;
	neto = filho->esq;

  // Coloca tudo vertical
	filho->angle_e = Vertical;
	(*no_atual)->angle_d = Vertical;

	filho->esq = neto->dir;
	neto->dir = filho;
	(*no_atual)->dir = neto->esq;
	neto->esq = *no_atual;
	*no_atual = neto;
}

void sbbRetiraEsqCurto(node **no_atual, short *fim_retira)
{
	/* Folha esquerda retirada => arvore curta na altura esquerda */
	if ((*no_atual)->angle_e == Horizontal)
	{
		(*no_atual)->angle_e = Vertical;
		*fim_retira = true;
		return;
	}

	if ((*no_atual)->angle_d == Horizontal)
	{
		node *no_atual_dir;
		no_atual_dir = (*no_atual)->dir;
		(*no_atual)->dir = no_atual_dir->esq;
		no_atual_dir->esq = *no_atual;
		*no_atual = no_atual_dir;
		if ((*no_atual)->esq->dir->angle_e == Horizontal)
		{
			sbbTransformDE(&(*no_atual)->esq);
			(*no_atual)->angle_e = Horizontal;
		}
		else if ((*no_atual)->esq->dir->angle_d == Horizontal)
		{
			sbbTransformDD(&(*no_atual)->esq);
			(*no_atual)->angle_e = Horizontal;
		}
		*fim_retira = true;
		return;
	}
	(*no_atual)->angle_d = Horizontal;
	if ((*no_atual)->dir->angle_e == Horizontal)
	{
		sbbTransformDE(no_atual);
		*fim_retira = true;
		return;
	}

	if ((*no_atual)->dir->angle_d == Horizontal)
	{
		sbbTransformDD(no_atual);
		*fim_retira = true;
	}
}

void sbbRetiraDirCurto(node **no_atual, short *fim_retira)
{
	/* Folha direita retirada => arvore curta na altura direita */

  //Se a treta na subtree, se o direito dela for horizontal, só troca para vertical e ta tudo certo
	if ((*no_atual)->angle_d == Horizontal)
	{
		(*no_atual)->angle_d = Vertical;
		*fim_retira = true;
		return;
	}

	if ((*no_atual)->angle_e == Horizontal)
	{
		node *no_atual_esq;
		no_atual_esq = (*no_atual)->esq;
		(*no_atual)->esq = no_atual_esq->dir;
		no_atual_esq->dir = *no_atual;
		*no_atual = no_atual_esq;
		if ((*no_atual)->dir->esq->angle_d == Horizontal)
		{
			sbbTransformED(&(*no_atual)->dir);
			(*no_atual)->angle_d = Horizontal;
		}
		else if ((*no_atual)->dir->esq->angle_e == Horizontal)
		{
			sbbTransformEE(&(*no_atual)->dir);
			(*no_atual)->angle_d = Horizontal;
		}
		*fim_retira = true;
		return;
	}
	(*no_atual)->angle_e = Horizontal;
	if ((*no_atual)->esq->angle_d == Horizontal)
	{
		sbbTransformED(no_atual);
		*fim_retira = true;
		return;
	}

	if ((*no_atual)->esq->angle_e == Horizontal)
	{
		sbbTransformEE(no_atual);
		*fim_retira = true;
	}
}

void sbbRetiraAntecessor(node *q, node **r, short *fim_retira)
{
  // Muito semelhante ao antecessor. Só muda dentro dos ifs
	if ((*r)->dir != NULL)
	{
		sbbRetiraAntecessor(q, &(*r)->dir, fim_retira);
		if (!*fim_retira)
			sbbRetiraDirCurto(r, fim_retira);
		return;
	}
	q->item = (*r)->item;
	q = *r;
	*r = (*r)->esq;
	free(q);

  // Se a esquerda do antecessor não for nula, precisamos rodar o DirCurto para a esquerda dele.
  // Isso será feito depois que desempilhar essa chamada atual
	if (*r != NULL)
		*fim_retira = true;
}

// void sbbRetiraAux(int item, node **no_atual, short *fim_retira)
void sbbRetiraAux(node **no_atual, int item, short *fim_retira)
{
	// No é nulo. Percorremos toda uma ramificação da árvore e não achamos nada.
	if (*no_atual == NULL)
	{
		printf("Chave não está na árvore!\n");
		*fim_retira = true;
		return;
	}

	// Nó é menor que a chave, vamos para a esquerda
	if (item < (*no_atual)->item)
	{
		sbbRetiraAux(&(*no_atual)->esq, item, fim_retira);
		if (!*fim_retira)
			sbbRetiraEsqCurto(no_atual, fim_retira);
		return;
	}

	// Nó é maior que a chave, vamos para a direita
	if (item > (*no_atual)->item)
	{
		sbbRetiraAux(&(*no_atual)->dir, item, fim_retira);
		if (!*fim_retira)
			sbbRetiraDirCurto(no_atual, fim_retira);
		return;
	}

	// Achamos o nó
	*fim_retira = false;
	node *aux = *no_atual;

	// Se não houver nada à direita do nó, é só trocar o nó atual com seu esquerdo e finalizar.
	// As funções serão desempilhadas sbbRetira sairá
	if (aux->dir == NULL)
	{
		*no_atual = aux->esq;
		free(aux);
		if (*no_atual != NULL)
			*fim_retira = true;
		return;
	}

	// Se não houver nada à esqurda do nó, é só trocar o nó atual com seu esquerdo e finalizar.
	// As funções serão desempilhadas sbbRetira sairá
	if (aux->esq == NULL)
	{
		*no_atual = aux->dir;
			free(aux);
		if (*no_atual != NULL)
			*fim_retira = true;
		return;
	}

  // Se o nó possuir dois filhos. Aí complica.
  // Chamamos o antecessor para substituir o nó atual com seu antecessor certo
	sbbRetiraAntecessor(aux, &aux->esq, fim_retira);

  // Aqui nós fizemos uma mudança então precisamos chamar EsqCurto para o nó atual.
  // Já que a esquerda do nó atual ficou menor.
	if (!*fim_retira)
		sbbRetiraEsqCurto(no_atual, fim_retira);
			/* Encontrou chave */
}

void sbbRetira(node **no_atual, int item)
{
	short fim_retira;
	sbbRetiraAux(no_atual, item, &fim_retira);
}

void sbbCria(node **alvo)
{
	*alvo = NULL;
}

void sbbInsereAux(node **no_atual, nodeAngle *no_ant, short *fim_insercao, int item)
{
	if (*no_atual == NULL)
	{
		*no_atual = (node *) malloc(sizeof(node));
		*no_ant = Horizontal;
		(*no_atual)->item = item;
		(*no_atual)->angle_e = Vertical;
		(*no_atual)->angle_d = Vertical;
		(*no_atual)->esq = NULL;
		(*no_atual)->dir = NULL;
		*fim_insercao = false;
		return;
	}

	if (item < (*no_atual)->item)
	{
		sbbInsereAux(&(*no_atual)->esq, &(*no_atual)->angle_e, fim_insercao, item);
		if (*fim_insercao)
			return;
		if ((*no_atual)->angle_e != Horizontal)
		{
			*fim_insercao = true;
			return;
		}

		if ((*no_atual)->esq->angle_e == Horizontal)
		{
			sbbTransformEE(no_atual);
			*no_ant = Horizontal;
			return;
		}
		if ((*no_atual)->esq->angle_d == Horizontal)
		{
			sbbTransformED(no_atual);
			*no_ant = Horizontal;
		}
		return;
	}

	if (item <= (*no_atual)->item)
	{
		printf("sbbInsereAux() Erro: Chave já está na árvore.\n");
		*fim_insercao = true;
		return;
	}

	sbbInsereAux(&(*no_atual)->dir, &(*no_atual)->angle_d, fim_insercao, item);
	if (*fim_insercao)
		return;
	if ((*no_atual)->angle_d != Horizontal)
	{
		*fim_insercao = true;
		return;
	}

	if ((*no_atual)->dir->angle_d == Horizontal)
	{
		sbbTransformDD(no_atual);
		*no_ant = Horizontal;
		return;
	}

	if ((*no_atual)->dir->angle_e == Horizontal)
	{
		sbbTransformDE(no_atual);
		*no_ant = Horizontal;
	}
}

void sbbInsere(node **no_atual, int item)
{
	short fim_insercao;
	nodeAngle no_ant;
	sbbInsereAux(no_atual, &no_ant, &fim_insercao, item);
}

void sbbImprimeEmOrdemAux(node **alvo)
{
	if((*alvo)->esq != NULL)
		sbbImprimeEmOrdemAux((node **)&(*alvo)->esq);
	printf("%d ",(*alvo)->item);
	if((*alvo)->dir != NULL)
		sbbImprimeEmOrdemAux((node **)&(*alvo)->dir);
}

void sbbImprimeEmOrdem(node **alvo)
{
	if((*alvo) == NULL)
	{
		printf("sbbImprimeEmOrdem(): Árvore vazia!\n");
		return;
	}
	sbbImprimeEmOrdemAux(alvo);
	printf("\n");
}

void sbbImprimePreOrdemAux(node **alvo)
{
	printf("%d ",(*alvo)->item);
	if((*alvo)->esq != NULL)
		sbbImprimePreOrdemAux((node **)&(*alvo)->esq);
	if((*alvo)->dir != NULL)
		sbbImprimePreOrdemAux((node **)&(*alvo)->dir);
}

void sbbImprimePreOrdem(node **alvo)
{
	if((*alvo) == NULL)
	{
		printf("sbbImprimeEmOrdem(): Árvore vazia!\n");
		return;
	}
	sbbImprimePreOrdemAux(alvo);

	printf("\n");
}

void sbbAuxImprimePosOrdem(node **alvo)
{
	if((*alvo)->esq != NULL)
		sbbAuxImprimePosOrdem((node **)&(*alvo)->esq);
	if((*alvo)->dir != NULL)
		sbbAuxImprimePosOrdem((node **)&(*alvo)->dir);

	printf("%d ",(*alvo)->item);
}

void sbbImprimePosOrdem(node **alvo)
{
	if((*alvo) == NULL)
	{
		printf("sbbImprimeEmOrdem(): Árvore vazia!\n");
		return;
	}
	sbbAuxImprimePosOrdem(alvo);
	printf("\n");
}

void sbbPesquisa(node **alvo, int item)
{
	if(*alvo == NULL)
	{
		printf("sbbPesquisa(): %d não encontrado!\n",item);
		return;
	}

	if((*alvo)->item == item)
	{
		printf("sbbPesquisa(): %d encontrado!\n",item);
		return;
	}

	if((*alvo)->item > item)
		sbbPesquisa((node **)&(*alvo)->esq,item);

	else if((*alvo)->item < item)
		sbbPesquisa((node **)&(*alvo)->dir,item);
}

void sbbImprimeNo(node **alvo)
{
	if(*alvo == NULL)
		puts("sbbImprimeNo(): Nó é nulo!");
	else
		printf("%d\n",(*alvo)->item);
}
int sbbDFS(node **alvo)
{
	if((*alvo) == NULL)
		return -1;

	return 1 + sbbDFS(&(*alvo)->dir);

}
