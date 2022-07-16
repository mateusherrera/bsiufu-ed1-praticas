#include <stdio.h>

double incp(double x, double per)
{
	double mult = (100.0 + per) / 100.0;
	
	return x * mult;
}//incp

int main(void)
{
	double x, per;
	
	printf("Digite o número que será alterado: ");
	scanf("%lf", &x);
	printf("Digite a porcentagem da alteração desejada: ");
	scanf("%lf", &per);
	
	printf("\n%.2lf%% de %.2lf é = %.2lf.\n\n", per + 100.0, x, incp(x, per));
	
	return 0;
}//main