#include <stdlib.h>
#include <math.h>
#include "Queue.h"

// Struct to queue
struct queue{
    Student* data;
    int initial_capacity, last_capacity;
    int front, rear, size;
};

Queue* queue_create(int size){
    Queue* qu = malloc(sizeof(Queue));
    if(qu && size > 1){
        qu->data = malloc(size * sizeof(Student));
        if(qu->data){
            qu->initial_capacity = size;
            qu->last_capacity = size;
            qu->front = 0;
            qu->rear = 0;
            qu->size = 0;
        }else{
            free(qu);
            qu = NULL;
        }// else if
    }else if(size <= 1){
        free(qu);
        qu = NULL;
    }// else if

    return qu;
}// queue_create

void queue_free(Queue* qu){
    if(qu){
        free(qu->data);
        free(qu);
    }// if

    return;
}// queue_free

int queue_push(Queue* qu, Student stu){
    if(qu){
        if(qu->size == qu->last_capacity){
            qu->last_capacity += qu->initial_capacity;
            if(!realloc(qu->data, qu->last_capacity * sizeof(Student)))
                return OUT_OF_MEMORY;
            qu->rear = qu->size;

            for(int i = 0; i != qu->front; ++i){
                qu->data[qu->rear] = qu->data[i];
                qu->rear = (qu->rear + 1) % qu->last_capacity;
            }// for
        }// if
        qu->data[qu->rear] = stu;
        qu->rear = (qu->rear + 1) % qu->last_capacity;
        ++qu->size;
    }else
        return OUT_OF_MEMORY;

    return SUCCESS;
}// queue_push

int queue_pop(Queue* qu){
    if(qu){
        if(qu->size){
            if(qu->size == 1){
                qu->front = 0;
                qu->rear = 0;
            }else
                qu->front = (qu->front + 1) % qu->last_capacity;
            qu->size--;
        }else
            return ELEM_NOT_FOUND;
    }else
        return OUT_OF_MEMORY;

    return SUCCESS;
}// queue_pop

int queue_top(Queue* qu, Student* stu){
    if(qu){
        if(qu->size)
            *stu = qu->data[qu->front];
        else
            return ELEM_NOT_FOUND;
    }else
        return OUT_OF_MEMORY;

    return SUCCESS;
}// queue_top

int queue_compact(Queue* qu){
    if(qu){
        int aux = (ceil((double)(qu->size / qu->initial_capacity))) * qu->initial_capacity;
        if(aux && qu->size != qu->last_capacity){
            if(qu->rear > qu->front){
                int i;
                for(i = 0; qu->front != qu->rear; ++i, ++qu->front)
                    qu->data[i] = qu->data[qu->front];
                qu->front = 0;
                qu->rear = i;
            }else{
                int i = qu->rear;
                while(qu->front != i){
                    qu->data[qu->rear] = qu->data[qu->front];
                    qu->front = (qu->front + 1) % aux;
                    qu->rear = (qu->rear + 1) % aux;
                }// while
            }// else if

            qu->last_capacity = aux;
            if(!realloc(qu->data, qu->last_capacity * sizeof(Student)))
                return OUT_OF_MEMORY;
        }else if(!aux){
            qu->last_capacity = qu->initial_capacity;
            if(!realloc(qu->data, qu->initial_capacity * sizeof(Student)))
                return OUT_OF_MEMORY;
        }// else if
    }else
        return OUT_OF_MEMORY;

    return SUCCESS;
}// queue_compact

int queue_empty(Queue* qu){
    if(qu){
        if(!qu->size)
            return 1;
        else
            return 0;
    }else
        return OUT_OF_MEMORY;
}// queue_empty

int queue_size(Queue* qu){
    if(qu)
        return qu->size;
    else
        return OUT_OF_MEMORY;
}// queue_size