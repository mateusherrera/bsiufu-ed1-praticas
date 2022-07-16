#include <stdio.h>
#include <stdlib.h>

void imprime_vet_double(double *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%9.2lf", vet[i]);
    printf("\n");

    return;
}//imprime_vet_double

double *copiarvet(double *vet_origem, int n)
{
    double *vet_destino = (double *) malloc(n * sizeof(double));

    for(int i = 0; i < n; i++)
        vet_destino[i] = vet_origem[i];

    return vet_destino;
}//copiarvet

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

int main(void)
{
    double *vet, *vet_cpy;
    int n;

    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &n);
    vet = (double *) malloc(n * sizeof(double));
    lerVetor(vet, n);

    vet_cpy = copiarvet(vet, n);

    printf("<< Vetor Armazenado >>\n");
    imprime_vet_double(vet, n);
    printf("<< Vetor Copiado >>\n");
    imprime_vet_double(vet_cpy, n);
    printf("\n");

    free(vet);
    free(vet_cpy);

    return 0;
}//main
