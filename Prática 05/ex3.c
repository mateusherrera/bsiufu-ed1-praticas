#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 3
#define COLUNA 5
#define MSM 4


int main(void)
{
  int mat1[LINHA][MSM], mat2[MSM][COLUNA], mat3[LINHA][COLUNA];

  srand(time(NULL));
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < MSM; j++)
      mat1[i][j] = (rand() / (double) RAND_MAX) * 5;
  }//for
  for(int i = 0; i < MSM; i++)
  {
    for(int j = 0; j < COLUNA; j++)
      mat2[i][j] = (rand() / (double) RAND_MAX) * 5;
  }//for

  printf("<< 1ª Matriz >>\n");
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < MSM; j++)
      printf("%7d", mat1[i][j]);
    printf("\n");
  }//for
  printf("\n");

  printf("<< 2ª Matriz >>\n");
  for(int i = 0; i < MSM; i++)
  {
    for(int j = 0; j < COLUNA; j++)
      printf("%7d", mat2[i][j]);
    printf("\n");
  }//for
  printf("\n");

  printf("<< Multiplicação das Matrizes >>\n");
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
    {
      mat3[i][j] = 0;
      for(int k = 0; k < MSM; k++)
        mat3[i][j] += (mat1[i][k] * mat2[k][j]);
      printf("%7d", mat3[i][j]);
    }//for
    printf("\n");
  }//for
  printf("\n");

  return 0;
}//main
