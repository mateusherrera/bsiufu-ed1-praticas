#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char nome[50];
	
	setbuf(stdin, NULL);
	printf("<< Vetor de Char >>\n");
	printf("Digite um nome: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	printf("O nome digitado é: %s\n", nome);
	
	return 0;
}//main