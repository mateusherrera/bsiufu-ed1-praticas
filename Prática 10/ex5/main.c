#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

// Definition of size of the strings
#define STR_SIZE 33

// Put parentheses in the begin and in the end of a string if it doesn't exist
void putParen(char*);

// Returns a bool that checks if a string of parentheses and/or brackets is spelled correctly
int verifyParBra(char*);

// A function that have a infix notation as parameter and put their posfix notation in the other paremeter
void RPN(char*, char*);

int main(void){
    char in_notation[STR_SIZE];
    char pos_notation[STR_SIZE];

    printf("Input your notation (MAX 30 character): ");
    if(!fgets(in_notation, STR_SIZE - 2, stdin)){
        fprintf(stderr, "\n\nERROR!!\n\n");
        exit(1);
    }else
        in_notation[strcspn(in_notation, "\n")] = '\0';

    putParen(in_notation);
    if(verifyParBra(in_notation)){
        RPN(in_notation, pos_notation);
        printf("\n\n<< REVERSE POLISH NOTATION >>\n");
        printf("Infix notation: %s\n", in_notation);
        printf("Posfix notation: %s\n\n", pos_notation);
    }else
        printf("\n\nThe parentheses are not spelled correctly.\n\n");

    return 0;
}// main

void putParen(char* str){
    if(str[0] == '(')
        return;

    int i;
    for(i = 0; str[i] != '\0'; ++i);
    str[i++] = ')';
    str[i + 1] = '\0';
    while(i != 0)
        str[i--] = str[i - 1];
    str[0] = '(';
    return;
}// putParen

int verifyParBra(char* str){
    Stack* st;
    char c;

    st = stack_create();
    if(!st)
        exit(1);

    for(int i = 0; str[i] != '\0'; ++i){
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
        }else if(str[i] == '(' || str[i] == '[')
            stack_push(st, str[i]);
    }//for

    if(stack_empty(st)){
        stack_free(st);
        return 1;
    }else{
        stack_free(st);
        return 0;
    }//else if
}//verifyParBra

void RPN(char* infix, char* posfix){
    Stack* st;
    st = stack_create();
    if(!st){
        printf("\n\nERROR.\n\n");
        exit(1);
    }// if
    stack_push(st, infix[0]);
    int j = 0;
    for(int i = 1; infix[i] != '\0'; ++i){
        switch(infix[i]){
            char x;
            case '(':
                stack_push(st, infix[i]);
                break;
            case ')':
                stack_top(st, &x);
                stack_pop(st);
                while(x != '('){
                    posfix[j++] = x;
                    stack_top(st, &x);
                    stack_pop(st);
                }// while
                break;
            case '+':
            case '-':
                stack_top(st, &x);
                stack_pop(st);
                while(x != '('){
                    posfix[j++] = x;
                    stack_top(st, &x);
                    stack_pop(st);
                }// while
                stack_push(st, x);
                stack_push(st, infix[i]);
                break;
            case '*':
            case '/':
                stack_top(st, &x);
                stack_pop(st);
                while(x != '(' && x != '+' && x != '-'){
                    posfix[j++] = x;
                    stack_top(st, &x);
                    stack_pop(st);
                }// while
                stack_push(st, x);
                stack_push(st, infix[i]);
                break;
            default: posfix[j++] = infix[i];
        }// switch
    }// for
    stack_free(st);
    posfix[j] = '\0';

    return;
}// RPN