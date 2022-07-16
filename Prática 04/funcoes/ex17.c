#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int(int *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%4d", vet[i]);
    printf("\n");

    return;
}//imprime_vet_int

void imprime_vet_double(double *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%7.2lf", vet[i]);
    printf("\n");

    return;
}//imprime_vet_double

void imprime_vet_float(float *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%7.2f", vet[i]);
    printf("\n");

    return;
}//imprime_vet_float

int main(void)
{
    int ni, nd, nf;
    int *veti;
    double *vetd;
    float *vetf;

    printf("Digite o tamanho do vetor de inteiros: ");
    scanf("%d", &ni);
    printf("Digite o tamanho do vetor de double: ");
    scanf("%d", &nd);
    printf("Digite o tamanho do vetor de float: ");
    scanf("%d", &nf);

    veti = (int *) calloc(ni, sizeof(int));
    vetd = (double *) calloc(nd, sizeof(double));
    vetf = (float *) calloc(nf, sizeof(float));

    for(int i = 0; i < ni; i++)
    {
        printf("Digite valor %d do vetor de inteiro: ", i + 1);
        scanf("%d", &veti[i]);
    }//for
    for(int i = 0; i < nd; i++)
    {
        printf("Digite valor %d do vetor de double: ", i + 1);
        scanf("%lf", &vetd[i]);
    }//for
    for(int i = 0; i < nf; i++)
    {
        printf("Digite valor %d do vetor de float: ", i + 1);
        scanf("%f", &vetf[i]);
    }//for

    printf("\n<< Vetor de Inteiro >>\n");
    imprime_vet_int(veti, ni);
    printf("\n<< Vetor de Double >>\n");
    imprime_vet_double(vetd, nd);
    printf("\n<< Vetor de Float >>\n");
    imprime_vet_float(vetf, nf);
    printf("\n");

    free(veti);
    free(vetd);
    free(vetf);

    return 0;
}//main
