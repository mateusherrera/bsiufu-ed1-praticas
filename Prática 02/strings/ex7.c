#include <stdio.h>

int main(void)
{
	char nome[50];
	char c;
	
	setbuf(stdin, NULL);
	
	printf("<< Vetor de Char >>\n");
	printf("Digite um nome: ");
	c = getchar();
	for(int i = 0; c != '\n'; i++)
	{
		nome[i] = c;
		c = getchar();
	}//while
	
	printf("O nome digitado é: %s\n", nome);
	
	return 0;
}//main
// O programa funcionará caso, no mínimo, o último char do vetor não seja ocupado e permaneça '\0'.