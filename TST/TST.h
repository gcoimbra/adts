#define MAX_PALAVRA 50

typedef struct node node;
typedef struct node
{
		char item;

		//verdadeiro caso a letra seja a ultima letra de uma das palavras
		unsigned int fim_string: 1;

		struct node *esq;
		struct node *mid;
		struct node *dir;
} node;

node *novoNo(char item);
void tstInsere(node **node, char *palavra);
void tstPercorreAux(node *node, char *buffer, int profundidade);
void tstPercorre(node *node);
int tstBusca(node *node, char *palavra);
