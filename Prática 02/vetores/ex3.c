#include <stdio.h>

int main(void)
{
	int vet[6];
	
	printf("<< Listando um vetor em ordem Inversa >>\n");
	for(int i = 0; i < 6; i++)
	{
		printf("Entre com o número %d: ", i + 1);
		scanf("%d", &vet[i]);
	}//for
	
	printf("A ordem inversa dos números é: ");
	for(int i = 5; i >= 0; i--)
		printf("%d ", vet[i]);
	printf("\n");
	
	return 0;
}//main