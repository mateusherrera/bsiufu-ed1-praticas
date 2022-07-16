#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int(int *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%6d", vet[i]);
    printf("\n");

    return;
}//imprime_vet_int

void imprime_vet_double(double *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%9.2lf", vet[i]);
    printf("\n");

    return;
}//imprime_vet_double

void lerVetor(int *vet, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Entre com o valor do elemento %d: ", i + 1);
        scanf("%d", &vet[i]);
    }//for
    printf("\n");

    return;
}//lerVetor

double *to_double(int *vet_int, int n)
{
    double *vet_double = (double *) malloc(n * sizeof(double));

    for(int i = 0; i < n; i++)
        vet_double[i] = (double) vet_int[i];
    
    return vet_double;
}//to_double

int main(void)
{
    int *vet_int;
    double *vet_double;
    int n;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);
    vet_int = (int *) malloc(n * sizeof(int));
    lerVetor(vet_int, n);

    vet_double = to_double(vet_int, n);

    printf("<< Vetor de Inteiro >>\n");
    imprime_vet_int(vet_int, n);
    printf("<< Vetor de Double >>\n");
    imprime_vet_double(vet_double, n);
    printf("\n");

    free(vet_double);
    free(vet_int);

    return 0;
}//main