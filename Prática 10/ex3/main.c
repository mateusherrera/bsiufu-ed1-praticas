#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

//Definition of size of string
#define TAM 50

//Returns a bool that checks if a string of parentheses and/or brackets is spelled correctly
int verifyParBra(char*);

int main(void){
    char str[TAM];

    printf("Escreva uma strings de parênteses e colchetes: ");
    if(!fgets(str, sizeof(str), stdin)){
        fprintf(stderr, "\nErro ao ler a string!!\n\n");
        exit(1);
    }else
        str[strcspn(str, "\n")] = '\0';

    for(int i = 0; i != TAM && str[i] != '\0'; i++){
        if(str[i] != '(' && str[i] != '[' && str[i] != ')' && str[i] != ']'){
            printf("\nString Incorreta!!\n\n");
            return 0;
        }//if
    }//for

    if(verifyParBra(str))
        printf("\nSua string está escrita corretamente.\n\n");
    else
        printf("\nSua string NÃO está escrita corretamente.\n\n");

    return 0;
}//main

int verifyParBra(char* str){
    Stack* st;
    char c;

    st = stack_create();
    if(!st)
        exit(1);

    for(int i = 0; i != TAM && str[i] != '\0'; i++){
        if(str[i] == ')'){
            if(stack_empty(st)){
                stack_free(st);
                return 0;
            }//if
            stack_top(st, &c);
            stack_pop(st);
            if(c != '('){
                stack_free(st);
                return 0;
            }//if
        }else if(str[i] == ']'){
            if(stack_empty(st)){
                stack_free(st);
                return 0;
            }//if
            stack_top(st, &c);
            stack_pop(st);
            if(c != '['){
                stack_free(st);
                return 0;
            }//if
        }else{
            if(stack_push(st, str[i])){
                printf("\nMemória Insuficiente!!\n\n");
                stack_free(st);
                exit(1);
            }//if
        }//else if
    }//for

    if(stack_empty(st)){
        stack_free(st);
        return 1;
    }else{
        stack_free(st);
        return 0;
    }//else if
}//verifyParBra