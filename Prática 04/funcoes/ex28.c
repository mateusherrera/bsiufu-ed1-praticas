#include <stdio.h>
#include <stdlib.h>

void lerVetor(double *vet, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Entre com o valor do elemento %d: ", i + 1);
        scanf("%lf", &vet[i]);
    }//for
    printf("\n");

    return;
}//lerVetor

void imprime_vet_double(double *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%7.2lf", vet[i]);
    printf("\n");

    return;
}//imprime_vet_double

/*
* Função que não funciona:
* void copiarvet(double *vet_origem, double *vet_destino, int n)
* {
*     vet_destino = (double *) malloc(n * sizeof(double));
*     for(int i = 0; i < n; i++)
*         vet_destino[i] = vet_origem[i];
*
*     return;
* }//copiarvet
*/

double *copiarvet(double *vet_origem, int n)
{
    double *vet_destino = (double *) malloc(n * sizeof(double));
    for(int i = 0; i < n; i++)
        vet_destino[i] = vet_origem[i];

    printf("Variável vet_origem: %lu\n", vet_origem);
    printf("Endereço vet_origem: %lu\n", &vet_origem);
    printf("Endereço vet_origem(hexadecimal): %p\n\n", &vet_origem);

    printf("Variável vet_destino: %lu\n", vet_destino);
    printf("Endereço vet_destino: %lu\n", &vet_destino);
    printf("Endereço vet_destino(hexadecimal): %p\n\n", &vet_destino);

    printf("Variável n: %d\n", n);
    printf("Endereço n: %lu\n", &n);
    printf("Endereço n(hexadecimal): %p\n\n", &n);

    return vet_destino;
}//copiarvet

int main(void)
{
    double *vet_origem, *vet_destino;
    int n;

    printf("Variável vet_origem: %lu\n", vet_origem);
    printf("Endereço vet_origem: %lu\n", &vet_origem);
    printf("Endereço vet_origem(hexadecimal): %p\n\n", &vet_origem);

    printf("Variável vet_destino: %lu\n", vet_destino);
    printf("Endereço vet_destino: %lu\n", &vet_destino);
    printf("Endereço vet_destino(hexadecimal): %p\n\n", &vet_destino);

    printf("Variável n: %d\n", n);
    printf("Endereço n: %lu\n", &n);
    printf("Endereço n(hexadecimal): %p\n\n", &n);

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);
    vet_origem = (double *) calloc(n, sizeof(double));
    lerVetor(vet_origem, n);
    vet_destino = copiarvet(vet_origem, n);
    printf("\n");

    printf("<< Vetor Origem >>\n");
    imprime_vet_double(vet_origem, n);
    printf("<< Vetor Destino >>\n");
    imprime_vet_double(vet_destino, n);
    printf("\n");

    printf("Variável vet_origem: %lu\n", vet_origem);
    printf("Endereço vet_origem: %lu\n", &vet_origem);
    printf("Endereço vet_origem(hexadecimal): %p\n\n", &vet_origem);

    printf("Variável vet_destino: %lu\n", vet_destino);
    printf("Endereço vet_destino: %lu\n", &vet_destino);
    printf("Endereço vet_destino(hexadecimal): %p\n\n", &vet_destino);

    printf("Variável n: %d\n", n);
    printf("Endereço n: %lu\n", &n);
    printf("Endereço n(hexadecimal): %p\n\n", &n);

    free(vet_origem);
    free(vet_destino);

    return 0;
}//main

/**
 * 28) ... Explique porque a função não funciona. Faça o mapa de memória (antes, durante, e depois da chamada da função).
 *     Qual seria a solução para uma função deste tipo?
 *
 *     R: A função não funciona porque nela está se alterando a copia do endereço apontado por 'vet_destino' e não o en-
 *        dereço em si do ponteiro.
 *        Uma solução seria retornar o endereço alocado e fazer com que 'vet_destino' receba esse retorno (como no código).
 */
