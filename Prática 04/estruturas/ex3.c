#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char rua[50];
    char cidade[50];
    int numero;
    char estado[50];
    char complem[50];
    int cep;
}ENDER;

int main(void)
{
    int n = 3;
    ENDER *vet = (ENDER *) malloc(n * sizeof(ENDER));

    for(int i = 0; i < n; i++)
    {
        printf("Digite a rua do elemento %d: ", i + 1);
        fgets(vet[i].rua, sizeof(vet[i].rua), stdin);
        vet[i].rua[strcspn(vet[i].rua, "\n")] = '\0';
        printf("Digite a cidade do elemento %d: ", i + 1);
        fgets(vet[i].cidade, sizeof(vet[i].cidade), stdin);
        vet[i].cidade[strcspn(vet[i].cidade, "\n")] = '\0';
        printf("Digite o número do elemento %d: ", i + 1);
        scanf("%d", &vet[i].numero);
        getchar();
        printf("Digite o estado do elemento %d: ", i + 1);
        fgets(vet[i].estado, sizeof(vet[i].estado), stdin);
        vet[i].estado[strcspn(vet[i].estado, "\n")] = '\0';
        printf("Digite o complemento do elemento %d: ", i + 1);
        fgets(vet[i].complem, sizeof(vet[i].complem), stdin);
        vet[i].complem[strcspn(vet[i].complem, "\n")] = '\0';
        printf("Digite o CEP do elemento %d: ", i + 1);
        scanf("%d", &vet[i].cep);
        getchar();
    }//for
    printf("\n");

    printf("<< ENDEREÇO >>\n");
    for(int i = 0; i < n; i++)
    {
        printf("Rua do elemento %d: %s\n", i + 1, vet[i].rua);
        printf("Cidade do elemento %d: %s\n", i + 1, vet[i].cidade);
        printf("Número do elemento %d: %d\n", i + 1, vet[i].numero);
        printf("Estado do elemento %d: %s\n", i + 1, vet[i].estado);
        printf("Complemento do elemento %d: %s\n", i + 1, vet[i].complem);
        printf("CEP do elemento %d: %d\n", i + 1, vet[i].cep);
        printf("\n");
    }//for

    free(vet);

    return 0;
}//main