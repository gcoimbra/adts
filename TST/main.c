/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "TST.h"

void menu()
{
	 Node *raiz = NULL;
	 int opcao = 1;
	 char palavra[MAX_PALAVRA], palavra2[MAX_PALAVRA];

	while(opcao != 0 )
	{
		printf("1 - Inserir | 2 - Percorrer Arvore | 3 - Buscar Palavra | 0 - Sair\n");
		scanf("%d",&opcao);

		switch(opcao)
		{
			case 1:
				printf("Digite a palavra que deseja inserir\n");
				scanf("%s",palavra);

				tstInsere(&raiz,palavra);
				break;

			case 2:
				printf("Percorrendo a arvore..\n");
				tstPercorre(raiz);
				break;

			case 3:
				printf("Digite a palavra que voce deseja buscar\n");
				scanf("%s",palavra2);

				if(tstBusca(raiz,palavra2))
						printf("A palavra '%s' foi encontrada !\n",palavra2);
				 else
						printf("A palavra '%s' nao foi encontrada !\n",palavra2);
				break;
		}
	}
}
int main()
{

		menu();
		return (EXIT_SUCCESS);
}
