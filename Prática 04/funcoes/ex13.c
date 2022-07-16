#include <stdio.h>

typedef struct
{
	int x;
	int y;
}PONTO;

void calc_area(PONTO p1, PONTO p2, int *area)
{
	if(p1.x > p2.x && p1.y > p2.y) *area = (p1.x - p2.x) * (p1.y - p2.y);
	if(p1.x > p2.x && p1.y < p2.y) *area = (p1.x - p2.x) * (p2.y - p1.y);
	if(p1.x < p2.x && p1.y < p2.y) *area = (p2.x - p1.x) * (p2.y - p1.y);
	if(p1.x < p2.x && p1.y > p2.y) *area = (p2.x - p1.x) * (p1.y - p2.y);
	
	return;
}//calc_area

int main(void)
{
	PONTO p1, p2;
	int area;
	
	printf("Digite x de p1: ");
	scanf("%d", &p1.x);
	printf("Digite y de p1: ");
	scanf("%d", &p1.y);
	printf("Digite x de p2: ");
	scanf("%d", &p2.x);
	printf("Digite y de p2: ");
	scanf("%d", &p2.y);
	
	calc_area(p1, p2, &area);
	printf("A área do retângulo defindo por (%d, %d) e (%d, %d) é %d\n", p1.x, p1.y, p2.x, p2.y, area);
	
	return 0;
}//main