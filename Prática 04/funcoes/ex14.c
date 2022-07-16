#include <stdio.h>

typedef struct
{
	int x;
	int y;
}PONTO;

void mult_ponto(PONTO p1, int cons, PONTO *ponto)
{
	ponto->x = p1.x * cons;
	ponto->y = p1.y * cons;
	
	return;
}//mult_ponto

int main(void)
{
	PONTO p1, ponto;
	int cons;
	
	printf("Digite x do ponto: ");
	scanf("%d", &p1.x);
	printf("Digite y do ponto: ");
	scanf("%d", &p1.y);
	printf("Digite a constante: ");
	scanf("%d", &cons);
	
	mult_ponto(p1, cons, &ponto);
	printf("Resultado: (%d, %d) * 5 = (%d, %d).\n", p1.x, p1.y, ponto.x, ponto.y);
	
	return 0;
}//main