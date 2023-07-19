#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>

#define MAX_ITEM 50

typedef enum
{
  Interno, Externo
} kindNode;

typedef struct node node;
typedef struct node
{
  kindNode kind;
  union
  {
    struct
    {
      uint index;
      char letra;
      node *esq, *dir;
    } insideNode;
    char item[MAX_ITEM];
  } unionNode;
} node;

short patriciaEhExterno(node *novo_no);
bool patriciaDirecao(uint *index, char *item, char *pivo);
node *patriciaCriaNoInterno(int index, char letra, node **esq,  node **dir);
node *patriciaCriaNoExterno(char *item);
void patriciaPesquisa(char *item, node *no_atual);
node *patriciaInsereEntre(char *item, node **no_atual, uint index);
node *patriciaInsere(char *item, node **no_atual);
