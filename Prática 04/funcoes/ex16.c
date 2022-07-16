#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	int x;
	int y;
}PONTO;

void inc_dir(PONTO *ponto, char dir)
{
	if(dir == 'N') ponto->y++;
	if(dir == 'S') ponto->y--;
	if(dir == 'L') ponto->x++;
	if(dir == 'O') ponto->x--;

	return;
}//inc_dir

void inc_diag(PONTO *ponto, char *dir)
{
	if(strcmp(dir, "NORDESTE") == 0)
	{
		ponto->x++;
		ponto->y++;
	}else if(strcmp(dir, "NOROESTE") == 0)
	{
		ponto->x--;
		ponto->y++;
	}else if(strcmp(dir, "SUDESTE") == 0)
	{
		ponto->x++;
		ponto->y--;
	}else if(strcmp(dir, "SUDOESTE") == 0)
	{
		ponto->x--;
		ponto->y--;
	}//else if

	return;
}

int main(void)
{
	PONTO p, ponto;
	char dir[10];

	printf("Digite x do ponto: ");
	scanf("%d", &p.x);
	printf("Digite y do ponto: ");
	scanf("%d", &p.y);
	printf("Digite a direção: ");
	getchar();
	fgets(dir, sizeof(dir), stdin);
	dir[strcspn(dir, "\n")] = '\0';

	for(int i = 0; i < 10; i++)
		dir[i] = toupper(dir[i]);
	ponto = p;

	if((strcspn(dir, "\0") - 1) <= 5)
		inc_dir(&ponto, dir[0]);
	else
		inc_diag(&ponto, dir);
	printf("(%d, %d) %s => (%d, %d).\n", p.x,  p.y, dir, ponto.x, ponto.y);

	return 0;
}//main
