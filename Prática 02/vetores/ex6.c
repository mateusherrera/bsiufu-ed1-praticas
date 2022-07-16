#include <stdio.h>

int main(void)
{
	double media = 0.0;
	int vet[5];
	int aux;
	int aux2;
	
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
	aux2 = 0;
	for(int i = 0; i < 5; i++)
	{
		if(aux < vet[i])
		{
			aux = vet[i];
			aux2 = i;
		}//if
	}//for
	printf("O maior valor é: %d, localizado na posição %d do vetor\n", aux, aux2);
	
	aux = vet[0];
	aux2 = 0;
	for(int i = 0; i < 5; i++)
	{
		if(aux > vet[i])
		{
			aux = vet[i];
			aux2 = i;
		}//if
	}//for
	printf("O menor valor é: %d, localizado na posição %d do vetor\n", aux, aux2);
	
	for(int i = 0; i < 5; i++)
		media += vet[i];
	printf("A média é: %lf\n", media / 5.0);
	
	return 0;
}//main