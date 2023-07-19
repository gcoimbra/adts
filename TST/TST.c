#include <stdlib.h>
#include <stdio.h>
#include "TST.h"


node *novoNo(char item)
{
		node *novo_no = (node*)malloc(sizeof(node));
		novo_no->item = item;
		novo_no->fim_string = 0;
		novo_no->dir = NULL;
		novo_no->mid = NULL;
		novo_no->esq = NULL;

		return novo_no;
}

void tstInsere(node **node,char *palavra)
{
		//Caso Base
		if(!(*node))
				*node = novoNo(*palavra);

		//Se o caracter atual da palavra for menor do que o caracter da node
		//entao inserimos essa palavra na subarvore a esquerda da node
		if((*palavra) < (*node)->item)
				tstInsere(&(*node)->esq,palavra);

		//Se o caracter atual da palavra for maior do que o caracter da node
		//entao inserimos essa palavra na subarvore a direita da node
		else if((*palavra) > (*node)->item)
				tstInsere(&(*node)->dir,palavra);

		//Se o caracter atual da palavra é o mesmo caracter da node
		else
		{
				if(*(palavra+1))
						tstInsere(&(*node)->mid,palavra+1);
				else
						(*node)->fim_string = 1;
		}
}

//Funçao auxiliar que percorre a arvore de forma recursiva
void tstPercorreAux(node *node, char *palavra, int profundidade)
{
		if(node)
		{
			//primeiro percorre a subarvore a esquerda
			tstPercorreAux(node->esq,palavra,profundidade);

			//Guarda o caracter deste nó
			palavra[profundidade] = node->item;

			if(node->fim_string)
			{
					palavra[profundidade+1] = '\0';
					printf("%s\n",palavra);
			}

			//percorre a subarvore do meio
			tstPercorreAux(node->mid,palavra,profundidade+1);
			//Finalmente percorre a subarvore da direta
			tstPercorreAux(node->dir,palavra,profundidade);
		}
}

void tstPercorre(node *node)
{
		char palavra[MAX_PALAVRA];
		tstPercorreAux(node,palavra,0);
}

int tstBusca(node *node,char *palavra)
{
		if(!node)
				return  0;

		if(*palavra < (node)->item)
				return tstBusca(node->esq,palavra);
		else if (*palavra > (node)->item)
				return tstBusca(node->dir,palavra);
		else
		{
				if(*(palavra+1) == 0)
						return node->fim_string;

				return tstBusca(node->mid,palavra+1);

		}
}
