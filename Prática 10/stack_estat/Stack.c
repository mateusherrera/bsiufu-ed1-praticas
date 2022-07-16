#include <stdlib.h>
#include "Stack.h"

//Struct stack
struct stack{
    Student data[MAX];
    int size;
};

Stack* stack_create(){
    Stack* st = malloc(sizeof(Stack));

    if(st)
        st->size = 0;

    return st;
}//stack_create

void stack_free(Stack* st){
    if(st)
        free(st);

    return;
}//stack_free

int stack_push(Stack* st, Student stu){
    if(!st)
        return OUT_OF_MEMORY;
    if(st->size == MAX)
        return ELEM_NOT_FOUND;

    st->data[st->size] = stu;
    st->size++;

    return SUCCESS;
}//stack_push

int stack_pop(Stack* st){
    if(!st)
        return OUT_OF_MEMORY;
    if(!st->size)
        return ELEM_NOT_FOUND;

    st->size--;

    return SUCCESS;
}//stack_pop

int stack_top(Stack* st, Student* stu){
    if(!st)
        return OUT_OF_MEMORY;
    if(!st->size)
        return ELEM_NOT_FOUND;

    *stu = st->data[st->size - 1];

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