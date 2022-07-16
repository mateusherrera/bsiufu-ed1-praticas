#include <stdio.h>

void Troca(double *A, double *B)
{
	double temp = *A;
	*A = *B;
	*B = temp;
	
	return;
}//Troca

int main(void)
{
	double A, B;
	
	printf("Digite valor para A: ");
	scanf("%lf", &A);
	printf("Digite valor para B: ");
	scanf("%lf", &B);
	
	printf("\nAntes da troca\nA = %.2lf\nB = %.2lf\n", A, B);
	Troca(&A, &B);
	printf("\nDepois da troca\nA = %.2lf\nB = %.2lf\n\n", A, B);
	
	return 0;
}//main