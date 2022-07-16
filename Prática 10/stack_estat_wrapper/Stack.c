#include <stdlib.h>
#include "ListaSequencial.h"
#include "Stack.h"

// Struct to stack (wrapper - list)
struct stack{
    Lista* list;
};

Stack* stack_create(void){
    Stack* st = malloc(sizeof(Stack));
    if(st){
        st->list = criaLista();
        if(!st->list){
            free(st);
            return NULL;
        }// if
    }// if

    return st;
}// stack_create

void stack_free(Stack* st){
    if(st){
        liberaLista(st->list);
        free(st);
    }// if

    return;
}// stack_free

int stack_push(Stack* st, Student stu){
    if(!st)
        return OUT_OF_MEMORY;

    return insereListaFinal(st->list, stu);
}// stack_push

int stack_pop(Stack* st){
    if(!st)
       return OUT_OF_MEMORY;

    return removeListaFinal(st->list);
}// stack_pop

int stack_top(Stack* st, Student* stu){
    if(!st)
        return OUT_OF_MEMORY;

    return consultaListaPos(st->list, tamLista(st->list), stu);
}// stack_top

int stack_empty(Stack* st){
    if(!st)
        return OUT_OF_MEMORY;

    return listaVazia(st->list);
}// stack_empty

int stack_size(Stack* st){
    if(!st)
        return OUT_OF_MEMORY;

    return tamLista(st->list);
}// stack_size