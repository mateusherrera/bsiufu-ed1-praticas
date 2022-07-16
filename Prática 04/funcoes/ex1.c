#include <stdio.h>

int DesenhaLinha(int x)
{
	printf("==========\n");
	
	return x;
}//DesenhaLinha

int main(void)
{
	int x = 1;
	
	while(DesenhaLinha(x))
	{
		printf("Digite 1 para imprimir uma nova linha e 0 para fechar o programa: ");
		scanf("%d", &x);
	}
	
	return 0;
}//main