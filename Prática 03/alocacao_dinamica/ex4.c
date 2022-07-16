#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int x;
	int y;
}COORD;

int main(void)
{
	COORD *coord;
	int n;
	
	printf("Quantos pontos deseja digitar: ");
	scanf("%d", &n);
	coord = (COORD *) malloc(n * sizeof(COORD));
	
	for(int i = 0; i < n; i++)
	{
		printf("Entre com a coordenada x do ponto %d: ", i + 1);
		scanf("%d", &coord[i].x);
		printf("Entre com a coordenada y do ponto %d: ", i + 1);
		scanf("%d", &coord[i].y);
	}//for
	
	printf("Pontos digitados: ");
	for(int i = 0; i < n; i++)
		printf("(%d, %d); ",  coord[i].x, coord[i].y);
	printf("\n");
	
	free(coord);
	
	return 0;
}//main