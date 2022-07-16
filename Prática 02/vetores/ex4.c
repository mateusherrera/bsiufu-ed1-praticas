#include <stdio.h>

int main(void)
{
	int vet[6];
	
	printf("<< Listando um vetor de números pares >>\n");
	for(int i = 0; i < 6; i++)
	{
		printf("Entre com o número %d: ", i + 1);
		scanf("%d", &vet[i]);
		while(vet[i] % 2 != 0)
		{
			printf("Erro: Valor inválido\n");
			printf("Entre com o número %d: ", i + 1);
			scanf("%d", &vet[i]);
		}//while
	}//for
	
	printf("Os números pares digitados foram: ");
	for(int i = 0; i < 6; i++)
		printf("%d ", vet[i]);
	printf("\n");
	
	return 0;
}//main