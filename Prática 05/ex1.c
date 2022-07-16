#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 4
#define COLUNA 4

int main(void)
{
  int mat1[LINHA][COLUNA], mat2[LINHA][COLUNA];

  srand(time(NULL));
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
    {
      mat1[i][j] = (rand() / (double) RAND_MAX) * 5;
      mat2[i][j] = (rand() / (double) RAND_MAX) * 5;
    }//for
  }//for

  printf("<< 1ª Matriz >>\n");
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
      printf("%7d", mat1[i][j]);
    printf("\n");
  }//for
  printf("\n");

  printf("<< 2ª Matriz >>\n");
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
      printf("%7d", mat2[i][j]);
    printf("\n");
  }//for
  printf("\n");

  printf("<< Soma das Matrizes >>\n");
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
      printf("%7d", mat1[i][j] + mat2[i][j]);
    printf("\n");
  }//for
  printf("\n");

  return 0;
}//main
