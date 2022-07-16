#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_cllist.h"

// A menu to insert a student on the list
void insert_student(List*);

// A menu to see the data of a student on the list
void find_student(List*);

// A menu to remove a student from a list
void remove_student(List*);

// A function that print the data of a single student
void print_student(Student);

// A function that read the data of a student
void input_student(Student*);

int main(void){
    unsigned int op = 0;
    int alloc = 0;
    List* li;

    while(op != 8){
        switch(op){
            case 0:
                printf("\n<< Menu Principal >>\n");
                printf("1 - Criar lista.\n");
                printf("2 - Inserir aluno.\n");
                printf("3 - Consultar dados de aluno.\n");
                printf("4 - Remover aluno da lista.\n");
                printf("5 - Consultar tamanho da lista e checar se está vazia.\n");
                printf("6 - Imprimir lista completa.\n");
                printf("7 - Destruír lista.\n");
                printf("8 - Sair.\n\n");
                printf("Entre com uma opção: ");
                scanf("%d", &op);
                if(op == 0) op = 9;
                break;
            case 1: // Criar lista
                if(alloc)
                    printf("\nLista já alocada.\n");
                else{
                    li = list_create();
                    if(li){
                        alloc = 1;
                        printf("\nLista alocada com sucesso.\n");
                    }else
                        printf("\nErro ao alocar lista.\n");
                }// else if
                op = 0;
                break;
            case 2: // Inserir aluno
                if(!alloc)
                    printf("\nLista não alocada.\n");
                else
                    insert_student(li);
                op = 0;
                break;
            case 3: // Consultar dados de aluno
                if(!alloc)
                    printf("\nLista não alocada.\n");
                else
                    find_student(li);
                op = 0;
                break;
            case 4: // Remover aluno da lista
                if(!alloc)
                    printf("\nLista não alocada.\n");
                else
                    remove_student(li);
                op = 0;
                break;
            case 5: // Consulta tamanho da lista e checar se está vazia
                if(!alloc)
                    printf("\nLista não alocada.\n");
                else{
                    printf("\nA lista possui %d aluno(s).\n", list_find_size(li));
                    if(list_empty(li))
                        printf("\nLista Vazia.\n");
                    else
                        printf("\nLista NÃO está vazia.\n");
                }// else if
                op = 0;
                break;
            case 6: // Imprimir lista completa
                if(!alloc)
                    printf("\nLista não alocada.\n");
                else{
                    if(list_print(li))
                        printf("\nLista vazia.\n");
                }// else if
                op = 0;
                break;
            case 7:
                if(!alloc)
                    printf("\nLista não alocada.\n");
                else{
                    list_free(li);
                    alloc = 0;
                    printf("\nLista Destruída!!\n");
                }// else if
                op = 0;
                break;
            default: // Opção inválida
                printf("\nOpção Inválida!!\n");
                printf("Entre com uma opção válida: ");
                scanf("%d", &op);
                break;
        }// switch
    }// while

    if(alloc){
        list_free(li);
        printf("\nLista Destruída!!\n");
    }// if

    printf("\nAté logo!!\n");
    return 0;
}// main

void insert_student(List* li){
    unsigned int op;
    Student stu;
    int res;

    printf("\n<< Inserir Novo Aluno na lista >>\n");
    printf("1 - Inserir no início da lista.\n");
    printf("2 - Inserir no final da lista.\n");
    printf("3 - Inserir na lista por posição.\n");
    printf("4 - Inserir em lista ordenada.\n");
    printf("5 - Voltar ao menu principal.\n");
    printf("Entre com uma opção: ");
    scanf("%d", &op);
    if(op == 5) return;

    input_student(&stu);
    if(op == 1)
        res = list_push_front(li, stu);
    else if(op == 2)
        res = list_push_back(li, stu);
    else if(op == 3){
        int pos;
        printf("Entre com a posição de inserção: ");
        scanf("%d", &pos);
        res = list_insert(li, pos, stu);
    }else if(op == 4)
        res = list_insert_reg(li, stu);
    else{
        printf("\nOpção Inválida!!\n");
        return;
    }// else if

    if(res == -1)
        printf("\nLista não alocada.\n");
    else if(res == -2)
        printf("\nPosição inválida.\n");
    else if(res == -3)
        printf("\nMemória insuficiente.\n");
    else
        printf("\nAluno inserido.\n");

    return;
}// insert_student

