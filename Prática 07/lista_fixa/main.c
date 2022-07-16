#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaSequencial.h"

//Protótipo de menuPrincipal
void menuPrincipal(unsigned int *op);

//Protótipo de listaCria
Lista *listaCria();

//Protótipo de insereAluno
void insereAluno(Lista *vet);

//Protótipo de consultaAluno
void consultaAluno(Lista *vet);

//Protótipo de removeAluno
void removeAluno(Lista *vet);

//Protótipo de listaCheiaVazia
void listaCheiaVazia(Lista *vet);

//Protótipo de listaImprime
void listaImprime(Lista *vet);

//Protótipo de listaLibera
void listaLibera(Lista *vet);

//Protótipo de opInvalida
void opInvalida(unsigned int *op);

//Protótipo de lerAluno
int lerAluno(Alunos *al);

int main(void){
  Lista *lista = NULL;
  unsigned int op = 0, aux = 0;

  while(!(op == 8)){
    switch(op){
      case 0:
        menuPrincipal(&op);
        break;
      case 1:
        if(aux == 0){
          lista = listaCria();
          aux = 1;
        }else
          printf("\n<< LISTA JÁ ALOCADA >>\n");
        op = 0;
        break;
      case 2:
        if(aux)
          insereAluno(lista);
        else
          printf("\nLista não alocada.\n");
        op = 0;
        break;
      case 3:
        if(aux)
          consultaAluno(lista);
        else
          printf("\nLista não alocada.\n");
        op = 0;
        break;
      case 4:
        if(aux)
          removeAluno(lista);
        else
          printf("\nLista não alocada.\n");
        op = 0;
        break;
      case 5:
        if(aux)
          listaCheiaVazia(lista);
        else
          printf("\nLista não alocada.\n");
        op = 0;
        break;
      case 6:
        if(aux)
          listaImprime(lista);
        else
          printf("\nLista não alocada.\n");
        op = 0;
        break;
      case 7:
        if(aux){
          listaLibera(lista);
          aux = 0;
        }else
          printf("\nLista não alocada.\n");
        op = 0;
        break;
      default:
        opInvalida(&op);
        if(op == 0) op = 9;
        break;
    }//switch
  }//while

  return 0;
}//main

void menuPrincipal(unsigned int *op){
  printf("\n<< MENU DE TESTE DE 'ListaSequencial' >>\n");
  printf("1 - Cria Lista.\n");
  printf("2 - Insere Novo Aluno.\n");
  printf("3 - Consulta Aluno.\n");
  printf("4 - Remove Aluno.\n");
  printf("5 - Lista Cheia ou Vazia.\n");
  printf("6 - Imprime Lista.\n");
  printf("7 - Libera Lista.\n");
  printf("8 - Sair.\n\n");
  printf("Digite a opção desejada: ");
  scanf("%u", op);
  if(*op == 0) *op = 9;
  return;
}//menuPrincipal

Lista *listaCria(){
  Lista *li = NULL;
  if(criaLista(&li))
    printf("\n<< Erro ao alocar lista >>\n");
  else
    printf("\n<< Lista alocada >>\n");

  return li;
}//listaCria

void insereAluno(Lista *vet){
  Alunos aluno;
  unsigned int o;
  int r;

  printf("\n<< Como deseja inserir o aluno à lista? >>\n");
  printf("1 - Inserir em lista ordenada.\n");
  printf("2 - Inserir no inicio da lista.\n");
  printf("3 - Inserir no final da lista.\n");
  printf("4 - Voltar ao menu principal.\n\n");
  printf("Digite sua opção: ");
  scanf("%u", &o);
  while(o == 0 || o > 4)
    opInvalida(&o);

  if(o == 4) return;

  if(lerAluno(&aluno)){
    printf("\n<< Erro ao ler dados do aluno >>\n");
    return;
  }//if

  if(o == 1)
    r = insereListaOrdenada(vet, aluno);
  else if(o == 2)
    r = insereListaInicio(vet, aluno);
  else
    r = insereListaFinal(vet, aluno);

  if(r) printf("\n<< Erro ao inserir aluno >>\n");

  return;
}//insereAluno

