#include <stdio.h>
#include <stdlib.h>

void imprime_vet_float(float *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%7.2f", vet[i]);
    printf("\n");

    return;
}//imprime_vet_float

int negativos(float *vet, int n)
{
    int qtd = 0;

    for(int i = 0; i < n; i++)
    {
        if(vet[i] < 0) qtd++;
    }//for

    return qtd;
}//negativos

int main(void)
{
    float *vet;
    int n, qtd;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (float *) malloc(n * sizeof(float));
    for(int i = 0; i < n; i++)
    {
        printf("Digite o valor %d do vetor: ", i + 1);
        scanf("%f", &vet[i]);
    }//for
    printf("\n");

    printf("<< Vetor de Float >>\n");
    imprime_vet_float(vet, n);
    printf("\n");

    qtd = negativos(vet, n);
    printf("Existem %d negativos nesse vetor.\n\n", qtd);

    free(vet);

    return 0;
}//main
