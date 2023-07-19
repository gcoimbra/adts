#include <sys/time.h>
#include "stdstd.h"

typedef enum
{
	Vertical, Horizontal
} nodeAngle;
typedef struct node node;

typedef struct node
{
	int item;
	node *esq, *dir;
	nodeAngle angle_e, angle_d;
} node;

void sbbCria(node **node);
void sbbInsere(node **no_atual, int item);
void sbbImprimeEmOrdem(node **alvo);
void sbbImprimePosOrdem(node **alvo);
void sbbPesquisa(node **alvo, int reg);
void sbbImprimePreOrdem(node **alvo);
void sbbImprimeNo(node **alvo);
int sbbDFS(node **alvo);
void sbbRetira(node **alvo, int reg);
