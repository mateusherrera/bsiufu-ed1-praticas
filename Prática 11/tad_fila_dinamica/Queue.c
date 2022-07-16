#include <stdlib.h>
#include "Queue.h"

//Definition of struct node
typedef struct node Node;

//Struct queue
struct queue{
    Node* begin;
    Node* end;
    int size;
};

//Struct node
struct node{
    Student data;
    Node* next;
};

Queue* queue_create(){
    Queue* qu = malloc(sizeof(Queue));

    if(qu){
        qu->begin = NULL;
        qu->end = NULL;
        qu->size = 0;
    }//if

    return qu;
}//queue_create

void queue_free(Queue* qu){
    Node* aux;

    if(qu){
        while(qu->begin){
            aux = qu->begin;
            qu->begin = aux->next;
            free(aux);
        }//while
        free(qu);
    }//if

    return;
}//queue_free

int queue_push(Queue* qu, Student stu){
    Node* nw;

    if(!qu)
        return OUT_OF_MEMORY;

    nw = malloc(sizeof(Node));
    if(!nw)
        return OUT_OF_MEMORY;
    nw->data = stu;
    nw->next = qu->begin;
    qu->begin = nw;
    if(!qu->end)
        qu->end = nw;
    qu->size++;

    return SUCCESS;
}//queue_push

int queue_pop(Queue* qu){
    Node* aux;

    if(!qu)
        return OUT_OF_MEMORY;
    if(!qu->size)
        return ELEM_NOT_FOUND;

    if(qu->begin == qu->end){
        qu->begin = NULL;
        qu->end = NULL;
    }else{
        for(aux = qu->begin; aux->next != qu->end; aux = aux->next);
        qu->end = aux;
        free(aux->next);
        aux->next = NULL;
    }// else
    qu->size--;

    return SUCCESS;
}//queue_pop

int queue_top(Queue* qu, Student* stu){
    if(!qu)
        return OUT_OF_MEMORY;
    if(!qu->size)
        return ELEM_NOT_FOUND;

    *stu = qu->end->data;

    return SUCCESS;
}//queue_top

int queue_empty(Queue* qu){
    if(!qu)
        return OUT_OF_MEMORY;

    if(!qu->size)
        return 1;
    else
        return 0;
}//queue_empty

int queue_size(Queue* qu){
    if(!qu)
        return OUT_OF_MEMORY;

    return qu->size;
}//queue_size