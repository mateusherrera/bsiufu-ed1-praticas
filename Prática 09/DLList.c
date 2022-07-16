#include <stdio.h>
#include <stdlib.h>
#include "DLList.h"

typedef struct node Node;

struct list{
  Node* begin;
  Node* end;
  int size;
};

struct node{
  Student data;
  Node* next;
  Node* prev;
};

List* create_list(){
  List* list = malloc(sizeof(List));
  if(!list)
    return NULL;

  list->begin = NULL;
  list->end = NULL;
  list->size = 0;

  return list;
}//create_list

int free_list(List* list){
  Node* aux;
  while(list->begin){
    aux = list->begin;
    list->begin = aux->next;
    free(aux);
  }//while
  free(list);

  return SUCCESS;
}//free_list

int list_find_pos(List* list, int pos, Student* data){
  Node* aux;

  if(!list)
    return OUT_OF_MEMORY;
  if(!list->begin)
    return ELEM_NOT_FOUND;
  if(pos <= 0 || pos > list->size)
    return ELEM_NOT_FOUND;

  aux = list->begin;
  for(int i = 1; aux && i != pos; i++)
    aux = aux->next;

  if(!aux)
    return ELEM_NOT_FOUND;
  *data = aux->data;

  return SUCCESS;
}//list_find_pos

int list_find_reg(List* list, int reg, Student* data){ //list_find_mat
  Node* aux;

  if(!list)
    return OUT_OF_MEMORY;
  if(!list->begin)
    return ELEM_NOT_FOUND;

  aux = list->begin;
  while(aux && aux->data.reg != reg)
    aux = aux->next;

  if(!aux)
    return ELEM_NOT_FOUND;
  *data = aux->data;

  return SUCCESS;
}//list_find_mat

int list_front(List* list, Student* data){
  if(!list)
    return OUT_OF_MEMORY;
  if(!list->begin)
    return ELEM_NOT_FOUND;

  *data = list->begin->data;

  return SUCCESS;
}//list_front

int list_back(List* list, Student* data){
  if(!list)
    return OUT_OF_MEMORY;
  if(!list->begin)
    return ELEM_NOT_FOUND;

  *data = list->end->data;

  return SUCCESS;
}//list_back

int list_get_pos(List* list, int reg, int* pos){
  Node* aux;
  int i;

  if(!list)
    return OUT_OF_MEMORY;
  if(!list->begin)
    return ELEM_NOT_FOUND;

  aux = list->begin;
  for(i = 1; aux && aux->data.reg != reg; aux = aux->next, i++);
  if(!aux)
    return ELEM_NOT_FOUND;

  *pos = i;
  return SUCCESS;
}//list_get_pos

int list_push_back(List* list, Student data){
  Node* nwnode;

  if(!list)
    return OUT_OF_MEMORY;

  nwnode = malloc(sizeof(Node));
  if(!nwnode)
    return OUT_OF_MEMORY;
  nwnode->data = data;
  nwnode->next = NULL;
  nwnode->prev = list->end;
  if(!list->begin)
    list->begin = nwnode;
  else
    list->end->next = nwnode;
  list->end = nwnode;

  list->size++;
  return SUCCESS;
}//list_push_back

int list_push_front(List* list, Student data){
  Node* nwnode;

  if(!list)
    return OUT_OF_MEMORY;

  nwnode = malloc(sizeof(Node));
  if(!nwnode)
    return OUT_OF_MEMORY;
  nwnode->data = data;
  nwnode->next = list->begin;
  nwnode->prev = NULL;
  if(!list->begin)
    list->end = nwnode;
  else
    list->begin->prev = nwnode;
  list->begin = nwnode;

  list->size++;
  return SUCCESS;
}//list_push_front

int list_insert(List* list, int pos, Student data){
  Node* nwnode;
  Node* aux;

  if(!list)
    return OUT_OF_MEMORY;
  if(pos <= 0 || pos > list->size + 1)
    return ELEM_NOT_FOUND;

  if(pos == 1)
    list_push_front(list, data);
  else if(pos == list->size + 1)
    list_push_back(list, data);
  else{
    aux = list->begin->next;
    for(int i = 2; aux && i != pos; i++)
      aux = aux->next;

    if(!aux)
      return ELEM_NOT_FOUND;

    nwnode = malloc(sizeof(Node));
    if(!nwnode)
      return OUT_OF_MEMORY;
    nwnode->data = data;
    nwnode->next = aux;
    nwnode->prev = aux->prev;
    aux->prev = nwnode;
    nwnode->prev->next = nwnode;
    list->size++;
  }//else if

  return SUCCESS;
}//list_insert

