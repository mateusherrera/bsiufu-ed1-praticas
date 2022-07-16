//Define success return
#define SUCCESS 0
//Define out of memory return
#define OUT_OF_MEMORY -1
//Define element not found return
#define ELEM_NOT_FOUND -2

//Stack type definition
typedef struct stack Stack;

//Create a stack
Stack* stack_create();
//Free a stack
void stack_free(Stack*);
//Push a element in the begin
int stack_push(Stack*, char);
//Pop the first element
int stack_pop(Stack*);
//Copy the top element to a variable
int stack_top(Stack*, char*);
//Verify if the stack is empty
int stack_empty(Stack*);
//Return the size of stack
int stack_size(Stack*);