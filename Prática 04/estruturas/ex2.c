#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
}NASC;

int main(void)
{
    int n = 3;
    NASC *vet = (NASC *) malloc(n * sizeof(NASC));

    for(int i = 0; i < n; i++)
    {
        printf("Digite o dia de nascimento do elemento %d: ", i + 1);
        scanf("%d", &vet[i].dia);
        printf("Digite o mês de nascimento do elemento %d: ", i + 1);
        scanf("%d", &vet[i].mes);
        printf("Digite o ano de nascimento do elemento %d: ", i + 1);
        scanf("%d", &vet[i].ano);
    }//for
    printf("\n");

    printf("<< DATA DE NASCIMENTO >>\n");
    for(int i = 0; i < n; i++)
        printf("Data de nascimento do elemento %d: %d/%d/%d\n", i + 1, vet[i].dia, vet[i].mes, vet[i].ano);
    printf("\n");

    free(vet);

    return 0;
}//main