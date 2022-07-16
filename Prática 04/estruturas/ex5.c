#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int matr;
    char nome[20];
    float prova1;
    float prova2;
    float prova3;
    float media;
    int falta;
}ALUNOS;

int main(void)
{
    int n = 3, maior_nota, imn, maior_media, imam, menor_media, imem;
    ALUNOS *vet =  (ALUNOS *) malloc(n * sizeof(ALUNOS));

    printf("<< ENTRE COM OS DADOS DOS TRÊS ALUNOS >>\n\n");
    for(int i = 0; i < n; i++)
    {
        printf("Entre com a matrícula do aluno %d: ", i + 1);
        scanf("%d", &vet[i].matr);
        getchar();
        printf("Entre com o nome do aluno %d: ", i + 1);
        fgets(vet[i].nome, sizeof(vet[i].nome), stdin);
        vet[i].nome[strcspn(vet[i].nome, "\n")] = '\0';
        printf("Entre com a nota da primeira prova do aluno %d: ", i + 1);
        scanf("%f", &vet[i].prova1);
        printf("Entre com a nota da segunda prova do aluno %d: ", i + 1);
        scanf("%f", &vet[i].prova2);
        printf("Entre com a nota da terceira prova do aluno %d: ", i + 1);
        scanf("%f", &vet[i].prova3);
        vet[i].media = (vet[i].prova1 + vet[i].prova2 + vet[i].prova3) / 3.0;
        printf("Entre com o número de faltas do aluno %d: ", i + 1);
        scanf("%d", &vet[i].falta);
        getchar();
        printf("\n");
    }//for

    imn = 0;
    imam = 0;
    imem = 0;
    for(int i = 0; i < n; i++)
    {
        if(vet[imn].prova1 < vet[i].prova1) imn = i;
        if(vet[imam].media < vet[i].media) imam = i;
        if(vet[imem].media > vet[i].media) imem = i;
    }//for

    printf("<< MAIOR NOTA DA PRIMEIRA PROVA >>\n");
    printf("Aluno: %s, Nota: %.2f\n\n", vet[imn].nome, vet[imn].prova1);
    
    printf("<< MAIOR MÉDIA GERAL >>\n");
    printf("Alunos: %s, Média: %.2f\n\n", vet[imam].nome, vet[imam].media);

    printf("<< MENOR MÉDIA GERAL >>\n");
    printf("Alunos: %s, Média: %.2f\n\n", vet[imem].nome, vet[imem].media);

    printf("<< SITUAÇÃO FINAL DOS ALUNOS >>\n");
    for(int i = 0; i < n; i++)
    {
        if(vet[i].falta > ((int) 72 * 0.25))
            printf("Aluno: %s\nMatrícula: %d\nSituação: Reprovado por falta\n\n", vet[i].nome, vet[i].matr);
        else if((vet[i].media * 3) < 60.0)
            printf("Aluno: %s\nMatrícula: %d\nSituação: Reprovado por nota\n\n", vet[i].nome, vet[i].matr);
        else
            printf("Aluno: %s\nMatrícula: %d\nSituação: Aprovado\n\n", vet[i].nome, vet[i].matr);
    }//for

    free(vet);

    return 0;
}//main