//Answer to success
#define SUCCESS 0
//Answer to out of memory
#define OUT_OF_MEMORY -1
//Answer to element not found
#define ELEM_NOT_FOUND -2

//Struct to student
typedef struct{
  float t1, t2, t3;
  char name[30];
  int reg;
}Student;

//Definition to struct list
typedef struct list List;

//Prototype of create_list
List* create_list();
//Prototype of free_list
int free_list(List*);
//Prototype of list_find_pos
int list_find_pos(List*, int, Student*);
//Prototype of list_find_reg
int list_find_reg(List*, int, Student*); //list_find_mat
//Prototype of list_front
int list_front(List*, Student*);
//Prototype of list_back
int list_back(List*, Student*);
//Prototype of list_get_pos
int list_get_pos(List*, int, int*);
//Prototype of list_push_back
int list_push_back(List*, Student);
//Prototype of list_push_front
int list_push_front(List*, Student);
//Prototype of list_insert
int list_insert(List*, int, Student);
//Prototype of list_insert_reg
int list_insert_reg(List*, Student);
//Prototype of list_pop_back
int list_pop_back(List*);
//Prototype of list_pop_front
int list_pop_front(List*);
//Prototype of list_erase
int list_erase(List*, int);
//Prototype of list_find_size
int list_find_size(List*);
//Prototype of list_full
int list_full(List*);
//Prototype of list_empty
int list_empty(List*);
//Prototype of print_list
int print_forward_list(List*);
//Prototype of print_reverse_list
int print_reverse_list(List*);