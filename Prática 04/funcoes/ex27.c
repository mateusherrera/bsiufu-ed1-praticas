#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
}PONTOS;

void imprime_vet_pontos(PONTOS *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("(%d, %d)  ", vet[i].x, vet[i].y);
    printf("\n");

    return;
}//imprime_vet_int

void lerVetor(PONTOS *vet, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Entre com o valor x do elemento %d: ", i + 1);
        scanf("%d", &vet[i].x);
        printf("Entre com o valor y do elemento %d: ", i + 1);
        scanf("%d", &vet[i].y);
    }//for
    printf("\n");

    return;
}//lerVetor

PONTOS *aloca_pontos(int n)
{
    PONTOS *ponto = (PONTOS *) malloc(n * sizeof(PONTOS));
    for(int i = 0; i < n; i++)
    {
        ponto[i].x = 0;
        ponto[i].y = 0;
    }//for

    return ponto;
}//aloca_pontos

int main(void)
{
    PONTOS *ponto;
    int n;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);
    ponto = aloca_pontos(n);
    printf("\n<< Vetor Inicializado com zero >>\n");
    imprime_vet_pontos(ponto, n);
    printf("\n");
    lerVetor(ponto, n);

    printf("<< Vetor de Pontos >>\n");
    imprime_vet_pontos(ponto, n);
    printf("\n");

    free(ponto);

    return 0;
}//main