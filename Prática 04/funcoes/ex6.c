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

double Neperiano(int qtd)
{
	double nep = 2.0;
	int fat = 1;
	
	for(int i = 2; i <= qtd; i++)
	{
		Fatorial(i, &fat);
		nep += 1.0/ (double) fat;
		fat = 1;
	}//for
	
	return nep;
}//Neperiano

int main(void)
{
	double nep;
	int qtd;
	
	printf("Digite o valor de n: ");
	scanf("%d", &qtd);
	nep = Neperiano(qtd);
	
	DesenhaLinha(30);
	printf("Para %d = %.4lf\n", qtd, nep);
	DesenhaLinha(30);
	
	return 0;
}//main