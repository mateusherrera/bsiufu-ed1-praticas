#include <stdio.h>
#include <stdlib.h>
#include "adt_cllist.h"

// Definition of Node type
typedef struct node Node;

// Struct of a circular linked list
struct list{
    Node* end;
    int size;
    int cur;
};

// Struct of a node to a circular linked list
struct node{
    Student data;
    Node* next;
};

List* list_create(void){
    List* li = malloc(sizeof(List));

    if(li){
        li->end = NULL;
        li->size = 0;
        li->cur = 1;
    }// if

    return li;
}// list_create

void list_free(List* li){
    if(li){
        if(li->end){
            Node* rm;
            for(rm = li->end->next; rm != li->end; rm = rm->next)
                free(rm);
            free(rm);
        }// if
        free(li);
    }// if

    return;
}// list_free

int list_push_front(List* li, Student stu){
    if(li){
        Node* nwnode = malloc(sizeof(Node));
        if(!nwnode)
            return OUT_OF_MEMORY;

        nwnode->data = stu;
        if(li->size){
            nwnode->next = li->end->next;
            li->end->next = nwnode;
        }else{
            nwnode->next = nwnode;
            li->end = nwnode;
        }// else if
        ++li->size;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_push_front

int list_push_back(List* li, Student stu){
    if(li){
        Node* nwnode = malloc(sizeof(Node));
        if(!nwnode)
            return OUT_OF_MEMORY;

        nwnode->data = stu;
        if(li->size){
            nwnode->next = li->end->next;
            li->end->next = nwnode;
        }else
            nwnode->next = nwnode;
        li->end = nwnode;
        ++li->size;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_push_back

int list_insert(List* li, int pos, Student stu){
    if(li){
        if(pos > 0 && pos <= li->size + 1){
            if(!li->size && pos != 1)
                return ELEM_OUT_OF_RANGE;

            else if(pos == 1)
                return list_push_front(li, stu);

            else if(pos == li->size + 1)
                return list_push_back(li, stu);

            else{
                Node* aux = li->end->next;

                for(int i = 2; aux != li->end && i != pos; ++i, aux = aux->next);

                if(aux != li->end){
                    Node* nwnode = malloc(sizeof(Node));
                    if(!nwnode)
                        return OUT_OF_MEMORY;

                    nwnode->data = stu;
                    nwnode->next = aux->next;
                    aux->next = nwnode;
                    ++li->size;
                }else
                    return ELEM_OUT_OF_RANGE;
            }// else if
        }else
            return ELEM_OUT_OF_RANGE;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_insert

int list_insert_reg(List* li, Student stu){
    if(li){
        if(!li->end || li->end->next->data.reg >= stu.reg)
            return list_push_front(li, stu);

        else if(li->end->data.reg < stu.reg)
            return list_push_back(li, stu);

        else{
            Node* aux;
            Node* nwnode = malloc(sizeof(Node));
            if(!nwnode)
                return OUT_OF_MEMORY;

            for(aux = li->end; aux->next->data.reg < stu.reg; aux = aux->next);

            nwnode->data = stu;
            nwnode->next = aux->next;
            aux->next = nwnode;
            ++li->size;
        }// else if
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_insert_reg

int list_find_pos(List* li, int pos, Student* stu){
    if(li){
        if(li->size && pos <= li->size && pos > 0){
            if(pos == 1)
                return list_front(li, stu);

            else if(pos == li->size)
                return list_back(li, stu);

            else{
                int aux_pos;
                Node* aux_node = li->end->next;

                for(aux_pos = 1; aux_pos != pos; ++aux_pos, aux_node = aux_node->next);

                *stu = aux_node->data;
            }// else if
        }else if(!li->size)
            return LIST_EMPTY;
        else
            return ELEM_OUT_OF_RANGE;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_find_pos

int list_front(List* li, Student* stu){
    if(li){
        if(li->size)
            *stu = li->end->next->data;
        else
            return LIST_EMPTY;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_front

int list_back(List* li, Student* stu){
    if(li){
        if(li->size)
            *stu = li->end->data;
        else
            return LIST_EMPTY;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_back

int list_next(List* li, Student* stu){
    if(li){
        if(li->size){
            if(li->cur > li->size)
                li->cur = 1;

            ++li->cur;
            return list_find_pos(li, li->cur - 1, stu);
        }else
            return LIST_EMPTY;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_next

int list_get_pos(List* li, int reg, int* pos){
    if(li){
        if(li->size){
            if(li->end->next->data.reg == reg)
                *pos = 1;

            else if(li->end->data.reg == reg)
                *pos = li->size;

            else{
                Node* aux = li->end->next;
                int i;
                for(i = 1; aux->data.reg != reg && i != li->size + 1; ++i, aux = aux->next);

                if(i <= li->size)
                    *pos = i;
                else
                    return ELEM_OUT_OF_RANGE;
            }// else if
        }else
            return LIST_EMPTY;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_get_pos

int list_pop_back(List* li){
    if(li){
        if(li->size){
            Node* rm = li->end;

            for(li->end = li->end->next; li->end != rm; li->end = li->end->next);

            li->end->next = rm->next;
            free(rm);

            --li->size;
            if(!li->size)
                li->end = NULL;
        }else
            return LIST_EMPTY;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_pop_back

int list_pop_front(List* li){
    if(li){
        if(li->size){
            if(li->size == 1){
                free(li->end);
                li->end = NULL;
            }else{
                Node* rm = li->end->next;
                
                li->end->next = li->end->next->next;
                free(rm);
            }// else if
            --li->size;
        }else
            return LIST_EMPTY;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_pop_front

int list_erase(List* li, int pos){
    if(li){
        if(li->size){
            if(pos > 0 && pos <= li->size){
                if(pos == 1)
                    return list_pop_front(li);

                else if(pos == li->size)
                    return list_pop_back(li);

                else{
                    Node* rm;
                    Node* aux = li->end->next;

                    for(int i = 2; i != pos; ++i, aux = aux->next);
                    rm = aux->next;

                    aux->next = rm->next;
                    free(rm);
                }// else if
            }else
                return ELEM_OUT_OF_RANGE;
        }else
            return LIST_EMPTY;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_erase

int list_find_size(List* li){
    if(li)
        return li->size;
    else
        return NOT_ALLOC_LIST;
}// list_find_size

int list_empty(List* li){
    if(li){
        if(li->size)
            return 0;
        else
            return 1;
    }else
        return NOT_ALLOC_LIST;
}// list_empty

int list_print(List* li){
    if(li){
        if(li->size){
            Node* node_current;
            int i;

            printf("\n<< Lista Circular >>\n");
            for(i = 0, node_current = li->end->next; !i; node_current = node_current->next){
                printf("\n<< %s >>\n", node_current->data.name);
                printf("\t%d\n", node_current->data.reg);
                printf("1ª = %.2f pts.\n", node_current->data.t1);
                printf("2ª = %.2f pts.\n", node_current->data.t2);
                printf("3ª = %.2f pts.\n", node_current->data.t3);
                if(node_current == li->end) ++i;
            }// for
            printf("<< ----- ----- ----- ----- ----- ----- ----- ----- >>\n");
        }else
            return LIST_EMPTY;
    }else
        return NOT_ALLOC_LIST;

    return SUCCESS;
}// list_print