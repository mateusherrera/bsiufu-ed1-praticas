#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char nome[50];
	int pos;
	
	printf("<< Invertido >>\n");
	printf("Digite a String: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	printf("Saída invertida: ");
	pos = strcspn(nome, "\0");
	for(; pos >= 0; pos--)
		printf("%c", nome[pos]);
	printf("\n");
	
	return 0;
}//main