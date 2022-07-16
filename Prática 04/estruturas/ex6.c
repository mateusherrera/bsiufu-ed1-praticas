#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[16];
    float pot, temp;
}ELETRO;

int main(void)
{
    int n = 5, dias;
    float consumo[5];
    float consumo_total = 0.0;
    ELETRO *vet = (ELETRO *) malloc(n * sizeof(ELETRO));

    printf("<< ELETRODOMÉSTICOS >>\n");
    for(int i = 0; i < n; i++)
    {
        printf("Entre com o nome do eletrodoméstico %d: ", i + 1);
        fgets(vet[i].nome, sizeof(vet[i].nome), stdin);
        vet[i].nome[strcspn(vet[i].nome, "\n")] = '\0';
        printf("Entre com a potência do eletrodoméstico %d(em Kw): ", i + 1);
        scanf("%f", &vet[i].pot);
        printf("Entre com o tempo de execução diária do eletrodoméstico %d(em horas): ", i + 1);
        scanf("%f", &vet[i].temp);
        getchar();
        printf("\n");
    }//for

    printf("Quantos dias se passaram: ");
    scanf("%d", &dias);

    for(int i = 0; i < n; i++)
    {
        consumo[i] = vet[i].temp * vet[i].pot * dias;
        consumo_total += consumo[i];
    }//for

    printf("\n<< Consumo em %d dia(s) >>\n", dias);
    printf("Consumo Total: %.2fKw.\n\n", consumo_total);
    for(int i = 0; i < n; i++)
        printf("Consumo relativo do eletrodoméstico %d: %.2f%%.\n", i + 1, (consumo[i] * 100) / consumo_total);
    printf("\n");

    free(vet);

    return 0;
}//main