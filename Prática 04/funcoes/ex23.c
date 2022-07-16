#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int(int *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%6d", vet[i]);
    printf("\n");

    return;
}//imprime_vet_int

void maior_menor(int *vet, int *maior, int *menor, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(*maior < vet[i]) *maior = vet[i];
        if(*menor > vet[i]) *menor = vet[i];
    }//for

    return;
}//maior_menor

int negativos(int *vet, int n)
{
    int qtd = 0;

    for(int i = 0; i < n; i++)
    {
        if(vet[i] < 0) qtd++;
    }//for

    return qtd;
}//negativos

void abs_vet(int *vet, int n)
{
    for(int i = 0; i < n; i++)
        vet[i] = abs(vet[i]);

    return;
}//abs_vet

void copiarvet(int *vet_origem, int *vet_destino, int n)
{
    for(int i = 0; i < n; i++)
        vet_destino[i] = vet_origem[i];

    return;
}//copiarvet

void multvet(int *vet, int n, int escalar)
{
    for(int i = 0; i < n; i++)
        vet[i] *= escalar;

    return;
}//multvet

int main(void)
{
    int n, qtd, maior, menor, escalar;
    int *vet, *vet_cpy;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        printf("Entre com o elemento %d: ", i + 1);
        scanf("%d", &vet[i]);
    }//for
    printf("\n");

    printf("Vetor Armazenado: ");
    imprime_vet_int(vet, n);

    maior = vet[0];
    menor = vet[0];
    maior_menor(vet, &maior, &menor, n);
    printf("Maior: %d       Menor: %d\n", maior, menor);

    qtd = negativos(vet, n);
    printf("Número de negativos: %d\n", qtd);

    vet_cpy = (int *) malloc(n * sizeof(int));
    copiarvet(vet, vet_cpy, n);
    abs_vet(vet_cpy, n);
    printf("Vetor Absoluto: ");
    imprime_vet_int(vet_cpy, n);

    copiarvet(vet, vet_cpy, n);
    printf("Vetor original: ");
    imprime_vet_int(vet, n);
    printf("Vetor copiado: ");
    imprime_vet_int(vet_cpy, n);

    printf("Entre com o valor escalar para multiplicar o vetor original: ");
    scanf("%d", &escalar);
    multvet(vet, n, escalar);
    printf("Vetor original: ");
    imprime_vet_int(vet, n);
    printf("Vetor copiado: ");
    imprime_vet_int(vet_cpy, n);
    printf("\n");

    free(vet);
    free(vet_cpy);

    return 0;
}//main
