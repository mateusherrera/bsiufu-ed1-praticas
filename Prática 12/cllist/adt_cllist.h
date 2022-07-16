#ifndef CIRCULAR_LINKED_LIST_INCLUDED
#define CIRCULAR_LINKED_LIST_INCLUDED

// Answer to success
#define SUCCESS 0

// Answer to not allocated list
#define NOT_ALLOC_LIST -1

// Answer to element out of range
#define ELEM_OUT_OF_RANGE -2

// Answer to out of memory
#define OUT_OF_MEMORY -3

// Answer to list empty
#define LIST_EMPTY -4

// Definition do struct of student
typedef struct{
    int reg;
    char name[31];
    float t1, t2, t3;
}Student;

// Definition to struct list
typedef struct list List;

// A function that create a circular linked list
List* list_create(void);

// A function that free a circular linked list
void list_free(List*);

// A function that push the data of a student on the begin of the list
int list_push_front(List*, Student);

// A function that push the data of a student on the end of the list
int list_push_back(List*, Student);

// A function that push the data of a student on a specified position of the list
int list_insert(List*, int, Student);

// A function that push the data of a student on a ordered circular linked list
int list_insert_reg(List*, Student);

// A function that find the data of student on a specified position of the list
int list_find_pos(List*, int, Student*);

// A function that find the data of the first student of the list
int list_front(List*, Student*);

// A function that find the data of the last student of the list
int list_back(List*, Student*);

// A fuction that find the next data of a student of the list(the position is a static variable so it just back
//                                                            to the start if it makes a loop or restarting the
//                                                            program).
int list_next(List*, Student*);

// A function that find the position of a student by their register
int list_get_pos(List*, int, int*);

// A function that remove the data of the last student of the list
int list_pop_back(List*);

// A function that remove the data of the first student of the list
int list_pop_front(List*);

// A function that remove the data of a student on a specified position
int list_erase(List*, int);

// A function that return the size of the list
int list_find_size(List*);

// A function that return if the list is empty or not
int list_empty(List*);

// A function that print the list
int list_print(List*);

#endif // CIRCULAR_LINKED_LIST_INCLUDED