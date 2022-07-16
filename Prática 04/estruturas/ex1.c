#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ddd;
    int numero;
}TELEFONE;

int main(void)
{
    int n = 3;
    TELEFONE *vet = (TELEFONE *) malloc(n * sizeof(TELEFONE));

    for(int i = 0; i < n; i++)
    {
        printf("Digite o DDD do telefone %d: ", i + 1);
        scanf("%d", &vet[i].ddd);
        printf("Digite o número do telefone %d: ", i + 1);
        scanf("%d", &vet[i].numero);
    }//for
    printf("\n");

    printf("<< TELEFONE >>\n");
    for(int i = 0; i < n; i++)
        printf("Telefone %d = (%d) %d\n", i + 1, vet[i].ddd, vet[i].numero);
    printf("\n");

    free(vet);

    return 0;
}//main