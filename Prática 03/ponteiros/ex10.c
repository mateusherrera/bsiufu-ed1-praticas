#include <stdio.h>

int main(void)
{
	int vet[10];
	
	for(int i = 0; i < 10; i++)
	{
		printf("Digite o inteiro %d: ", i + 1);
		scanf("%d", vet + i);
	}//for
	for(int i = 0; i < 10; i++)
		printf("%4d", *((vet + 9) - i));
	printf("\n");
	
	return 0;
}//main