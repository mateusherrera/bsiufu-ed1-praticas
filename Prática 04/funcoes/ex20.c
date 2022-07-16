#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int(int *vet, int n)
{
    for(int i = 0; i < n; i++)
        printf("%4d", vet[i]);
    printf("\n");

    return;
}//imprime_vet_int

void copiarvet(int *vet_origem, int *vet_destino, int n)
{
    for(int i = 0; i < n; i++)
        vet_destino[i] = vet_origem[i];

    return;
}//copiarvet

int main(void)
{
    int *vet1, *vet2;
    int n;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);

    vet1 = (int *) malloc(n * sizeof(int));
    vet2 = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        printf("Digite o valor %d do primeiro vetor: ", i + 1);
        scanf("%d", &vet1[i]);
        printf("Digite o valor %d do segundo vetor: ", i + 1);
        scanf("%d", &vet2[i]);
    }//for
    printf("\n");

    printf("<< Vetor 1 >>\n");
    imprime_vet_int(vet1, n);
    printf("<< Vetor 2 >>\n");
    imprime_vet_int(vet2, n);

    copiarvet(vet1, vet2, n);
    printf("\nDepois da copia dos vetores tem-se:\n");
    printf("<< Vetor Origem >>\n");
    imprime_vet_int(vet1, n);
    printf("<< Vetor Destino >>\n");
    imprime_vet_int(vet2, n);
    printf("\n");

    free(vet1);
    free(vet2);

    return 0;
}//main
