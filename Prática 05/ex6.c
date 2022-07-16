#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 3
#define COLUNA 3

int main(void)
{
  int mat[LINHA][COLUNA], soma_lin[LINHA], soma_col[COLUNA];

  srand(time(NULL));
  for(int i = 0; i < LINHA; i++)
  {
    soma_lin[i] = 0;
    for(int j = 0; j < COLUNA; j++)
      mat[i][j] = (rand() / (double) RAND_MAX) * 5;
  }//for
  for(int i = 0; i < COLUNA; i++)
    soma_col[i] = 0;

  printf("<< Matriz >>\n");
  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
    {
      printf("%7d", mat[i][j]);
      soma_lin[i] += mat[i][j];
    }//for
    printf("\n");
  }//for
  printf("\n");

  for(int i = 0; i < COLUNA; i++)
  {
    for(int j = 0; j < LINHA; j++)
      soma_col[i] += mat[j][i];
  }//for

  printf("<< Soma das linhas >>\n");
  for(int i = 0; i < LINHA; i++)
    printf("Linha %d: %d\n", i + 1, soma_lin[i]);
  printf("\n");
  printf("<< Soma das colunas >>\n");
  for(int i = 0; i < COLUNA; i++)
    printf("Coluna %d: %d\n", i + 1, soma_col[i]);
  printf("\n");

  return 0;
}//main
