#include <stdlib.h>
#include "Stack.h"

//Definition of struct node
typedef struct node Node;

struct node{
    char c;
    Node* next;
};//struct node

struct stack{
    Node* head;
    int size;
};//struct stack

Stack* stack_create(){
    Stack* st = malloc(sizeof(Stack));

    if(!st)
        return NULL;
    st->head = NULL;
    st->size = 0;

    return st;
}//stack_create

void stack_free(Stack* st){
    Node* aux;

    if(st){
        for(aux = st->head; st->head; aux = st->head){
            st->head = aux->next;
            free(aux);
        }//for
        free(st);
    }//if

    return;
}//stack_free

int stack_push(Stack* st, char c){
    Node* nwnode;
    if(!st)
        return OUT_OF_MEMORY;

    nwnode = malloc(sizeof(Node));
    if(!nwnode)
        return OUT_OF_MEMORY;

    nwnode->c = c;
    nwnode->next = st->head;
    st->head = nwnode;
    st->size++;

    return SUCCESS;
}//stack_push

int stack_pop(Stack* st){
    Node* rm;

    if(!st)
        return OUT_OF_MEMORY;
    if(!st->head)
        return ELEM_NOT_FOUND;

    rm = st->head;
    st->head = rm->next;
    free(rm);
    st->size--;

    return SUCCESS;
}//stack_pop

int stack_top(Stack* st, char* c){
    if(!st)
        return OUT_OF_MEMORY;
    if(!st->head)
        return ELEM_NOT_FOUND;

    *c = st->head->c;

    return SUCCESS;
}//stack_top

int stack_empty(Stack* st){
    if(!st)
        return OUT_OF_MEMORY;

    if(st->head)
        return 0; //False that the stack is empty
    else
        return 1; //True that the stack is empty
}//stack_empty

int stack_size(Stack* st){
    if(!st)
        return OUT_OF_MEMORY;

    return st->size;
}//stack_size