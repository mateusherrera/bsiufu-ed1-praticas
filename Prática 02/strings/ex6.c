#include <stdio.h>

int main(void)
{
	char nome[40];
	char c;
	int pos = 0;
	
	setbuf(stdin,NULL);
	
	printf("<< Vetor de Char >>\n");
	printf("Digite o nome e o sobrenome: ");
	c = getchar();
	for(int i = 0; c != '\n'; i++)
	{
		nome[i] = c;
		c = getchar();
	}//for
	
	printf("Nome: ");
	while(nome[pos] != ' ')
	{
		printf("%c", nome[pos]);
		pos++;
	}//while
	printf("\n");
	pos++;
	printf("Sobrenome: ");
	while(nome[pos] != '\0')
	{
		printf("%c", nome[pos]);
		pos++;
	}//while
	printf("\n");
	
	return 0;
}//main