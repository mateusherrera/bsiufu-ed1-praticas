#include <stdio.h>

int main(void)
{
	int num;
	int soma = 0;
	
	printf("<< Soma de n valores naturais >>\n");
	printf("Quantos números deseja somar? ");
	scanf("%d", &num);
	
	for(int i = num; i >= 0; i--)
		soma += i;
	
	printf("A soma dos %d primeiros números é: %d\n", num, soma);
	
	return 0;
}//main