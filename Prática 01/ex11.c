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
	
	do{
		soma += i;
		i--;
	}while(i >= 0);
	
	printf("A soma dos %d primeiros números é: %d\n", num, soma);
	
	return 0;
}//main