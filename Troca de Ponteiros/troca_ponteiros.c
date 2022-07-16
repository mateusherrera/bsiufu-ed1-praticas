#include <stdio.h>
#include <stdlib.h>

// A funtion that switch to pointers
void switch_pointer(int** pa, int** pb);

int main(void){
    int* pa = malloc(10 * sizeof(int));
    int* pb = malloc(20 * sizeof(int));

    if(!pa || !pb){
        printf("\nErro ao alocar um (ou os dois) dos ponteiros.\n");
        exit(1);
    }// if

    for(int i = 0; i < 20; ++i){
        if(i < 10)
            pa[i] = i;
        pb[i] = i;
    }// for

    printf("\nPA:\n");
    for(int i = 0; i < 10; ++i)
        printf("%d ", pa[i]);
    printf("\n");

    printf("\nPB:\n");
    for(int i = 0; i < 20; ++i)
        printf("%d ", pb[i]);
    printf("\n");

    switch_pointer(&pa, &pb);

    printf("\nPA:\n");
    for(int i = 0; i < 20; ++i)
        printf("%d ", pa[i]);
    printf("\n");

    printf("\nPB:\n");
    for(int i = 0; i < 10; ++i)
        printf("%d ", pb[i]);
    printf("\n");

    free(pa);
    free(pb);

    return 0;
}// main

void switch_pointer(int** pa, int** pb){
    int* pc = *pa;

    *pa = *pb;
    *pb = pc;

    return;
}// switch_pointer