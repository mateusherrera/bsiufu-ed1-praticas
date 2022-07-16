#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int(int *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%4d", vet[i]);
    printf("\n");

    return;
}//imprime_vet_int

void multvet(int *vet, int n, int escalar)
{
    for(int i = 0; i < n; i++)
        vet[i] *= escalar;

    return;
}//multvet

int main(void)
{
    int n, escalar;
    int *vet;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    printf("Digite o valor da escalar: ");
    scanf("%d", &escalar);

    vet = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        printf("Digite o valor %d do vetor: ", i + 1);
        scanf("%d", &vet[i]);
    }//for
    printf("\n");

    printf("<< Vetor Armazenado >>\n");
    imprime_vet_int(vet, n);
    printf("\n");

    multvet(vet, n, escalar);
    printf("<< Vetor Pós Multiplicação >>\n");
    imprime_vet_int(vet, n);
    printf("\n");

    free(vet);

    return 0;
}//main
