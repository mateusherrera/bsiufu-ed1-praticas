#include <stdio.h>

typedef struct
{
	int x;
	int y;
}PONTO;

void imprimi_ponto(PONTO ponto)
{
	printf("(%d, %d)", ponto.x, ponto.y);
	
	return;
}//ImprimiPonto

int main(void)
{
	PONTO ponto;
	
	printf("Digite o valor de x para o ponto: ");
	scanf("%d", &ponto.x);
	printf("Digite o valor de y para o ponto: ");
	scanf("%d", &ponto.y);
	imprimi_ponto(ponto);
	printf(".\n");
	
	return 0;
}//main