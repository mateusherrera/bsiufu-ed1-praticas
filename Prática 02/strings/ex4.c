#include <stdio.h>

int main(void)
{
	char nome1[50];
	char nome2[50];
	char c;
	int aux = 0;
	
	setbuf(stdin,NULL);
	
	printf("<< Compara nomes >>");
	printf("Digite o nome 1: ");
	c = getchar();
	for(int i = 0; c != '\n'; i++)
	{
		nome1[i] = c;
		c = getchar();
	}//for
	c = '\0';
	
	printf("Digite o nome 2: ");
	c = getchar();
	for(int i = 0; c != '\n'; i++)
	{
		nome2[i] = c;
		c = getchar();
	}//for
	
	for(int i = 0; i < 50 && nome1[i] != '\0' && nome2[i] != '\0';  i++)
	{
		if(nome1[i] != nome2[i])
		{
			aux = 1;
			i = 50;
		}//if
	}//for
	if(aux == 0)
	{
		printf("Os nomes digitados são iguais\n");
	}else{
		printf("Os nomes digitados são diferentes\n");
	}//if else
	
	return 0;
}//main