#include <stdio.h>
#include <stdlib.h>

void imprime_vet_double(double *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%7.2lf", vet[i]);
    printf("\n");

    return;
}//imprime_vet_double

void maior_menor(double *vet, double *maior, double *menor, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(*maior < vet[i]) *maior = vet[i];
        if(*menor > vet[i]) *menor = vet[i];
    }//for

    return;
}//maior_menor

int main(void)
{
    double maior, menor;
    double *vet;
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    vet = (double *) calloc(n, sizeof(double));

    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("Digite o valor %d do vetor: ", i + 1);
        scanf("%lf", &vet[i]);
    }//for
    printf("\n");

    printf("<< O Vetor Armazenado é o Seguinte >>\n");
    imprime_vet_double(vet, n);
    printf("\n");

    maior = vet[0];
    menor = vet[0];
    maior_menor(vet, &maior, &menor, n);
    printf("O maior elemento é = %.2lf\nO menor elemento é = %.2lf\n\n", maior, menor);

    free(vet);

    return 0;
}//main
