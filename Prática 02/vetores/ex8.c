#include <stdio.h>
#include <math.h>

int main(void)
{
	double media = 0.0;
	double DP = 0.0;
	double vet[5];
	
	printf("<< Média e desvio-padrão >>\n");
	for(int i = 0; i < 5; i++)
	{
		printf("Digite o valor %d: ", i + 1);
		scanf("%lf", &vet[i]);
	}//for
	
	for(int i = 0; i < 5; i++)
		media += vet[i];
	media /= 5.0;
	
	for(int i = 0; i < 5; i++)
		DP += pow((vet[i] - media),2);
	DP = sqrt(DP / 4.0);
	
	printf("A média é %.2lf e o desvio-padrão é %.2lf.\n", media, DP);
	
	return 0;
}//main