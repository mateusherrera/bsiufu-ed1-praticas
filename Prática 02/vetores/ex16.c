#include <stdio.h>

int main(void)
{
	int vet[8];
	int vezes = 0;
	int aux = 0;
	
	printf("<< Valores iguais >>\n");
	for(int i = 0; i < 8; i++)
	{
		printf("Entre com o número %d: ", i + 1);
		scanf("%d", &vet[i]);
	}//for
	
	printf("Valores repetidos: \n");
	for(int i = 0; i < 8; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(vet[i] == vet[j]) aux = 1;
		}//for
		if(aux == 0)
		{
			for(int j = i + 1; j < 8; j++)
			{
				if(vet[i] == vet[j])
				{
					for(int k = i; k < 8; k++)
					{
						if(vet[i] == vet[k]) vezes++;
					}//for
					printf("%d aparece %d vezes\n", vet[i], vezes);
					vezes = 0;
					j = 8;
				}//if
			}//for
		}//if
		aux = 0;
	}//for
	printf("\n");
	
	return 0;
}//main