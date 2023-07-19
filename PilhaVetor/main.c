#include "stdstd.h"
#define MAX_STR 500
#define MAX_EXPRESSION 100
int main(void)
{
	Pilha pilha;
	pilhaCria(&pilha);
	char expression[MAX_EXPRESSION];
	fgets(expression,MAX_EXPRESSION,stdin);

	pilhaItem item1;
	item1.valor = '(';
	for (int i = 0; i < strlen(expression); ++i)
	{
		if(expression[i] == '(')
			pilhaEmpilha(&pilha,&item1);
		else if(expression[i] == ')')
			pilhaDesempilha(&pilha,NULL);
	}
	printf("%zu\n",pilhaQuantidade(&pilha));
	return 1;
}

int reverseStr(void)
{
	Pilha pilha;
	pilhaCria(&pilha);


	char str[MAX_STR];
	scanf("%s",str);
	pilhaItem item;

	for (int i = 0; i < strlen(str); ++i)
	{
		item.valor = str[i];
		pilhaEmpilha(&pilha,&item);
	}

	for (int i = 0; i < strlen(str); ++i)
	{
		pilhaDesempilha(&pilha,&item);
		printf("%c\n",item.valor );
	}
	return 0;
}