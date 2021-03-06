#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ListaSequencial.h"

//Estrutura da Lista
struct Lista{
  unsigned int inicial, atual, qtd;
  Alunos *dados;
};

int criaLista(Lista **vet, unsigned int tam){
  *vet = malloc(sizeof(Lista));

  if(*vet == NULL)
    return 1;
  (*vet)->dados = malloc(tam * sizeof(Alunos));
  if((*vet)->dados == NULL){
    free(vet);
    return 1;
  }//if

  (*vet)->inicial = tam;
  (*vet)->atual = tam;
  (*vet)->qtd = 0;

  return 0;
}//criaLista

int liberaLista(Lista *vet){
  if(vet == NULL)
    return 1;

  free(vet->dados);
  free(vet);

  return 0;
}//liberaLista

int compactarLista(Lista **vet){
  double temp;

  if(*vet == NULL)
    return 1;

  temp = (*vet)->qtd / (*vet)->inicial;
  temp = ceil(temp) * (*vet)->inicial;
  temp = (unsigned int)temp;

  if(temp == (*vet)->atual)
    return 1;

  (*vet)->dados = realloc((*vet)->dados, temp * sizeof(Alunos));
  if((*vet)->dados == NULL)
    return 1;
  (*vet)->atual = temp;

  return 0;
}//compactarLista

int consultaListaPos(Lista *vet, unsigned int pos, Alunos *aluno){
  if(vet == NULL || pos > vet->qtd || pos == 0)
    return 1;

  *aluno = vet->dados[pos - 1];

  return 0;
}//consultaListaPos

int consultaListaMat(Lista *vet, int mat, Alunos *aluno){
  if(vet == NULL)
    return 1;

  int i = 0;
  while(i < vet->qtd && vet->dados[i].matricula != mat)
    i++;

  if(i == vet->qtd)
    return 1;

  *aluno = vet->dados[i];

  return 0;
}//consultaListaMat

int insereListaFinal(Lista *vet, Alunos aluno){
  if(vet == NULL)
    return 1;

  if(vet->qtd == vet->atual){
    vet->atual += vet->inicial;
    if(realloc(vet->dados, vet->atual * sizeof(Alunos)) == NULL){
      vet->atual -= vet->inicial;
      return 1;
    }//if
  }//if

  vet->dados[vet->qtd] = aluno;
  vet->qtd++;

  return 0;
}//insereListaFinal

int insereListaInicio(Lista *vet, Alunos aluno){
  if(vet == NULL)
    return 1;

  if(vet->qtd == vet->atual){
    vet->atual += vet->inicial;
    if(realloc(vet->dados, vet->atual * sizeof(Alunos)) == NULL){
      vet->atual -= vet->inicial;
      return 1;
    }//if
  }//if

  for(int i = vet->qtd; i > 0; i--)
    vet->dados[i] = vet->dados[i - 1];

  vet->dados[0] = aluno;
  vet->qtd++;

  return 0;
}//insereListaInicio

int insereListaOrdenada(Lista *vet, Alunos aluno){
  if(vet == NULL)
    return 1;

  if(vet->qtd == vet->atual){
    vet->atual += vet->inicial;
    if(realloc(vet->dados, vet->atual * sizeof(Alunos)) == NULL){
      vet->atual -= vet->inicial;
      return 1;
    }//if
  }//if

  int i = 0;
  while(i < vet->qtd && vet->dados[i].matricula < aluno.matricula)
    i++;

  for(int j = vet->qtd; j > i; j--)
    vet->dados[j] = vet->dados[j - 1];

  vet->dados[i] = aluno;
  vet->qtd++;

  return 0;
}//insereListaOrdenada

int removeLista(Lista *vet, int mat){
  if(vet == NULL)
    return 1;

  if(vet->qtd == 0)
    return 1;

  int i = 0;
  while(i < vet->qtd && vet->dados[i].matricula != mat)
    i++;

  if(i == vet->qtd)
    return 1;

  for(int j = i; j < vet->qtd; j++)
    vet->dados[j] = vet->dados[j + 1];
  vet->qtd--;

  return 0;
}//removeLista

int removeListaOtimizada(Lista *vet, int mat){
  if(vet == NULL)
    return 1;

  if(vet->qtd == 0)
    return 1;

  int i = 0;
  while(i < vet->qtd && vet->dados[i].matricula != mat)
    i++;

  if(i == vet->qtd)
    return 1;

  vet->qtd--;
  vet->dados[i] = vet->dados[vet->qtd];

  return 0;
}//removeListaOtimizada

int removeListaInicio(Lista *vet){
  if(vet == NULL)
    return 1;

  if(vet->qtd == 0)
    return 1;

  for(int i = 0; i < vet->qtd; i++)
    vet->dados[i] = vet->dados[i + 1];

  vet->qtd--;

  return 0;
}//removeListaInicio

int removeListaFinal(Lista *vet){
  if(vet == NULL)
    return 1;

  if(vet->qtd == 0)
    return 1;

  vet->qtd--;

  return 0;
}//removeListaFinal

int listaCheia(Lista *vet){
  if(vet == NULL)
    return -1;

  return (vet->qtd == vet->atual);
}//listaCheia

int listaVazia(Lista *vet){
  if(vet == NULL)
    return -1;

  return (vet->qtd == 0);
}//listaVazia

int imprimeLista(Lista *vet){
  if(vet == NULL)
    return 1;

  printf("\n<< ALUNOS >>\n");
  for(int i = 0; i < vet->qtd; i++){
    printf("\n<< Aluno %d >>\n", i + 1);
    printf("Matricula: %d\n", vet->dados[i].matricula);
    printf("Nome: %s\n", vet->dados[i].nome);
    printf("Nota 1?? prova: %.2f\n", vet->dados[i].n1);
    printf("Nota 2?? prova: %.2f\n", vet->dados[i].n2);
    printf("Nota 3?? prova: %.2f\n", vet->dados[i].n3);
  }//for
  printf("\n---------------------------------\n\n");

  return 0;
}//imprimeLista

unsigned int tamanhoLista(Lista *vet){
  if(vet == NULL)
    return 0;

  return vet->atual;
}//tamanhoLista
