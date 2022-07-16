#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

typedef struct lista_no Lista_no;

struct lista{
  Lista_no* head;
  int qtd;
  int ordenada; // 0 - não ordenada; diferente de 0 - ordenada.
};

struct lista_no{
  Aluno dado;
  Lista_no* prox;
};

Lista* cria_lista(int ord){
  Lista* li = malloc(sizeof(Lista));

  if(!li)
    return NULL;
  li->head = NULL;
  li->qtd = 0;
  li->ordenada = ord;

  return li;
}//cria_lista

void libera_lista(Lista* li){
  Lista_no* No;

  No = li->head;
  while(No){
    li->head = No->prox;
    free(No);
    No = li->head;
  }
  free(li);

  return;
}//libera_lista

int consulta_lista_pos(Lista* li, int pos, Aluno* al){
  Lista_no* No;
  int paux;

  if(!li)
    return OUT_OF_MEMORY;

  pos--;
  No = li->head;
  for(paux = 0; No && paux != pos; paux++)
    No = No->prox;

  if(!No)
    return ELEM_NOT_FOUND;
  *al = No->dado;

  return SUCCESS;
}//consulta_lista_pos

int consulta_lista_mat(Lista* li, int mat, Aluno* al){
  Lista_no* No;

  if(!li)
    return OUT_OF_MEMORY;

  for(No = li->head; No && mat != No->dado.matricula; No = No->prox);

  if(!No)
    return ELEM_NOT_FOUND;
  *al = No->dado;

  return SUCCESS;
}//consulta_lista_mat

int insere_lista_final(Lista* li, Aluno al){
  Lista_no* No;

  if(!li)
    return OUT_OF_MEMORY;

  if(li->ordenada)
    return INVALID_LIST;

  if(!li->head){
    li->head = malloc(sizeof(Lista_no));
    if(!li->head)
      return OUT_OF_MEMORY;
    li->head->dado = al;
    li->head->prox = NULL;
  }else{
    for(No = li->head; No->prox; No = No->prox);
    No->prox = malloc(sizeof(Lista_no));
    if(!No->prox)
      return OUT_OF_MEMORY;
    No->prox->dado = al;
    No->prox->prox = NULL;
  }//else if

  li->qtd++;
  return SUCCESS;
}//insere_lista_final

int insere_lista_inicio(Lista* li, Aluno al){
  Lista_no* No;

  if(!li)
    return OUT_OF_MEMORY;

  if(li->ordenada)
    return INVALID_LIST;

  if(!li->head){
    li->head = malloc(sizeof(Lista_no));
    if(!li->head)
      return OUT_OF_MEMORY;
    li->head->dado = al;
    li->head->prox = NULL;
  }else{
    No = malloc(sizeof(Lista_no));
    if(!No)
      return OUT_OF_MEMORY;
    No->dado = al;
    No->prox = li->head;
    li->head = No;
  }//else

  li->qtd++;
  return SUCCESS;
}//insere_lista_inicio

int insere_lista_pos(Lista* li, int pos, Aluno al){
  Lista_no* No_Ant;
  Lista_no* No_At;
  Lista_no* No_Nv;
  int paux;

  if(!li)
    return OUT_OF_MEMORY;

  if(li->ordenada)
    return INVALID_LIST;

  if(pos <= 0 || (!li->head && pos != 1))
    return ELEM_NOT_FOUND;

  No_At = li->head;
  for(paux = 1; No_At && paux != pos; paux++){
    No_Ant = No_At;
    No_At = No_At->prox;
  }//for
  if(!No_At && paux != pos)
    return ELEM_NOT_FOUND;
  else{
    No_Nv = malloc(sizeof(Lista_no));
    if(!No_Nv)
      return OUT_OF_MEMORY;
    No_Nv->dado = al;
    No_Nv->prox = No_At;
    No_Ant->prox = No_Nv;
  }//else if

  li->qtd++;
  return SUCCESS;
}//insere_lista_pos

