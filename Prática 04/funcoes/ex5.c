#include <stdio.h>
#include <math.h>

int SqPerfeito(double num)
{
	int aux = 0;
	double inteiro, fracional;
	
	num = sqrt(num);
	fracional = modf(num, &inteiro);
	if(fracional == 0.0) aux = 1;
	
	return aux;
}//SqPerfeito

int main(void)
{
	double num;
	
	printf("Digite um número: ");
	scanf("%lf", &num);
	if(SqPerfeito(num))
		printf("É verdadeiro que %.2lf é um quadrado perfeito.\n\n", num);
	else
		printf("É falso que %.2lf é um quadrado perfeito.\n\n", num);
	
	return 0;
}//main