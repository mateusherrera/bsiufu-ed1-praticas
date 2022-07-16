#include <stdio.h>

int main(void)
{
	int vet[6];
	
	printf("<< Listando um vetor >>\n");
	for(int i = 0; i < 6; i++)
	{
		printf("Entre com o número %d: ", i + 1);
		scanf("%d", &vet[i]);
	}//for
	
	printf("Os valores lidos são: ");
	for(int i = 0; i < 6; i++)
		printf("%d ", vet[i]);
	printf("\n");
	
	return 0;
}//main