void consultaAluno(Lista *vet){
  Alunos aluno;
  unsigned int o, pos;
  int r, mat;

  printf("\n<< Como deseja consultar o aluno na lista? >>\n");
  printf("1 - Consultar por posição.\n");
  printf("2 - Consultar por matrícula.\n");
  printf("3 - Volat ao menu principal.\n\n");
  printf("Digite sua opção: ");
  scanf("%u", &o);
  while(o == 0 || o > 3)
    opInvalida(&o);

  if(o == 3) return;

  if(o == 1){
    printf("Digite a posição do aluno que deseja consultar: ");
    scanf("%u", &pos);
    r = consultaListaPos(vet, pos, &aluno);
  }else{
    printf("Digite a matrícula do aluno que deseja consultar: ");
    scanf("%d", &mat);
    r = consultaListaMat(vet, mat, &aluno);
  }//else if

  if(r){
    printf("\n<< Erro ao consultar aluno >>\n");
    return;
  }//if

  printf("\n<< Aluno Consultado >>\n");
  printf("Matricula: %d\n", aluno.matricula);
  printf("Nome: %s\n", aluno.nome);
  printf("Nota 1: %.2f\nNota 2: %.2f\nNota 3: %.2f\n\n", aluno.n1, aluno.n2, aluno.n3);

  return;
}//consultaAluno

void removeAluno(Lista *vet){
  unsigned int o;
  int r, mat;

  printf("\n<< Como deseja remover o aluno? >>\n");
  printf("1 - Remover aluno de lista ordenada.\n");
  printf("2 - Remover aluno de lista não ordenada.\n");
  printf("3 - Remover primeiro aluno.\n");
  printf("4 - Remover último aluno.\n");
  printf("5 - Voltar ao menu principal.\n\n");
  printf("Digite a opção desejada: ");
  scanf("%u", &o);
  while(o == 0 || o > 5)
    opInvalida(&o);

  if(o == 5) return;

  if(o == 1 || o == 2){
    printf("Digite a matrícula do aluno que deve ser removido: ");
    scanf("%d", &mat);
    if(o == 1)
      r = removeLista(vet, mat);
    else
      r = removeListaOtimizada(vet, mat);
  }else if(o == 3)
    r = removeListaInicio(vet);
  else
    r = removeListaFinal(vet);

  if(r) printf("\n<< Erro ao remover aluno >>\n");

  return;
}//removeLista

void listaCheiaVazia(Lista *vet){
  int rc, rv;

  rc = listaCheia(vet);
  rv = listaVazia(vet);

  if(rc == -1 || rv == -1)
    printf("\n<< Erro, lista não alocada >>\n");
  else if(rc)
    printf("\nLista Cheia!!\n");
  else if(rv)
    printf("\nLista Vazia!!\n");
  else
    printf("\nLista não está cheia, nem vazia!!\n");

  return;
}//listaCheiaVazia

void listaImprime(Lista *vet){
  if(imprimeLista(vet))
    printf("\n<< Erro, lista não alocada >>\n");

  return;
}//listaImprime

void listaLibera(Lista *vet){
  if(liberaLista(vet))
    printf("\nLista não alocada.\n");
  else
    printf("\n<< Lista liberada >>\n");

  return;
}//listaLibera

void opInvalida(unsigned int *op){
  printf("\nOpção Inválida!!!\n");
  printf("Digite uma opção válida: ");
  scanf("%u", op);

  return;
}//opInvalida

int lerAluno(Alunos *al){
  printf("\n<< Entre com as informações do aluno >>\n");

  printf("Matrícula: ");
  scanf("%d", &al->matricula);
  getchar();

  printf("Nome: ");
  if(fgets(al->nome, sizeof(al->nome), stdin) == NULL){
    fprintf(stderr, "\n<< Erro ao ler nome >>\n");
    return 1;
  }else
    al->nome[strcspn(al->nome, "\n")] = '\0';

  printf("Entre com o valor da nota 1: ");
  scanf("%2f", &al->n1);

  printf("Entre com o valor da nota 2: ");
  scanf("%2f", &al->n2);

  printf("Entre com o valor da nota 3: ");
  scanf("%2f", &al->n3);

  return 0;
}//lerAluno
