#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "Student.h"

//Definition to struct queue
typedef struct queue Queue;
//Definition to struct aluno
typedef struct aluno Student;

//Prototype to queue_create
Queue* queue_create(void);
//Prototype to queue_free
void queue_free(Queue*);
//Prototype to queue_push
int queue_push(Queue*, Student);
//Prototype to queue_pop
int queue_pop(Queue*);
//Prototype to queue_top
int queue_top(Queue*, Student*);
//Prototype to queue_empty
int queue_empty(Queue*);
//Prototype to queue_size
int queue_size(Queue*);

#endif