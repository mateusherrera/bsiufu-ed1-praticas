#include <stdlib.h>
#include "Stack.h"

//Definition of struct node
typedef struct node Node;

//Struct stack
struct stack{
    Node* head;
    int size;
};

//Struct node
struct node{
    Student data;
    Node* next;
};

Stack* stack_create(){
    Stack* st = malloc(sizeof(Stack));

    if(st){
        st->head = NULL;
        st->size = 0;
    }//if

    return st;
}//stack_create

void stack_free(Stack* st){
    Node* aux;

    if(st){
        while(st->head){
            aux = st->head;
            st->head = aux->next;
            free(aux);
        }//while
        free(st);
    }//if

    return;
}//stack_free

int stack_push(Stack* st, Student stu){
    Node* nw;

    if(!st)
        return OUT_OF_MEMORY;

    nw = malloc(sizeof(Node));
    if(!nw)
        return OUT_OF_MEMORY;
    nw->data = stu;
    nw->next = st->head;
    st->head = nw;
    st->size++;

    return SUCCESS;
}//stack_push

int stack_pop(Stack* st){
    Node* aux;

    if(!st)
        return OUT_OF_MEMORY;
    if(!st->size)
        return ELEM_NOT_FOUND;

    aux = st->head;
    st->head = aux->next;
    free(aux);
    st->size--;

    return SUCCESS;
}//stack_pop

int stack_top(Stack* st, Student* stu){
    if(!st)
        return OUT_OF_MEMORY;
    if(!st->size)
        return ELEM_NOT_FOUND;

    *stu = st->head->data;

    return SUCCESS;
}//stack_top

int stack_empty(Stack* st){
    if(!st)
        return OUT_OF_MEMORY;

    if(!st->size)
        return 1;
    else
        return 0;
}//stack_empty

int stack_size(Stack* st){
    if(!st)
        return OUT_OF_MEMORY;

    return st->size;
}//stack_size