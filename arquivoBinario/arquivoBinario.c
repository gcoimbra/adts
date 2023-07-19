#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *arquivo = fopen("text.txt","r+b");
	if(arquivo == NULL)
	{
		printf("main(): não dá para abrir arquivo\n");
		return 0;
	}
	char string[] = "Dalila eu te amo";

	fwrite(string,strlen(string),sizeof(char),arquivo);
	int a = 22222;
	fscanf(arquivo,"%d",&a);

	fseek(arquivo,3,SEEK_SET);
	char pega[5];
	fgets(pega,5,arquivo);
	puts(pega);


	fclose(arquivo);
	return 0;
}
