#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int(int *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%6d", vet[i]);
    printf("\n");

    return;
}//imprime_vet_int

int *aloca_inteiro(int n)
{
    int *vet = (int *) calloc(n, sizeof(int));

    return vet;
}//aloca_inteiro

int main(void)
{
    int *vet;
    int n;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);

    vet = aloca_inteiro(n);
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("Entre com o valor do elemento %d: ", i + 1);
        scanf("%d", &vet[i]);
    }//for
    printf("\n");

    printf("<< Vetor Armazenado >>\n");
    imprime_vet_int(vet, n);
    printf("\n");

    free(vet);

    return 0;
}//main
