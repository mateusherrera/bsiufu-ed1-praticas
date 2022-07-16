#include <stdio.h>

void Potencia(int base, int expo, double *pot)
{
	*pot = 1.0;
	if(expo >= 0){
		for(int i = 0; i < expo; i++)
			(*pot) *= base;
		return;
	}else{
		for(int i = 0; i > expo; i--)
			(*pot) *= base;
		*pot = 1.0 / *pot;
		return;
	}//if else
}//Potencia

int main(void)
{
	int base, expo;
	double pot;
	
	printf("Digite a base: ");
	scanf("%d", &base);
	printf("Digite o expoente: ");
	scanf("%d", &expo);
	Potencia(base, expo, &pot);
	printf("%d ^ %d = %.2lf\n\n", base, expo, pot);
	
	return 0;
}//main