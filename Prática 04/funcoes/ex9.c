#include <stdio.h>

void incp(double x, double per, double *final)
{
	double mult = (100.0 + per) / 100.0;
	*final = x * mult;
	
	return;
}//incp

int main(void)
{
	double x, per, final;
	
	printf("Digite o número que será alterado: ");
	scanf("%lf", &x);
	printf("Digite a porcentagem da alteração desejada: ");
	scanf("%lf", &per);
	incp(x, per, &final);
	
	printf("\n%.2lf%% de %.2lf é = %.2lf.\n\n", per + 100.0, x, final);
	
	return 0;
}//main