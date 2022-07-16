#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 5
#define COLUNA 8

int main(void)
{
  int mat[LINHA][COLUNA], lin_maior, col_maior;

  srand(time(NULL));
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
      mat[i][j] = (rand() / (double) RAND_MAX) * 5;
  }//for

  printf("<< Matriz >>\n");
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
      printf("%7d", mat[i][j]);
    printf("\n");
  }//for
  printf("\n");

  lin_maior = 0;
  col_maior = 0;
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
    {
      if(mat[i][j] > mat[lin_maior][col_maior])
      {
        lin_maior = i;
        col_maior = j;
      }//if
    }//for
  }//for

  printf("<< Maior valor >>\n");
  printf("Sua posição é: %dx%d\n", lin_maior + 1, col_maior + 1);
  printf("Seu valor é: %d\n\n", mat[lin_maior][col_maior]);

  return 0;
}//main