int insere_lista_ordenada(Lista* li, Aluno al){
  Lista_no* No_Ant;
  Lista_no* No_At;
  Lista_no* No_Nv;

  if(!li)
    return OUT_OF_MEMORY;

  if(!li->ordenada)
    return INVALID_LIST;

  No_Nv = malloc(sizeof(Lista_no));
  if(!No_Nv)
    return OUT_OF_MEMORY;
  if(!li->head || al.matricula < li->head->dado.matricula){
    No_Nv->dado = al;
    No_Nv->prox = li->head;
    li->head = No_Nv;
  }else{
    No_Ant = li->head;
    No_At = No_Ant->prox;
    while(No_At && !(al.matricula < No_At->dado.matricula)){
      No_Ant = No_At;
      No_At = No_At->prox;
    }//while
    No_Nv = malloc(sizeof(Lista_no));
    if(!No_Nv)
      return OUT_OF_MEMORY;
    No_Nv->dado = al;
    No_Nv->prox = No_At;
    No_Ant->prox = No_Nv;
  }//else if

  li->qtd++;
  return SUCCESS;
}//insere_lista_ordenada

int remove_lista(Lista* li, int mat){
  Lista_no* No;
  Lista_no* No_Ant;

  if(!li)
    return OUT_OF_MEMORY;
  No = li->head;

  while(No && No->dado.matricula != mat){
    No_Ant = No;
    No = No->prox;
  }//while

  if(!No)
    return ELEM_NOT_FOUND;
  if(No == li->head)
    li->head = No->prox;
  else
    No_Ant->prox = No->prox;
  free(No);

  li->qtd--;
  return SUCCESS;
}//remove_lista

int remove_lista_inicio(Lista* li){
  Lista_no* No;

  if(!li)
    return OUT_OF_MEMORY;
  if(!li->head)
    return ELEM_NOT_FOUND;

  No = li->head;
  li->head = No->prox;
  free(No);

  li->qtd--;
  return SUCCESS;
}//remove_lista_inicio

int remove_lista_final(Lista* li){
  Lista_no* No;
  Lista_no* No_aux;

  if(!li)
    return OUT_OF_MEMORY;
  if(!li->head)
    return ELEM_NOT_FOUND;

  if(!li->head->prox){
    No = li->head;
    li->head = No->prox;
  }else{
    for(No_aux = li->head; No_aux->prox->prox; No_aux = No_aux->prox);
    No = No_aux->prox;
    No_aux->prox = No->prox;
  }//else if
  free(No);

  li->qtd--;
  return SUCCESS;
}//remove_lista_final

int tamanho_lista(Lista* li){
  Lista_no* No;

  if(!li)
    return OUT_OF_MEMORY;

  return li->qtd;
}//tamanho_lista

int lista_cheia(Lista* li){
  Lista_no* teste;

  if(!li)
    return OUT_OF_MEMORY;
  teste = malloc(sizeof(Lista_no));
  if(!teste)
    return 1;
  free(teste);

  return SUCCESS;
}//lista_cheia

int lista_vazia(Lista* li){
  if(!li)
    return OUT_OF_MEMORY;
  if(!li->head)
    return 1;

  return SUCCESS;
}//lista_vazia

int imprime_lista(Lista* li){
  Lista_no* No;

  if(!li)
    return OUT_OF_MEMORY;
  if(!li->head)
    return ELEM_NOT_FOUND;

  No = li->head;
  printf("\n<< Lista de Alunos >>\n");
  for(int i = 1; No; i++){
    printf("\n<< Aluno %d >>\n", i);
    printf("Nome: %s\n", No->dado.nome);
    printf("Matrícula: %d\n", No->dado.matricula);
    printf("Nota 1: %.2f\nNota 2: %.2f\nNota 3: %.2f\n\n", No->dado.n1, No->dado.n2, No->dado.n3);
    No = No->prox;
  }//for
  printf("\n----------------------------------------\n\n");

  return SUCCESS;
}//imprime_lista
