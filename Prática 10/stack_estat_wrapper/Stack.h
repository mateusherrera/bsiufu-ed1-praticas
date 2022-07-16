#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Student.h"

//Definition to struct aluno
typedef struct aluno Student;
//Definition to struct stack
typedef struct stack Stack;

//Prototype to stack_create
Stack* stack_create(void);
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