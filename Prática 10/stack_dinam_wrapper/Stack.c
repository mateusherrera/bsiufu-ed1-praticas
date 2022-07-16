#include <stdlib.h>
#include "ListaEncadeada.h"
#include "Stack.h"

// Struct to stack (wrapper - list)
struct stack{
    Lista* list;
};

Stack* stack_create(void){
    Stack* st = malloc(sizeof(Stack));
    if(st){
        st->list = cria_lista();
        if(!st->list){
            free(st);
            return NULL;
        }// if
    }// if

    return st;
}// stack_create

void stack_free(Stack* st){
    if(st){
        libera_lista(st->list);
        free(st);
    }// if

    return;
}// stack_free

int stack_push(Stack* st, Student stu){
    if(!st)
        return OUT_OF_MEMORY;

    return insere_lista_inicio(st->list, stu);
}// stack_push

int stack_pop(Stack* st){
    if(!st)
        return OUT_OF_MEMORY;

    return remove_lista_inicio(st->list);
}// stack_pop

int stack_top(Stack* st, Student* stu){
    if(!st)
        return OUT_OF_MEMORY;

    return consulta_lista_pos(st->list, 1, stu);
}// stack_top

int stack_empty(Stack* st){
    if(!st)
        return OUT_OF_MEMORY;

    return lista_vazia(st->list);
}// stack_empty

int stack_size(Stack* st){
    if(!st)
        return OUT_OF_MEMORY;

    return tamanho_lista(st->list);
}// stack_size