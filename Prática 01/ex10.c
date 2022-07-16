#include <stdio.h>

int main(void)
{
	int num;
	int i = 0;
	int soma = 0;
	
	printf("<< Soma de n valores naturais >>\n");
	printf("Quantos números deseja somar? ");
	scanf("%d", &num);
	i = num;
	
	while(i >= 0)
	{
		soma += i;
		i--;
	}//while
	
	printf("A soma dos %d primeiros números é: %d\n", num, soma);
	
	return 0;
}//main