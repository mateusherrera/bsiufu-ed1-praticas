#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINHA 6
#define COLUNA 6

//Protótipo somaDir
int somaDir(int mat[LINHA][COLUNA], char dir);

int main(void)
{
  int mat[LINHA][COLUNA], norte, sul, oeste, leste, nordes = 0, noroes = 0;

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

  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
    {
      if(j > i) nordes += mat[i][j];
      if((i + j) < (COLUNA - 1)) noroes += mat[i][j];
    }//for
  }//for
  norte = somaDir(mat, 'n');
  sul = somaDir(mat, 's');
  oeste = somaDir(mat, 'o');
  leste = somaDir(mat, 'l');

  printf("<< Somas das regiões >>\n");
  printf("Nordeste: %d\n", nordes);
  printf("Noroeste: %d\n", noroes);
  printf("Norte: %d\n", norte);
  printf("Oeste: %d\n", oeste);
  printf("Oeste + Leste: %d\n", oeste + leste);
  printf("Norte + Sul: %d\n", norte + sul);
  printf("Norte + Oeste: %d\n", norte + oeste);
  printf("Sul + Oeste: %d\n\n", sul + oeste);

  return 0;
}//main

int somaDir(int mat[LINHA][COLUNA], char dir)
{
  int soma = 0;

  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
    {
      if(dir == 'n')
      {
        if((j > i) && ((i + j) < (COLUNA - 1))) soma += mat[i][j];
      }else if(dir == 's')
      {
        if((j < i) && ((i + j) >= COLUNA)) soma += mat[i][j];
      }else if(dir == 'o')
      {
        if(((i + j) < (COLUNA - 1)) && (j < i)) soma += mat[i][j];
      }else if(dir == 'l')
      {
        if((j > i) && ((j + i) >= COLUNA)) soma += mat[i][j];
      }//else if
    }//for
  }//for

  return soma;
}//somaDir
