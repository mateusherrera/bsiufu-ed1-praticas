#include <stdio.h>

void DesenhaLinha(int x)
{
	for(int i = 0; i < x; i++)
		printf("=");
	printf("\n");
	
	return;
}//DesenhaLinha

int main(void)
{
	int x;
	
	do{
		printf("Quantos '=' deseja imprimir, digite 0 para fechar o programa: ");
		scanf("%d", &x);
		DesenhaLinha(x);
	}while(x);
	
	return 0;
}//main