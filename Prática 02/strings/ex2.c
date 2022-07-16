#include <stdio.h>

int main(void)
{
	char nome[50];
	char c;
	int pos = 0;
	
	setbuf(stdin, NULL);
	
	printf("<< Vetor de Char >>\n");
	printf("Digite um nome: ");
	c = getchar();
	while(c != '\n')
	{
		nome[pos] = c;
		pos++;
		c = getchar();
	}//while
	
	printf("O nome digitado é: ");
	for(int i = 0; i < pos; i++)
		printf("%c", nome[i]);
	printf("\n");
	
	return 0;
}//main