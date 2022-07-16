#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "Student.h"

//Answer to success
#define SUCCESS 0
//Answer to out of memory
#define OUT_OF_MEMORY -1
//Answer to element not found
#define ELEM_NOT_FOUND -2

//Definition to struct queue
typedef struct queue Queue;

//Prototype to queue_create
Queue* queue_create();
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