#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Student.h"

//Answer to success
#define SUCCESS 0
//Answer to out of memory
#define OUT_OF_MEMORY -1
//Answer to element not found
#define ELEM_NOT_FOUND -2

//Definition to struct stack
typedef struct stack Stack;

//Prototype to stack_create
Stack* stack_create();
//Prototype to stack_free
void stack_free(Stack*);
//Prototype to stack_push
int stack_push(Stack*, Student);
//Prototype to stack_pop
int stack_pop(Stack*);
//Prototype to stack_top
int stack_top(Stack*, Student*);
//Prototype to stack_empty
int stack_empty(Stack*);
//Prototype to stack_size
int stack_size(Stack*);

#endif