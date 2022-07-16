#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLList.h"

//Protótipo de consultaLista
void consultaLista(List*);
//Protótipo de insereLista
void insereLista(List*);
//Protótipo de removeLista
void removeLista(List*);
//Protótipo de listaCheiaVazia
void tamanhoLista(List*);
//Protótipo de imprimeLista
void imprimeLista(List*);
//Protótipo de leAluno
int leAluno(Student*);
//Protótipo de imprimirAluno
void imprimeAluno(Student);

int main(void){
  unsigned int o = 8, alloc = 0;
  List* lista;

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
        if(o == 8){
          o = 0;
          if(alloc){
            free_list(lista);
            printf("\nLista Liberada.\n");
          }//if
        }//if
        else if(o == 0) o = 9;
        break;
      case 1: //Criar Lista
        if(alloc)
          printf("\nLista JÁ Alocada.\n");
        else{
          lista = create_list();
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
      o = 8;
        if(!alloc)
          printf("\nLista NÃO Alocada.\n");
        else{
          free_list(lista);
          printf("\nLista Destruída.\n");
          alloc = 0;
        }//else if
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

void consultaLista(List* li){
  int mat, pos, res;
  unsigned int o;
  Student aluno;

  printf("\n<< Consultar Aluno >>\n");
  printf("1 - Consultar por posição.\n");
  printf("2 - Consultar por matrícula.\n");
  printf("3 - Consultar primeiro aluno.\n");
  printf("4 - Consultar último aluno.\n");
  printf("5 - Consultar posição de aluno.\n");
  printf("6 - Voltar ao menu principal.\n\n");
  printf("Digite uma opção: ");
  scanf("%u", &o);
  while(!o || o > 6){
    printf("\nOPÇÃO INVÁLIDA.\n");
    printf("Digite uma opção válida: ");
    scanf("%u", &o);
  }//while

  if(o == 1){
    printf("Qual a posição do aluno que deseja consultar? ");
    scanf("%d", &pos);
    res = list_find_pos(li, pos, &aluno);
  }else if(o == 2){
    printf("Qual a matrícula do aluno que deseja consultar? ");
    scanf("%d", &mat);
    res = list_find_reg(li, mat, &aluno); //list_find_mat
  }else if(o == 3)
    res = list_front(li, &aluno);
  else if(o == 4)
    res = list_back(li, &aluno);
  else if(o == 5){
    printf("Qual a matrícula do aluno que deseja ter a posição? ");
    scanf("%d", &mat);
    res = list_get_pos(li, mat, &pos);
  }else
    return;

  if(res == -1)
    printf("\nMemória Insuficiente.\n");
  else if(res == -2)
    printf("\nAluno Inexistente.\n");
  else if(o == 5)
    printf("A posição do aluno de matrícula %d é %d.\n", mat, pos);
  else
    imprimeAluno(aluno);

  return;
}//consultaLista

void insereLista(List* li){
  int mat, pos, res;
  unsigned int o;
  Student* aluno = malloc(sizeof(Student));
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
    res = list_push_back(li, *aluno);
  else if(o == 2)
    res = list_push_front(li, *aluno);
  else if(o == 3){
    printf("Em qual posição o aluno deve ser inserido? ");
    scanf("%d", &pos);
    res = list_insert(li, pos, *aluno);
  }else if(o == 4)
    res = list_insert_reg(li, *aluno);

  if(res == -1)
    printf("\nMemória Insuficiente.\n");
  else if(res == -2)
    printf("\nAluno Inexistente.\n");
  else if(res == -3)
    printf("\nTipo de Lista Incompatível.\n");
  else
    printf("\nAluno inserido.\n");

  free(aluno);
  return;
}//insereLista

void removeLista(List* li){
  unsigned int o;
  int pos, res;

  printf("\n<< Remover Aluno >>\n");
  printf("1 - Remove aluno.\n");
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
    printf("Qual a posição do aluno que deve ser removido? ");
    scanf("%d", &pos);
    res = list_erase(li, pos);
  }else if(o == 2)
    res = list_pop_front(li);
  else if(o == 3)
    res = list_pop_back(li);
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

void tamanhoLista(List* li){
  int res;

  res = list_find_size(li);
  if(res == -1)
    printf("\nLista NÃO Alocada.\n");
  else
    printf("\nA Lista possui %d elemento(s).\n", res);

  res = list_full(li);
  if(res == -1)
    printf("\nLista NÃO Alocada.\n");
  else if(res == 1)
    printf("\nMemória Cheia.\n");
  else
    printf("\nMemória não está cheia.\n");

  res = list_empty(li);
  if(res == -1)
    printf("\nLista NÃO Alocada.\n");
  else if(res == 1)
    printf("\nLista Vazia.\n");
  else
    printf("\nLista não está vazia.\n");

  return;
}//tamanhoLista

void imprimeLista(List* li){
  unsigned int o;
  int res;

  printf("\n<< Imprime Lista >>\n");
  printf("1 - Imprime Lista.\n");
  printf("2 - Imprime Lista Reversa.\n");
  printf("3 - Voltar ao menu principal.\n\n");
  printf("Digite uma opção: ");
  scanf("%u", &o);
  while(!o || o > 3){
    printf("\nOPÇÃO INVÁLIDA.\n");
    printf("Digite uma opção válida: ");
    scanf("%u", &o);
  }//while

  if(o == 1)
    res = print_forward_list(li);
  else if(o == 2)
    res = print_reverse_list(li);
  else
    return;

  if(res == -1)
    printf("\nLista NÃO Alocada.\n");
  else if(res == -2)
    printf("\nLista Vazia.\n");

  return;
}//imprimeLista

int leAluno(Student* al){
  if(!al){
    printf("\nEstrutura do aluno NÃO alocada.\n");
    return 1;
  }//if

  printf("Digite o nome do Aluno: ");
  if(!fgets(al->name, sizeof(al->name), stdin)){
    printf("\nErro ao ler nome do aluno.\n");
    return 1;
  }else
    al->name[strcspn(al->name, "\n")] = '\0';
  printf("Digite o número de matrícula: ");
  scanf("%d", &al->reg);
  printf("Digite a nota da primeira prova: ");
  scanf("%f", &al->t1);
  printf("Digite a nota da segunda prova: ");
  scanf("%f", &al->t2);
  printf("Digite a nota da terceira prova: ");
  scanf("%f", &al->t3);

  return 0;
}//leAluno

void imprimeAluno(Student al){
  printf("\n<< Student: %s >>\n", al.name);
  printf("Register: %d\n", al.reg);
  printf("Test 1: %.2f\nTest 2: %.2f\nTest 3: %.2f\n", al.t1, al.t2, al.t3);
  printf("\n--------------------\n");

  return;
}//imprimeAluno
