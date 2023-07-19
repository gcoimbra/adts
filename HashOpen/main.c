#include <stdio.h>
#include <stdlib.h>

#include "HashOpen.h"

int main()
{
	hashOpen tabela;
	hashOpenCria(&tabela);
	char string[200] = "AAAAAAAAAAAAAAAAAAAA";
	hashOpenInsere(&tabela,string);
	hashOpenPesquisa(&tabela,string);

	#define MAX 11
	for (size_t i = 0; i < MAX; i++) {
		string[i] = 'a';
		hashOpenInsere(&tabela,string);
		hashOpenPesquisa(&tabela,string);
	}

}
