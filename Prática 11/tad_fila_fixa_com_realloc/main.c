#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

//Prototype of pushQueue
void pushQueue(Queue*);
//Prototype of popQueue
void popQueue(Queue*);
//Prototype of topQueue
void topQueue(Queue*);
//Prototype of isEmpty
void isEmpty(Queue*);
//Prototype of sizeQueue
void sizeQueue(Queue*);
//Prototype of inputStudent
Student inputStudent(void);
//Prototype of printStudent
void printStudent(Student);

int main(void){
    unsigned int op = 0, alloc = 0;
    int qtd_init;
    Queue* qu;

    printf("Qual a quantidade inicial de alunos? ");
    scanf("%d", &qtd_init);

    while(op != 10){
        switch(op){
            case 0: //Menu Principal
                printf("\n<< MENU PRINCIPAL >>\n");
                printf("1 - Criar Fila.\n");
                printf("2 - Inserir Fila.\n");
                printf("3 - Remover Fila.\n");
                printf("4 - Topo da Fila.\n");
                printf("5 - Fila Vazia.\n");
                printf("6 - Tamanho da Fila.\n");
                printf("7 - Destruir Fila.\n");
                printf("8 - Compactar Fila.\n");
                printf("9 - Mudar Tamanho da Fila.\n");
                printf("10 - Sair.\n\n");
                printf("Digite uma opção: ");
                scanf("%u", &op);
                if(!op) op = 11;
                break;
            case 1: //Criar Fila
                if(alloc)
                    printf("\nFila já alocada.\n");
                else{
                    qu = queue_create(qtd_init);
                    if(!qu){
                        printf("\nMemória Insuficiente ou tamanho da lista inválida.\n");
                        exit(1);
                    }else{
                        alloc = 1;
                        printf("\nFila Alocada.\n");
                    }// else if
                }//else if
                op = 0;
                break;
            case 2: //Inserir Fila
                if(!alloc)
                    printf("\nFila não alocada.\n");
                else
                    pushQueue(qu);
                op = 0;
                break;
            case 3: //Remover Fila
                if(!alloc)
                    printf("\nFila não alocada.\n");
                else
                    popQueue(qu);
                op = 0;
                break;
            case 4: //Topo da Fila
                if(!alloc)
                    printf("\nFila não alocada.\n");
                else
                    topQueue(qu);
                op = 0;
                break;
            case 5: //Fila Vazia
                if(!alloc)
                    printf("\nFila não alocada.\n");
                else
                    isEmpty(qu);
                op = 0;
                break;
            case 6: //Tamanho da Fila
                if(!alloc)
                    printf("\nFila não alocada.\n");
                else
                    sizeQueue(qu);
                op = 0;
                break;
            case 7: //Destruir Fila
                if(!alloc)
                    printf("\nFila não alocada.\n");
                else{
                    queue_free(qu);
                    printf("\nFila Destruída.\n");
                    printf("Qual a quantidade inicial de alunos? ");
                    scanf("%d", &qtd_init);
                    alloc = 0;
                }//else if
                op = 0;
                break;
            case 8: //Compactar Fila
                if(!alloc)
                    printf("\nFila não alocada.\n");
                else{
                    if(queue_compact(qu))
                        printf("\nFila não compactada.\n");
                    else
                        printf("\nFila compactada.\n");
                }// else if
                op = 0;
                break;
            case 9: //Mudar Tamanho da Fila
                if(alloc){
                    printf("\nFila alocada.\n");
                    printf("Destrua a Fila atual antes de mudar o\n");
                    printf("tamanho inicial da fila, assim a pro-\n");
                    printf("xima fila criada terá o novo tamanho.\n");
                }else{
                    printf("Qual a nova quantidade inicial de alunos? ");
                    scanf("%d", &qtd_init);
                }// else if
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
        queue_free(qu);
        printf("\nFila Destruída.\n");
    }//if

    printf("\nAté Logo!!\n");
    return 0;
}//main

void pushQueue(Queue* qu){
    Student stu;
    int res;

    getchar();
    stu = inputStudent();
    res = queue_push(qu, stu);

    if(res == -1)
        printf("\nMemória Insuficiente.\n");
    else if(res == -2)
        printf("\nElemento não encontrado.\n");
    else
        printf("\nAluno Inserido.\n");

    return;
}//pushQueue

void popQueue(Queue* qu){
    int res = queue_pop(qu);

    if(res == -1)
        printf("\nMemória Insuficiente.\n");
    else if(res == -2)
        printf("\nElemento não encontrado.\n");
    else
        printf("\nAluno Removido do Topo.\n");

    return;
}//popQueue

void topQueue(Queue* qu){
    Student stu;
    int res = queue_top(qu, &stu);

    if(res == -1)
        printf("\nMemória Insuficiente.\n");
    else if(res == -2)
        printf("\nElemento não encontrado.\n");
    else
        printStudent(stu);

    return;
}//topQueue

void isEmpty(Queue* qu){
    int res = queue_empty(qu);

    if(res == -1)
        printf("\nMemória Insuficiente.\n");
    else if(res)
        printf("\nFila Vazia.\n");
    else
        printf("\nFila NÃO está Vazia.\n");

    return;
}//isEmpty

void sizeQueue(Queue* qu){
    int size = queue_size(qu);

    if(size == -1)
        printf("\nMemória Insuficiente.\n");
    else
        printf("\nA Fila possui %d aluno(s).\n", size);

    return;
}//sizeQueue

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