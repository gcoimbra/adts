#include <stdio.h>
#include <stdlib.h>

#include "HashClosed.h"

int main()
{
	hashClosed tabela;
	hashClosedCria(&tabela);
	char string[] = "olaa";
	hashClosedInsere(&tabela,string);
	hashClosedPesquisa(&tabela,string);

	strcpy(string,"asd12ee");
	for (size_t i = 0; i < 10; i++) {
		string[i%10] = i%200;
		hashClosedInsere(&tabela,string);
		hashClosedPesquisa(&tabela,string);
	}
}
