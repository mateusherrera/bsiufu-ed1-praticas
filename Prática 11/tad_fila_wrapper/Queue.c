#include <stdlib.h>
#include "ListaEncadeada.h"
#include "Queue.h"

// Struct to queue (wrapper - list)
struct queue{
    Lista* list;
};

Queue* queue_create(void){
    Queue* qu = malloc(sizeof(Queue));
    if(qu){
        qu->list = cria_lista();
        if(!qu->list){
            free(qu);
            return NULL;
        }// if
    }// if

    return qu;
}// queue_create

void queue_free(Queue* qu){
    if(qu){
        libera_lista(qu->list);
        free(qu);
    }// if

    return;
}// queue_free

int queue_push(Queue* qu, Student stu){
    if(!qu)
        return OUT_OF_MEMORY;

    return insere_lista_inicio(qu->list, stu);
}// queue_push

int queue_pop(Queue* qu){
    if(!qu)
        return OUT_OF_MEMORY;

    return remove_lista_final(qu->list);
}// queue_pop

int queue_top(Queue* qu, Student* stu){
    if(!qu)
        return OUT_OF_MEMORY;

    return consulta_lista_pos(qu->list, tamanho_lista(qu->list), stu);
}// queue_top

int queue_empty(Queue* qu){
    if(!qu)
        return OUT_OF_MEMORY;

    return lista_vazia(qu->list);
}// queue_empty

int queue_size(Queue* qu){
    if(!qu)
        return OUT_OF_MEMORY;

    return tamanho_lista(qu->list);
}// queue_size