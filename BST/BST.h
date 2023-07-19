#include "stdstd.h"
#include "FilaEncadeada/filaEncadeada.h"

typedef struct node node;
typedef struct node
{
	int reg;
	node *esq;
	node *dir;
} node;

void bstImprimeNo(node **alvo);
void bstImprimePosOrdem(node **alvo);
void bstImprimePreOrdem(node **alvo);
void bstCria(node **node);
void bstInsere(node **alvo, int reg);
void bstImprimeEmOrdem(node **alvo);
void bstImprimeNo(node **alvo);
void bstBFS(node **alvo);
int bstDFS(node **alvo);
void bstPesquisa(node **alvo, int reg);
void bstRetira(node **alvo, int reg);
void bstRetiraAntecessor(node **alvo,node **antecessor);
