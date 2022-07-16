#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencial.h"

//Estrutura da Lista
struct Lista{
  int qtd;
  Alunos dados[MAX];
};

Lista* criaLista(void){
  Lista* li = malloc(sizeof(Lista));
  if(li)
    li->qtd = 0;

  return li;
}// criarLista

void liberaLista(Lista* vet){
  if(vet)
    free(vet);

  return;
}// liberaLista

int consultaListaPos(Lista *vet, unsigned int pos, Alunos *aluno){
  if(vet == NULL)
    return OUT_OF_MEMORY;
  if(pos > vet->qtd || pos == 0)
    return ELEM_NOT_FOUND;
  *aluno = vet->dados[pos - 1];
  return SUCCESS;
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
    return OUT_OF_MEMORY;
  if(vet->qtd == MAX)
    return ELEM_NOT_FOUND;
  vet->dados[vet->qtd] = aluno;
  vet->qtd++;
  return SUCCESS;
}//insereListaFinal

int insereListaInicio(Lista *vet, Alunos aluno){
  if(vet == NULL)
    return 1;
  if(vet->qtd == MAX)
    return 1;
  for(int i = vet->qtd; i > 0; i--)
    vet->dados[i] = vet->dados[i - 1];
  vet->dados[0] = aluno;
  vet->qtd++;
  return 0;
}//insereListaInicio

int insereListaOrdenada(Lista *vet, Alunos aluno){
  if(vet == NULL)
    return 1;
  if(vet->qtd == MAX)
    return 1;
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
    return OUT_OF_MEMORY;
  if(vet->qtd == 0)
    return ELEM_NOT_FOUND;
  vet->qtd--;
  return SUCCESS;
}//removeListaFinal

int listaCheia(Lista *vet){
  if(vet == NULL)
    return -1;
  return (vet->qtd == MAX);
}//listaCheia

int listaVazia(Lista *vet){
  if(vet == NULL)
    return OUT_OF_MEMORY;
  if(!vet->qtd)
    return 1;
  else
    return 0;
}//listaVazia

int tamLista(Lista* vet){
  if(!vet)
    return OUT_OF_MEMORY;
  return vet->qtd;
}//temLista

int imprimeLista(Lista *vet){
  if(vet == NULL)
    return 1;
  printf("\n<< ALUNOS >>\n");
  for(int i = 0; i < vet->qtd; i++){
    printf("\n<< Aluno %d >>\n", i + 1);
    printf("Matricula: %d\n", vet->dados[i].matricula);
    printf("Nome: %s\n", vet->dados[i].nome);
    printf("Nota 1ª prova: %.2f\n", vet->dados[i].n1);
    printf("Nota 2ª prova: %.2f\n", vet->dados[i].n2);
    printf("Nota 3ª prova: %.2f\n", vet->dados[i].n3);
  }//for
  printf("\n---------------------------------\n\n");
  return 0;
}//imprimeLista
