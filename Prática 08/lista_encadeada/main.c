#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaEncadeada.h"

//Protótipo de consultaLista
void consultaLista(Lista*);
//Protótipo de insereLista
void insereLista(Lista*);
//Protótipo de removeLista
void removeLista(Lista*);
//Protótipo de listaCheiaVazia
void tamanhoLista(Lista*);
//Protótipo de imprimeLista
void imprimeLista(Lista*);
//Protótipo de leAluno
int leAluno(Aluno*);
//Protótipo de imprimirAluno
void imprimeAluno(Aluno);

int main(void){
  unsigned int o = 8, alloc = 0;
  Lista* lista;

  while(o){
    switch(o){
      case 8: //Menu_Principal
        printf("\n<< Menu Principal >>\n");
        printf("1 - Criar Lista.\n");
        printf("2 - Consultar Aluno.\n");
        printf("3 - Inserir Aluno.\n");
        printf("4 - Remover Aluno.\n");
        printf("5 - Tamanho da Lista.\n");
        printf("6 - Imprime Lista.\n");
        printf("7 - Destrói Lista.\n");
        printf("8 - Sair.\n\n");
        printf("Digite uma opção: ");
        scanf("%u", &o);
        if(o == 8) o = 0;
        else if(o == 0) o = 9;
        break;
      case 1: //Criar Lista
        if(alloc)
          printf("\nLista JÁ Alocada.\n");
        else{
          lista = cria_lista();
          if(!lista)
            printf("\nMemória Insuficiente, Lista NÃO Alocada.\n");
          else{
            printf("\nLista Alocada.\n");
            alloc = 1;
          }//else if
        }//else if
        o = 8;
        break;
      case 2: //Consultar Aluno
        if(!alloc)
          printf("\nLista NÃO Alocada.\n");
        else
          consultaLista(lista);
        o = 8;
        break;
      case 3: //Inserir Aluno
        if(!alloc)
          printf("\nLista NÃO Alocada.\n");
        else
          insereLista(lista);
        o = 8;
        break;
      case 4: //Remover Aluno
        if(!alloc)
          printf("\nLista NÃO Alocada.\n");
        else
          removeLista(lista);
        o = 8;
        break;
      case 5: //Lista Cheia Vazia
        if(!alloc)
          printf("\nLista NÃO Alocada.\n");
        else
          tamanhoLista(lista);
        o = 8;
        break;
      case 6: //Imprime Lista
        if(!alloc)
          printf("\nLista NÃO Alocada.\n");
        else
          imprimeLista(lista);
        o = 8;
        break;
      case 7: //Destrói Lista
        if(!alloc)
          printf("\nLista NÃO Alocada.\n");
        else{
          libera_lista(lista);
          printf("\nLista Destruída.\n");
          alloc = 0;
        }//else if
        o = 8;
        break;
      default:
        printf("\nOpção Inválida.\n");
        o = 8;
        break;
    }//switch
  }//while

  printf("\nAté Logo!!\n");
  return 0;
}//main

void consultaLista(Lista* li){
  int mat, pos, res;
  unsigned int o;
  Aluno aluno;

  printf("\n<< Consultar Aluno >>\n");
  printf("1 - Consultar por posição.\n");
  printf("2 - Consultar por matrícula.\n");
  printf("3 - Voltar ao menu principal.\n\n");
  printf("Digite uma opção: ");
  scanf("%u", &o);
  while(!o || o > 3){
    printf("\nOPÇÃO INVÁLIDA.\n");
    printf("Digite uma opção válida: ");
    scanf("%u", &o);
  }//while

  if(o == 1){
    printf("Qual a posição do aluno que deseja consultar? ");
    scanf("%d", &pos);
    res = consulta_lista_pos(li, pos, &aluno);
  }else if(o == 2){
    printf("Qual a matrícula do aluno que deseja consultar? ");
    scanf("%d", &mat);
    res = consulta_lista_mat(li, mat, &aluno);
  }else
    return;

  if(res == -1)
    printf("\nMemória Insuficiente.\n");
  else if(res == -2)
    printf("\nAluno Inexistente.\n");
  else
    imprimeAluno(aluno);

  return;
}//consultaLista

