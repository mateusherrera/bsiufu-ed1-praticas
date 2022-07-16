#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char nome[50];
	
	printf("<< Sem Vogais >>\n");
	printf("Digite a String: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	printf("Saída sem vogais: ");
	for(int i = 0; i < 50 && nome[i] != '\0'; i++)
	{
		if(nome[i] != 'a' && nome[i] != 'e' && nome[i] != 'i' && nome[i] != 'o' && nome[i] != 'u' && nome[i] != 'A' && nome[i] != 'E' && nome[i] != 'I' && nome[i] != 'O' && nome[i] != 'U')
		{
			printf("%c", nome[i]);
		}//if
	}//for
	printf("\n");
	
	return 0;
}//main