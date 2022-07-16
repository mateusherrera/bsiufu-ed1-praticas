#include <stdio.h>

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
}//imprimi_ponto

void soma_ponto(PONTO p1, PONTO p2, PONTO *ponto)
{
	ponto->x = p1.x + p2.x;
	ponto->y = p1.y + p2.y;
	
	return;
}//soma_ponto

int main(void)
{
	PONTO p1, p2, ponto;
	
	printf("Digite x de p1: ");
	scanf("%d", &p1.x);
	printf("Digite y de p1: ");
	scanf("%d", &p1.y);
	printf("Digite x de p2: ");
	scanf("%d", &p2.x);
	printf("Digite y de p2: ");
	scanf("%d", &p2.y);
	
	soma_ponto(p1, p2, &ponto);
	
	printf("A soma de ");
	imprimi_ponto(p1);
	printf(" com ");
	imprimi_ponto(p2);
	printf(" é ");
	imprimi_ponto(ponto);
	printf(".\n");
	
	return 0;
}//main