#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char nome[50];
	
	printf("<< Separa letras >>\n");
	printf("Digite o nome: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	for(int i = 0; i < 50 && nome[i] != '\0'; i++)
		printf("%dª Letra: %c\n", i + 1, nome[i]);
	
	return 0;
}//main