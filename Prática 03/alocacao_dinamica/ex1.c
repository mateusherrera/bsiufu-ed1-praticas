#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double *produtos;
	int n;
	
	printf("Informe o número de produtos: ");
	scanf("%d", &n);
	produtos = (double *) malloc(n * sizeof(double));
	
	for(int i = 0; i < n; i++)
	{
		printf("Informe o valor do produto %d R$: ", i + 1);
		scanf("%lf", &produtos[i]);
	}//for
	
	printf("\nProdutos cadastrados\n");
	for(int i = 0; i < n; i++)
		printf("Produto %d - R$: %6.2lf\n", i + 1, produtos[i]);
	
	free(produtos);
	
	return 0;
}//main

/**
* 1) ...discuta o que significa o valor de n e de sizeof(double) no commando malloc(n*sizeof(double)).
* 
*    R: n respresenta a quantidade de variáveis que será posivel utilizar. sizeof(double) é a quantidade
*       de bytes que um double necesseita para ser alocado. n * sizeof(double) é quantidade total de bytes
*       que será alocada.
*/