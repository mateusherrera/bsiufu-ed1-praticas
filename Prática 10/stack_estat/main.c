#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

//Prototype of pushStack
void pushStack(Stack*);
//Prototype of popStack
void popStack(Stack*);
//Prototype of topStack
void topStack(Stack*);
//Prototype of isEmpty
void isEmpty(Stack*);
//Prototype of sizeStack
void sizeStack(Stack*);
//Prototype of inputStudent
Student inputStudent(void);
//Prototype of printStudent
void printStudent(Student);

int main(void){
    unsigned int op = 0, alloc = 0;
    Stack* st;

    while(op != 8){
        switch(op){
            case 0: //Menu Principal
                printf("\n<< MENU PRINCIPAL >>\n");
                printf("1 - Criar Pilha.\n");
                printf("2 - Inserir Pilha.\n");
                printf("3 - Remover Pilha.\n");
                printf("4 - Topo da Pilha.\n");
                printf("5 - Pilha Vazia.\n");
                printf("6 - Tamanho da Pilha.\n");
                printf("7 - Destruir Pilha.\n");
                printf("8 - Sair.\n\n");
                printf("Digite uma opção: ");
                scanf("%u", &op);
                if(!op) op = 9;
                break;
            case 1: //Criar Pilha
                if(alloc)
                    printf("\nPilha já alocada.\n");
                else{
                    st = stack_create();
                    if(!st){
                        printf("\nMemória Insuficiente.\n");
                        exit(1);
                    }//if
                    alloc = 1;
                    printf("\nPilha Alocada.\n");
                }//else if
                op = 0;
                break;
            case 2: //Inserir Pilha
                if(!alloc)
                    printf("\nPilha não alocada.\n");
                else
                    pushStack(st);
                op = 0;
                break;
            case 3: //Remover Pilha
                if(!alloc)
                    printf("\nPilha não alocada.\n");
                else
                    popStack(st);
                op = 0;
                break;
            case 4: //Topo da Pilha
                if(!alloc)
                    printf("\nPilha não alocada.\n");
                else
                    topStack(st);
                op = 0;
                break;
            case 5: //Pilha Vazia
                if(!alloc)
                    printf("\nPilha não alocada.\n");
                else
                    isEmpty(st);
                op = 0;
                break;
            case 6: //Tamanho da Pilha
                if(!alloc)
                    printf("\nPilha não alocada.\n");
                else
                    sizeStack(st);
                op = 0;
                break;
            case 7: //Destruir Pilha
                if(!alloc)
                    printf("\nPilha não alocada.\n");
                else{
                    stack_free(st);
                    printf("\nPilha Destruída.\n");
                    alloc = 0;
                }//else if
                op = 0;
                break;
            default: //Opção Inválida
                printf("\nOpção Inválida!!\n");
                printf("Digite uma opção válida: ");
                scanf("%u", &op);
                if(!op) op = 9;
                break;
        }//switch
    }//while

    if(alloc){
        stack_free(st);
        printf("\nPilha Destruída.\n");
    }//if

    printf("\nAté Logo!!\n");
    return 0;
}//main

void pushStack(Stack* st){
    Student stu;
    int res;

    getchar();
    stu = inputStudent();
    res = stack_push(st, stu);

    if(res == -1)
        printf("\nMemória Insuficiente.\n");
    else if(res == -2)
        printf("\nElemento não encontrado.\n");
    else
        printf("\nAluno Inserido.\n");

    return;
}//pushStack

void popStack(Stack* st){
    int res = stack_pop(st);

    if(res == -1)
        printf("\nMemória Insuficiente.\n");
    else if(res == -2)
        printf("\nElemento não encontrado.\n");
    else
        printf("\nAluno Removido do Topo.\n");

    return;
}//popStack

void topStack(Stack* st){
    Student stu;
    int res = stack_top(st, &stu);

    if(res == -1)
        printf("\nMemória Insuficiente.\n");
    else if(res == -2)
        printf("\nElemento não encontrado.\n");

    printStudent(stu);

    return;
}//topStack

void isEmpty(Stack* st){
    int res = stack_empty(st);

    if(res == -1)
        printf("\nMemória Insuficiente.\n");
    else if(res)
        printf("\nPilha Vazia.\n");
    else
        printf("\nPilha NÃO está Vazia.\n");

    return;
}//isEmpty

void sizeStack(Stack* st){
    int size = stack_size(st);

    if(size == -1)
        printf("\nMemória Insuficiente.\n");
    else
        printf("\nA Pilha possui %d aluno(s).\n", size);

    return;
}//sizeStack

Student inputStudent(void){
    Student stu;

    printf("Digite o nome do aluno: ");
    if(!fgets(stu.name, sizeof(stu.name), stdin)){
        printf("\nErro ao ler nome.\n");
        exit(1);
    }else
        stu.name[strcspn(stu.name, "\n")] = '\0';
    printf("Digite a matrícula do aluno: ");
    scanf("%d", &stu.reg);
    printf("Digite a nota da primeira prova: ");
    scanf("%f", &stu.t1);
    printf("Digite a nota da segunda prova: ");
    scanf("%f", &stu.t2);
    printf("Digite a nota da terceira prova: ");
    scanf("%f", &stu.t3);

    return stu;
}//inputStudent

void printStudent(Student stu){
    printf("\n<< Aluno: %s >>\n", stu.name);
    printf("<< Matrícula: %d >>\n", stu.reg);
    printf("<< 1ª prova: %.2f pts >>\n", stu.t1);
    printf("<< 2ª prova: %.2f pts >>\n", stu.t2);
    printf("<< 3ª prova: %.2f pts >>\n", stu.t3);

    return;
}//printStudent