#include <stdio.h>

int main(void)
{
	int num;
	long double fat = 1.0;
	long double soma = 1.0;
	
	printf("<< Número neperiano >>\n");
	printf("Entre com o número de termos: ");
	scanf("%d", &num);
	
	for(int i = 1; i < num; i++)
	{
		for(int j = 1; j <= i; j++)
			fat *= j;
		soma += 1.0/fat;
		fat = 1.0;
	}//for
	printf("%Lf\n", soma);
	
	return 0;
}//main