void insereLista(Lista* li){
  int mat, pos, res;
  unsigned int o;
  Aluno* aluno = malloc(sizeof(Aluno));
  if(!aluno){
    printf("\nMemória Insuficiente.\n");
    return;
  }//if

  printf("\n<< Inserir Aluno >>\n");
  printf("1 - Final da lista.\n");
  printf("2 - Início da lista.\n");
  printf("3 - Posição específica.\n");
  printf("4 - Lista ordenada.\n");
  printf("5 - Voltar ao menu principal.\n\n");
  printf("Digite uma opção: ");
  scanf("%u", &o);
  while(!o || o > 5){
    printf("\nOPÇÃO INVÁLIDA.\n");
    printf("Digite uma opção válida: ");
    scanf("%u", &o);
  }//while
  getchar();

  if(o == 5){
    free(aluno);
    return;
  }//if

  if(leAluno(aluno)){
    printf("\nErro ao ler dados do aluno.\n");
    return;
  }//if

  if(o == 1)
    res = insere_lista_final(li, *aluno);
  else if(o == 2)
    res = insere_lista_inicio(li, *aluno);
  else if(o == 3){
    printf("Em qual posição o aluno deve ser inserido? ");
    scanf("%d", &pos);
    res = insere_lista_pos(li, pos, *aluno);
  }else if(o == 4)
    res = insere_lista_ordenada(li, *aluno);

  if(res == -1)
    printf("\nMemória Insuficiente.\n");
  else if(res == -2)
    printf("\nAluno Inexistente.\n");
  else
    printf("\nAluno inserido.\n");

  free(aluno);
  return;
}//insereLista

void removeLista(Lista* li){
  unsigned int o;
  int mat, res;

  printf("\n<< Remover Aluno >>\n");
  printf("1 - Remove aluno por matrícula.\n");
  printf("2 - Remove primeiro aluno.\n");
  printf("3 - Remove último aluno.\n");
  printf("4 - Voltar ao menu principal.\n\n");
  printf("Digite uma opção: ");
  scanf("%u", &o);
  while(!o || o > 4){
    printf("\nOPÇÃO INVÁLIDA.\n");
    printf("Digite uma opção válida: ");
    scanf("%u", &o);
  }//while

  if(o == 1){
    printf("Qual a matrícula do aluno que deve ser removido? ");
    scanf("%d", &mat);
    res = remove_lista(li, mat);
  }else if(o == 2)
    res = remove_lista_inicio(li);
  else if(o == 3)
    res = remove_lista_final(li);
  else
    return;

    if(res == -1)
      printf("\nMemória Insuficiente.\n");
    else if(res == -2)
      printf("\nAluno Inexistente.\n");
    else
      printf("\nAluno removido.\n");

    return;
}//removeLista

void tamanhoLista(Lista* li){
  int res;

  res = tamanho_lista(li);
  if(res == -1)
    printf("\nLista NÃO Alocada.\n");
  else
    printf("\nA Lista possui %d elemento(s).\n", res);

  res = lista_cheia(li);
  if(res == -1)
    printf("\nLista NÃO Alocada.\n");
  else if(res == 1)
    printf("\nMemória Cheia.\n");
  else
    printf("\nMemória não está cheia.\n");

  res = lista_vazia(li);
  if(res == -1)
    printf("\nLista NÃO Alocada.\n");
  else if(res == 1)
    printf("\nLista Vazia.\n");
  else
    printf("\nLista não está vazia.\n");

  return;
}//tamanhoLista

void imprimeLista(Lista* li){
  int res = imprime_lista(li);

  if(res == -1)
    printf("\nLista NÃO Alocada.\n");
  else if(res == -2)
    printf("\nLista Vazia.\n");

  return;
}//imprimeLista

int leAluno(Aluno* al){
  if(!al){
    printf("\nEstrutura do aluno NÃO alocada.\n");
    return 1;
  }//if

  printf("Digite o nome do Aluno: ");
  if(!fgets(al->nome, sizeof(al->nome), stdin)){
    printf("\nErro ao ler nome do aluno.\n");
    return 1;
  }else
    al->nome[strcspn(al->nome, "\n")] = '\0';
  printf("Digite o número de matrícula: ");
  scanf("%d", &al->matricula);
  printf("Digite a nota da primeira prova: ");
  scanf("%f", &al->n1);
  printf("Digite a nota da segunda prova: ");
  scanf("%f", &al->n2);
  printf("Digite a nota da terceira prova: ");
  scanf("%f", &al->n3);

  return 0;
}//leAluno

void imprimeAluno(Aluno al){
  printf("\n<< Aluno: %s >>\n", al.nome);
  printf("Matrícula: %d\n", al.matricula);
  printf("Nota 1: %.2f\nNota 2: %.2f\nNota 3: %.2f\n", al.n1, al.n2, al.n3);
  printf("\n--------------------\n");

  return;
}//imprimeAluno