void find_student(List* li){
    unsigned int op;
    Student stu;
    int res, pos, reg;

    printf("\n<< Consultar dados de um aluno da lista >>\n");
    printf("1 - Consultar pela posição na lista.\n");
    printf("2 - Consultar primeiro aluno da lista.\n");
    printf("3 - Consultar último aluno da lista.\n");
    printf("4 - Consultar próximo aluno.\n");
    printf("5 - Achar posição de aluno na lista.\n");
    printf("6 - Voltar ao menu principal.\n");
    printf("Entre com uma opção: ");
    scanf("%d", &op);
    if(op == 6) return;

    if(op == 1){
        int pos;
        printf("\nDigite a posição que deseja consultar: ");
        scanf("%d", &pos);
        res = list_find_pos(li, pos, &stu);
    }else if(op == 2)
        res = list_front(li, &stu);
    else if(op == 3)
        res = list_back(li, &stu);
    else if(op == 4)
        res = list_next(li, &stu);
    else if(op == 5){
        printf("Digite a matrícula do aluno que deseja encontrar: ");
        scanf("%d", &reg);
        res = list_get_pos(li, reg, &pos);
    }else{
        printf("\nOpção Inválida!!\n");
        return;
    }// else if

    if(res == -1)
        printf("\nLista não alocada.\n");
    else if(res == -2)
        printf("\nElemento inválido.\n");
    else if(res == -4)
        printf("\nLista Vazia.\n");
    else if(op == 5)
        printf("\nA posição do aluno de matrícula %d, na lista, é %d.\n", reg, pos);
    else
        print_student(stu);

    return;
}// find_student

void remove_student(List* li){
    unsigned int op;
    int res, pos, reg;

    printf("\n<< Remover um Aluno da lista >>\n");
    printf("1 - Remover primeiro aluno da lista.\n");
    printf("2 - Remover último aluno da lista.\n");
    printf("3 - Remover aluno por posição.\n");
    printf("4 - Achar posição de aluno na lista.\n");
    printf("5 - Voltar ao menu principal.\n");
    printf("Entre com uma opção: ");
    scanf("%d", &op);
    if(op == 5) return;

    if(op == 1)
        res = list_pop_front(li);
    else if(op == 2)
        res = list_pop_back(li);
    else if(op == 3){
        int pos;
        printf("Entre com a posição do aluno que deve ser removido: ");
        scanf("%d", &pos);
        res = list_erase(li, pos);
    }else if(op == 4){
        printf("Digite a matrícula do aluno que deseja encontrar: ");
        scanf("%d", &reg);
        res = list_get_pos(li, reg, &pos);
    }else{
        printf("\nOpção Inválida!!\n");
        return;
    }// else if

    if(res == -1)
        printf("\nLista não alocada.\n");
    else if(res == -2)
        printf("\nElemento inválido.\n");
    else if(res == -4)
        printf("\nLista Vazia.\n");
    else if(op == 4)
        printf("\nA posição do aluno de matrícula %d, na lista, é %d.\n", reg, pos);
    else
        printf("\nAluno removido.\n");

    return;
}// remove_student

void print_student(Student stu){
    printf("\n<< %s >>\n", stu.name);
    printf("\t%d\n", stu.reg);
    printf("1ª = %.2f pts.\n", stu.t1);
    printf("2ª = %.2f pts.\n", stu.t2);
    printf("3ª = %.2f pts.\n", stu.t3);

    return;
}// print_student

void input_student(Student* stu){
    printf("\nEntre com o nome do aluno: ");

    getchar();
    if(!fgets(stu->name, sizeof(stu->name), stdin)){
        printf("\nErro ao ler string.\n");
        exit(1);
    }else
        stu->name[strcspn(stu->name, "\n")] = '\0';
    printf("Entre com o número de matrícula do aluno: ");
    scanf("%d", &stu->reg);

    printf("Entre com a nota da primeira prova: ");
    scanf("%f", &stu->t1);

    printf("Entre com a nota da segunda prova: ");
    scanf("%f", &stu->t2);

    printf("Entre com a nota da terceira prova: ");
    scanf("%f", &stu->t3);

    return;
}// input_student