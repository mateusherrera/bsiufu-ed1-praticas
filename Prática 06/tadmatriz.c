#include <stdlib.h>
#include <time.h>
#include "tadmatriz.h"

struct matriz
{
  double *mat;
  unsigned int linha, coluna;
};

int criarMatriz(unsigned int linha, unsigned int coluna, Matriz **vet)
{
  *vet = malloc(sizeof(Matriz));

  if(*vet == NULL)
    return 1;
  else
  {
    (*vet)->mat = malloc(linha * coluna * sizeof(Matriz));
    if((*vet)->mat == NULL)
    {
      free(*vet);
      return 1;
    }//if
    (*vet)->linha = linha;
    (*vet)->coluna = coluna;
  }//if

  return 0;
}//criarMatriz

int liberarMatriz(Matriz *vet)
{
  if(vet == NULL)
    return 1;
  else
  {
    free(vet->mat);
    free(vet);
  }//else if

  return 0;
}//liberarMatriz

int escreveElem(Matriz *vet, unsigned int i, unsigned int j, double num)
{
  i--;
  j--;

  if(vet == NULL)
    return 1;
  else
  {
    if(i >= vet->linha || j >= vet->coluna)
      return 1;
    else
      vet->mat[(j * vet->linha) + i] = num;
  }//else if

  return 0;
}//escreveElem

int acessarElem(Matriz *vet, unsigned int i, unsigned int j, double *num)
{
  i--;
  j--;

  if(vet == NULL)
    return 1;
  else
  {
    if(i >= vet->linha || j >= vet->coluna)
      return 1;
    else
      *num = vet->mat[(j * vet->linha) + i];
  }//else if

  return 0;
}//acessarElem

int preencherAleatorio(Matriz *vet, unsigned int max)
{
  if(vet == NULL)
    return 1;
  else
  {
    srand(time(NULL));
    for(int i = 0; i < vet->linha; i++)
    {
      for(int j = 0; j < vet->coluna; j++)
        vet->mat[(j * vet->linha) + i] = (rand() / (double) RAND_MAX) * max;
    }//for
  }//else if

  return 0;
}//preencherAleatorio

int somarMatriz(Matriz *vet1, Matriz *vet2, Matriz *vet3)
{
  if(!(vet1 != NULL && vet2 != NULL && vet3 != NULL))
    return 1;
  else
  {
    if(!((vet1->linha == vet2->linha) && (vet1->linha == vet3->linha) && (vet1->coluna == vet2->coluna) && (vet1->coluna == vet3->coluna)))
      return 1;
    else
    {
      for(int i = 0; i < vet1->linha; i++)
      {
        for(int j = 0; j < vet1->coluna; j++)
          vet3->mat[(j * vet3->linha) + i] = vet1->mat[(j * vet1->linha) + i] + vet2->mat[(j * vet2->linha) + i];
      }//for
    }//else if
  }//else if

  return 0;
}//somarMatriz

int multiplicarMatriz(Matriz *vet1, Matriz *vet2, Matriz *vet3)
{
  if(!(vet1 != NULL && vet2 != NULL && vet3 != NULL))
    return 1;
  else
  {
    if(!((vet1->coluna == vet2->linha) && (vet1->linha == vet3->linha) && (vet2->coluna == vet3->coluna)))
      return 1;
    else
    {
      for(int i = 0; i < vet3->linha; i++)
      {
        for(int j = 0; j < vet3->coluna; j++)
        {
          vet3->mat[(j * vet3->linha) + i] = 0.0;
          for(int k = 0; k < vet1->coluna; k++)
            vet3->mat[(j * vet3->linha) + i] += vet1->mat[(k * vet1->linha) + i] * vet2->mat[(j * vet2->linha) + k];
        }//for
      }//for
    }//else if
  }//else if

  return 0;
}//multiplicarMatriz

int multMatEscalar(Matriz *vet, double escalar)
{
  if(vet == NULL)
    return 1;
  else
  {
    for(int i = 0; i < vet->linha; i++)
    {
      for(int j = 0; j < vet->coluna; j++)
        vet->mat[(j * vet->linha) + i] *= escalar;
    }//for
  }//else if

  return 0;
}//multMatEscalar

int tracoMatriz(Matriz *vet, double *traco)
{
  if(vet == NULL)
    return 1;
  else
  {
    if(vet->linha != vet->coluna)
      return 1;
    else
    {
      *traco = 0.0;
      for(int i = 0; i < vet->linha; i++)
      {
        for(int j = 0; j < vet->coluna; j++)
        {
          if(i == j) *traco += vet->mat[(j * vet->linha) + i];
        }//for
      }//for
    }//else if
  }//else if

  return 0;
}//tracoMatriz

int somaLinha(Matriz *vet, double *Linha, unsigned int linha)
{
  if(!(vet != NULL && Linha != NULL))
    return 1;
  else
  {
    if(linha != vet->linha)
      return 1;
    else
    {
      for(int i = 0; i < vet->linha; i++)
      {
        Linha[i] = 0.0;
        for(int j = 0; j < vet->coluna; j++)
          Linha[i] += vet->mat[(j * vet->linha) + i];
      }//for
    }//else if
  }//else if

  return 0;
}//somaLinha

int somaColuna(Matriz *vet, double *Coluna, unsigned int coluna)
{
  if(!(vet != NULL && Coluna != NULL))
    return 1;
  else
  {
    if(coluna != vet->coluna)
      return 1;
    else
    {
      for(int j = 0; j < vet->coluna; j++)
      {
        Coluna[j] = 0.0;
        for(int i = 0; i < vet->linha; i++)
          Coluna[j] += vet->mat[(j * vet->linha) + i];
      }//for
    }//else if
  }//else if

  return 0;
}//somaColuna
