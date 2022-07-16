#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int x;
	int y;
}PONTO;

void inc_dir(PONTO *ponto, char dir)
{
	if(dir == 'n') ponto->y++;
	if(dir == 's') ponto->y--;
	if(dir == 'l') ponto->x++;
	if(dir == 'o') ponto->x--;
	
	return;
}//inc_dir

int main(void)
{
	PONTO p, ponto;
	char dir[6];
	
	printf("Digite x do ponto: ");
	scanf("%d", &p.x);
	printf("Digite y do ponto: ");
	scanf("%d", &p.y);
	printf("Digite a direção: ");
	getchar();
	fgets(dir, sizeof(dir), stdin);
	dir[strcspn(dir, "\n")] = '\0';
	
	ponto = p;
	inc_dir(&ponto, dir[0]);
	printf("(%d, %d) %s => (%d, %d).\n", p.x,  p.y, dir, ponto.x, ponto.y);
	
	return 0;
}//main