#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 5
#define COLUNA 5

int main(void)
{
  int mat[LINHA][COLUNA], soma = 0;

  srand(time(NULL));
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
    {
      mat[i][j] = (rand() / (double) RAND_MAX) * 5;
      if(i == j) soma += mat[i][j];
    }//for
  }//for

  printf("<< Matriz >>\n");
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
      printf("%7d", mat[i][j]);
    printf("\n");
  }//for
  printf("\n");

  printf("Soma da diagonal principal: %d\n\n", soma);

  return 0;
}//main
