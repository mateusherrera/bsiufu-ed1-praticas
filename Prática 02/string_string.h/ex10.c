#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char nome[20];
	int pos, aux = 0;
	
	printf("Políndromo\n");
	printf("Digite uma palavra: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	pos = strcspn(nome, "\0") - 1;
	
	for(int i = 0; i != pos; i++, pos--)
	{
		if(nome[i] != nome[pos])
		{
			aux = 1;
			i = pos;
			i--;
			pos++;
		}//if
	}//for
	if(aux == 0)
	{
		printf("%s é políndromo!\n", nome);
	}else{
		printf("%s não é políndromo!\n", nome);
	}//if else
	
	return 0;
}//main