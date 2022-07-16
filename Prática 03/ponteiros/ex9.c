#include <stdio.h>

int main(void)
{
	double vet[10];
	
	for(int i = 0; i < 10; i++)
	{
		printf("Digite o double %d: ", i + 1);
		scanf("%lf", vet + i);
	}//for
	for(int i = 0; i < 10; i++)
		printf("%6.2lf", *(vet + i));
	printf("\n");
	
	return 0;
}//main