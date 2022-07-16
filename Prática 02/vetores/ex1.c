#include <stdio.h>

int main(void)
{
	int vet[6];
	
	printf("<< Listando um vetor >>\n");
	printf("Entre com o número 1: ");
	scanf("%d", &vet[0]);
	printf("Entre com o número 2: ");
	scanf("%d", &vet[1]);
	printf("Entre com o número 3: ");
	scanf("%d", &vet[2]);
	printf("Entre com o número 4: ");
	scanf("%d", &vet[3]);
	printf("Entre com o número 5: ");
	scanf("%d", &vet[4]);
	printf("Entre com o número 6: ");
	scanf("%d", &vet[5]);
	
	printf("Os valores lidos são: %d %d %d %d %d %d\n", vet[0],vet[1],vet[2],vet[3],vet[4],vet[5]);
	
	return 0;
}//main