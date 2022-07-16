#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char nome1[50];
	char nome2[50];
	
	printf("<< Compara nomes >>\n");
	printf("Digite o nome 1: ");
	fgets(nome1, sizeof(nome1), stdin);
	nome1[strcspn(nome1, "\n")] = '\0';
	
	printf("Digite o nome 2: ");
	fgets(nome2, sizeof(nome2), stdin);
	nome2[strcspn(nome2, "\n")] = '\0';
	
	for(int i = 0; i < 50 && nome1[i] != '\0' && nome2[i] != '\0'; i++)
	{
		if(islower(nome1[i])) nome1[i] = toupper(nome1[i]);
		if(islower(nome2[i])) nome2[i] = toupper(nome2[i]);
	}//for
	
	if(strcmp(nome1, nome2) == 0)
	{
		printf("Os nomes digitados são iguais\n");
	}else{
		printf("Os nomes digitados são diferentes\n");
	}//if else
	
	return 0;
}//main