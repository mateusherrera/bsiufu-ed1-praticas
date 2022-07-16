#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime_vet_int(int *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%4d", vet[i]);
    printf("\n");

    return;
}//imprime_vet_int

void abs_vet(int *vet, int n)
{
    for(int i = 0; i < n; i++)
        vet[i] = abs(vet[i]);

    return;
}//abs_vet

int main(void)
{
    int *vet;
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vet = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        printf("Digite o valor %d do vetor: ", i + 1);
        scanf("%d", &vet[i]);
    }//for

    printf("\n<< Vetor Armazenado >>\n");
    imprime_vet_int(vet, n);
    printf("\n");

    abs_vet(vet, n);
    printf("<< Vetor com Valores Absolutos >>\n");
    imprime_vet_int(vet, n);
    printf("\n");

    free(vet);

    return 0;
}//main
