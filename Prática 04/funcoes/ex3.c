#include <stdio.h>
#include <stdlib.h>

void DesenhaLinha(int x)
{
	for(int i = 0; i < x; i++)
		printf("=");
	printf("\n");
	
	return;
}//DesenhaLinha

void Fatorial(int num, int *fat)
{
	if(num < 0)
	{
		fprintf(stderr, "Fatorial de número negativo!!\n\n");
		exit(1);
	}//if
	if(num == 0)
		return;
	for(int i = 1; i <= num; i++)
		*fat *= i;
	
	return;
}//Fatorial

int main(void)
{
	int num, fat = 1;
	
	printf("Digite um número: ");
	scanf("%d", &num);
	Fatorial(num, &fat);
	DesenhaLinha(20);
	printf("Fatorial(%d) = %d\n", num, fat);
	DesenhaLinha(20);
	printf("\n");
	
	return 0;
}//main