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
	int *esq, *dir, *cima, *baixo, *esq_y, *dir_y, *cima_x, *baixo_x;
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
	
	esq = &coord[0].x;
	esq_y = &coord[0].y;
	dir = &coord[0].x;
	dir_y = &coord[0].y;
	cima = &coord[0].y;
	cima_x = &coord[0].x;
	baixo = &coord[0].y;
	baixo_x = &coord[0].x;
	for(int i = 0; i < n; i++)
	{
		if(*esq > coord[i].x) 
		{
			esq = &coord[i].x;
			esq_y = &coord[i].y;
		}//if
		if(*dir < coord[i].x)
		{
			dir = &coord[i].x;
			dir_y = &coord[i].y;
		}//if
		if(*cima < coord[i].y)
		{
			cima = &coord[i].y;
			cima_x = &coord[i].x;
		}//if
		if(*baixo > coord[i].y)
		{
			baixo = &coord[i].y;
			baixo_x = &coord[i].x;
		}//if
	}//for
	
	printf("\nPonto mais à cima: (%d, %d).\n", *cima_x, *cima);
	printf("Ponto mais à esquerda: (%d, %d).\n", *esq, *esq_y);
	printf("Ponto mais à direita: (%d, %d).\n", *dir, *dir_y);
	printf("Ponto mais à baixo: (%d, %d).\n", *baixo_x, *baixo);
	
	free(coord);
	
	return 0;
}//main