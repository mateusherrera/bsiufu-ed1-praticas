#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

// Size of char per name
#define TAM 50
// return to success
#define SUCCESS 0
// return to out of memory
#define OUT_OF_MEMORY -1
// return to element not found
#define ELEM_NOT_FOUND -2
// return to invalid size
#define INVALID_SIZE -3

// Definition to struct queue
typedef struct queue Queue;
// Definition and struct to Student
typedef struct{
    int reg;
    char name[TAM];
    float t1, t2, t3;
}Student;

// A function that create a queue
Queue* queue_create(int);

// A function that free the queue
void queue_free(Queue*);

// A function to push a element on the end of the queue
int queue_push(Queue*, Student);

// A function to pop the first element of the queue
int queue_pop(Queue*);

// A funtion that find the first element of the queue
int queue_top(Queue*, Student*);

// A function that compact the array of student if their's don't need more of a realloc memory
int queue_compact(Queue*);

// A function that return if the list is empty or not
int queue_empty(Queue*);

// A function that return the size of the queue
int queue_size(Queue*);

#endif // QUEUE_H_INCLUDED