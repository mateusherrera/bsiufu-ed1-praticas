#include <stdio.h>
#define LINHA 3
#define COLUNA 3

int main(void)
{
  int mat[LINHA][COLUNA], aux = 1;

  for(int i = 0; i < LINHA; i++)
  {
    for(int j = 0; j < COLUNA; j++)
    {
      printf("Digite o valor da posição %dx%d: ", i + 1, j + 1);
      scanf("%d", &mat[i][j]);
    }//for
  }//for
  printf("\n");

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
    for(int j = 0; j < LINHA; j++)
    {
      if((i != j) && (mat[i][j] != mat[j][i])) aux = 0;
    }//for
  }//for

  if(aux)
    printf("<< MATRIZ SIMÉTRICA >>\n\n");
  else
    printf("<< MATRIZ NÃO SIMÉTRICA >>\n\n");

  return 0;
}//main
