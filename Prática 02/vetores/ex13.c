#include <stdio.h>

int main(void)
{
	int vet[5];
	
	printf("<< Zerando negativos >>\n");
	for(int i = 0; i < 5; i++)
	{
		printf("Entre com o valor %d: ", i + 1);
		scanf("%d", &vet[i]);
		if(vet[i] < 0) vet[i] = 0;
	}//for
	printf("Zerando os negativos, obtém-se: ");
	for(int i = 0; i < 5; i++)
		printf("%d  ", vet[i]);
	printf("\n");
	
	return 0;
}//main