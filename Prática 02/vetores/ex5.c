#include <stdio.h>

int main(void)
{
	double media = 0.0;
	int vet[5];
	int aux;
	
	printf("<< 5 valores >>\n");
	for(int i = 0; i < 5; i++)
	{
		printf("Entre com o valor %d: ", i + 1);
		scanf("%d", &vet[i]);
	}//for
	
	printf("Os números digitados são: ");
	for(int i = 0; i < 5; i++)
		printf("%d ", vet[i]);
	printf("\n");
	
	aux = vet[0];
	for(int i = 0; i < 5; i++)
	{
		if(aux < vet[i]) aux = vet[i];
	}//for
	printf("O maior valor é: %d\n", aux);
	
	aux = vet[0];
	for(int i = 0; i < 5; i++)
	{
		if(aux > vet[i]) aux = vet[i];
	}//for
	printf("O menor valor é: %d\n", aux);
	
	for(int i = 0; i < 5; i++)
		media += vet[i];
	printf("A média é: %lf\n", media / 5.0);
	
	return 0;
}//main