int list_insert_reg(List* list, Student data){
  Node* nwnode;
  Node* aux;

  if(!list)
    return OUT_OF_MEMORY;

  if(!list->begin || list->begin->data.reg >= data.reg)
    list_push_front(list, data);
  else if(list->end->data.reg <= data.reg)
    list_push_back(list, data);
  else{
    aux = list->begin->next;
    while(aux && aux->data.reg < data.reg)
      aux = aux->next;

    if(!aux)
      list_push_back(list, data);
    else{
      nwnode = malloc(sizeof(Node));
      if(!nwnode)
        return OUT_OF_MEMORY;
      nwnode->data = data;
      nwnode->next = aux;
      nwnode->prev = aux->prev;
      nwnode->prev->next = nwnode;
      nwnode->next->prev = nwnode;
      list->size++;
    }//else if
  }//else if

  return SUCCESS;
}//list_insert_reg

int list_pop_back(List* list){
  Node* rm;

  if(!list)
    return OUT_OF_MEMORY;
  if(!list->begin)
    return ELEM_NOT_FOUND;

  rm = list->end;
  if(rm == list->begin){
    list->begin = NULL;
    list->end = NULL;
  }else{
    list->end = rm->prev;
    list->end->next = NULL;
  }//else if
  free(rm);

  list->size--;
  return SUCCESS;
}//list_pop_back

int list_pop_front(List* list){
  Node* rm;

  if(!list)
    return OUT_OF_MEMORY;
  if(!list->begin)
    return ELEM_NOT_FOUND;

  rm = list->begin;
  if(rm == list->end){
    list->begin = NULL;
    list->end = NULL;
  }else{
    list->begin = rm->next;
    list->begin->prev = NULL;
  }//else if
  free(rm);

  list->size--;
  return SUCCESS;
}//list_pop_front

int list_erase(List* list, int pos){
  Node* rm;

  if(!list)
    return OUT_OF_MEMORY;
  if(!list->begin)
    return ELEM_NOT_FOUND;

  if(pos == 1)
    list_pop_front(list);
  else if(pos == list->size)
    list_pop_back(list);
  else{
    rm = list->begin->next;
    for(int i = 2; rm && i != pos; i++, rm = rm->next);

    if(!rm)
      return ELEM_NOT_FOUND;

    rm->prev->next = rm->next;
    rm->next->prev = rm->prev;
    free(rm);
    list->size--;
  }//else if

  return SUCCESS;
}//list_erase

int list_find_size(List* list){
  if(!list)
    return OUT_OF_MEMORY;

  return list->size;
}//list_find_size

int list_full(List* list){
  Node* test;
  if(!list)
    return OUT_OF_MEMORY;

  test = malloc(sizeof(Node));
  if(!test)
    return 1;
  free(test);
  return SUCCESS;
}//list_full

int list_empty(List* list){
  if(!list)
    return OUT_OF_MEMORY;

  if(!list->begin)
    return 1;

  return SUCCESS;
}//list_empty

int print_forward_list(List* list){
  Node* aux;

  if(!list)
    return OUT_OF_MEMORY;
  if(!list->begin)
    return ELEM_NOT_FOUND;

  aux = list->begin;
  printf("\n<< Students List >>\n");
  for(int i = 1; aux; i++){
    printf("<< Student %d >>\n", i);
    printf("Name: %s\n", aux->data.name);
    printf("Register: %d\n", aux->data.reg);
    printf("Test 1: %.2f\n", aux->data.t1);
    printf("Test 2: %.2f\n", aux->data.t2);
    printf("Test 3: %.2f\n\n", aux->data.t3);
    aux = aux->next;
  }//for
  printf("<<< ------------------------------ >>>\n");
}//print_list

int print_reverse_list(List* list){
  Node* aux;

  if(!list)
    return OUT_OF_MEMORY;
  if(!list->begin)
    return ELEM_NOT_FOUND;

  aux = list->end;
  printf("\n<< Students List >>\n");
  for(int i = list->size; aux; i--){
    printf("<< Student %d >>\n", i);
    printf("Name: %s\n", aux->data.name);
    printf("Register: %d\n", aux->data.reg);
    printf("Test 1: %.2f\n", aux->data.t1);
    printf("Test 2: %.2f\n", aux->data.t2);
    printf("Test 3: %.2f\n\n", aux->data.t3);
    aux = aux->prev;
  }//for
  printf("<<< ------------------------------ >>>\n");
}//print_reverse_list