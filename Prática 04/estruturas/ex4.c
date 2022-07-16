#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int ddd;
    int numero;
}TEL;

typedef struct
{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct
{
    char rua[50];
    char cidade[50];
    int numero;
    char estado[50];
    char complem[50];
    int cep;
}ENDER;

typedef struct
{
    char nome[20];
    int cpf;
    char sexo;
    ENDER end_com;
    char est_civil;
    ENDER end_res;
    float salario;
    TEL tel;
    TEL tel_res;
    int id;
    DATA nasc;
    DATA ingresso;
}CADAS;

int main(void)
{
    int op = 0, n = 5, c, po, pd;
    CADAS *vet = (CADAS *) malloc(n * sizeof(CADAS));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 20; j++)
            vet[i].nome[j] = '\0';
        vet[i].cpf = 00000000000;
        vet[i].sexo = '\0';
        for(int j = 0; j < 50; j++)
            vet[i].end_com.rua[j] = '\0';
        for(int j = 0; j < 50; j++)
            vet[i].end_com.cidade[j] = '\0';
        vet[i].end_com.numero = 0;
        for(int j = 0; j < 50; j++)
            vet[i].end_com.estado[j] = '\0';
        for(int j = 0; j < 50; j++)
            vet[i].end_com.complem[j] = '\0';
        vet[i].end_com.cep = 00000000;
        for(int j = 0; j < 50; j++)
            vet[i].end_res.rua[j] = '\0';
        for(int j = 0; j < 50; j++)
            vet[i].end_res.cidade[j] = '\0';
        vet[i].end_res.numero = 0;
        for(int j = 0; j < 50; j++)
            vet[i].end_res.estado[j] = '\0';
        for(int j = 0; j < 50; j++)
            vet[i].end_res.complem[j] = '\0';
        vet[i].end_res.cep = 00000000;
        vet[i].salario = 0.0;
        vet[i].tel.ddd = 00;
        vet[i].tel.numero = 00000000;
        vet[i].tel_res.ddd = 00;
        vet[i].tel_res.numero = 00000000;
        vet[i].id = 00000;
        vet[i].nasc.dia = 0;
        vet[i].nasc.mes = 0;
        vet[i].nasc.ano = 0;
        vet[i].ingresso.dia = 0;
        vet[i].ingresso.mes = 0;
        vet[i].ingresso.ano = 0;
    }//for

    while(op != 6)
    {
        switch(op)
        {
            case 0:
                printf("<< MENU >>\n\n");
                printf("1 - Listar cadastros.\n");
                printf("2 - Cadastrar/Sobrescrever cadastro.\n");
                printf("3 - Listar pessoas que nasceram depois de 1990.\n");
                printf("4 - Copiar dados de um cadastro para outro.\n");
                printf("5 - Fechar programa.\n\n");
                printf("Entre com uma opção: ");
                scanf("%d", &op);
                getchar();
                printf("\n");
                break;
            case 1:
                printf("<< Cadastros >>\n");
                for(int i = 0; i < n; i++)
                {
                    printf("Nome: %s\n", vet[i].nome);
                    printf("CPF: %d\n", vet[i].cpf);
                    printf("Sexo: %c\n", vet[i].sexo);
                    printf("Rua Comercial: %s\n", vet[i].end_com.rua);
                    printf("Cidade Comercial: %s\n", vet[i].end_com.cidade);
                    printf("Número Comercial: %d\n", vet[i].end_com.numero);
                    printf("Estado Comercial: %s\n", vet[i].end_com.estado);
                    printf("Complemento Comercial: %s\n", vet[i].end_com.complem);
                    printf("CEP Comercial: %d\n", vet[i].end_com.cep);
                    printf("Estado Civil: %c\n", vet[i].est_civil);
                    printf("Rua Residencial: %s\n", vet[i].end_res.rua);
                    printf("Cidade Residencial: %s\n", vet[i].end_res.cidade);
                    printf("Número Residencial: %d\n", vet[i].end_res.numero);
                    printf("Estado Residencial: %s\n", vet[i].end_res.estado);
                    printf("Complemento Residencial: %s\n", vet[i].end_res.complem);
                    printf("CEP Residencial: %d\n", vet[i].end_res.cep);
                    printf("Salário: %.2f\n", vet[i].salario);
                    printf("Telefone: (%d) %d\n", vet[i].tel.ddd, vet[i].tel.numero);
                    printf("Telefone Residencial: (%d) %d\n", vet[i].tel_res.ddd, vet[i].tel_res.numero);
                    printf("Identidade: %d\n", vet[i].id);
                    printf("Nascimento: %d/%d/%d\n", vet[i].nasc.dia, vet[i].nasc.mes, vet[i].nasc.ano);
                    printf("Data de Ingresso: %d/%d/%d\n", vet[i].ingresso.dia, vet[i].ingresso.mes, vet[i].ingresso.ano);
                    printf("\n");
                }//for
                op = 0;
                break;
            case 2:
                printf("<< Cadastrar/Sobrescrever cadastro >>\n");
                printf("Qual posição deseja preencher: ");
                scanf("%d", &c);
                getchar();
                printf("\nEntre com o cadastro:\n");
                printf("Nome: ");
                fgets(vet[c].nome, sizeof(vet[c].nome), stdin);
                vet[c].nome[strcspn(vet[c].nome, "\n")] = '\0';
                printf("CPF: ");
                scanf("%d", &vet[c].cpf);
                getchar();
                printf("Sexo: ");
                scanf("%c", &vet[c].sexo);
                getchar();
                printf("Rua Comercial: ");
                fgets(vet[c].end_com.rua, sizeof(vet[c].end_com.rua), stdin);
                vet[c].end_com.rua[strcspn(vet[c].end_com.rua, "\n")] = '\0';
                printf("Cidade Comercial: ");
                fgets(vet[c].end_com.cidade, sizeof(vet[c].end_com.cidade), stdin);
                vet[c].end_com.cidade[strcspn(vet[c].end_com.cidade, "\n")] = '\0';
                printf("Número Comercial: ");
                scanf("%d", &vet[c].end_com.numero);
                getchar();
                printf("Estado Comercial: ");
                fgets(vet[c].end_com.estado, sizeof(vet[c].end_com.estado), stdin);
                vet[c].end_com.estado[strcspn(vet[c].end_com.estado, "\n")] = '\0';
                printf("Complemento Comercial: ");
                fgets(vet[c].end_com.complem, sizeof(vet[c].end_com.complem), stdin);
                vet[c].end_com.complem[strcspn(vet[c].end_com.complem, "\n")] = '\0';
                printf("CEP Comercial: ");
                scanf("%d", &vet[c].end_com.cep);
                getchar();
                printf("Estado Civil: ");
                scanf("%c", &vet[c].est_civil);
                getchar();
                printf("Rua Residencial: ");
                fgets(vet[c].end_res.rua, sizeof(vet[c].end_res.rua), stdin);
                vet[c].end_res.rua[strcspn(vet[c].end_res.rua, "\n")] = '\0';
                printf("Cidade Residencial: ");
                fgets(vet[c].end_res.cidade, sizeof(vet[c].end_res.cidade), stdin);
                vet[c].end_res.cidade[strcspn(vet[c].end_res.cidade, "\n")] = '\0';
                printf("Número Residencial: ");
                scanf("%d", &vet[c].end_res.numero);
                getchar();
                printf("Estado Residencial: ");
                fgets(vet[c].end_res.estado, sizeof(vet[c].end_res.estado), stdin);
                vet[c].end_res.estado[strcspn(vet[c].end_res.estado, "\n")] = '\0';
                printf("Complemento Residencial: ");
                fgets(vet[c].end_res.complem, sizeof(vet[c].end_res.complem), stdin);
                vet[c].end_res.complem[strcspn(vet[c].end_res.complem, "\n")] = '\0';
                printf("CEP Residencial: ");
                scanf("%d", &vet[c].end_res.cep);
                printf("Salário: ");
                scanf("%f", &vet[c].salario);
                printf("DDD: ");
                scanf("%d", &vet[c].tel.ddd);
                printf("Telefone: ");
                scanf("%d", &vet[c].tel.numero);
                printf("DDD Residencial: ");
                scanf("%d", &vet[c].tel_res.ddd);
                printf("Telefone Residencial: ");
                scanf("%d", &vet[c].tel_res.numero);
                printf("Identidade: ");
                scanf("%d", &vet[c].id);
                printf("Dia do Nascimento: ");
                scanf("%d", &vet[c].nasc.dia);
                printf("Mês do Nascimento: ");
                scanf("%d", &vet[c].nasc.mes);
                printf("Ano do Nascimento: ");
                scanf("%d", &vet[c].nasc.ano);
                printf("Dia de Ingresso: ");
                scanf("%d", &vet[c].ingresso.dia);
                printf("Mês de Ingresso: ");
                scanf("%d", &vet[c].ingresso.mes);
                printf("Ano de Ingresso: ");
                scanf("%d", &vet[c].ingresso.ano);
                getchar();
                printf("\n");
                op = 0;
                break;
            case 3:
                printf("<< Lista de pessoas que nasceram depois de 1990 >>\n");
                for(int i = 0; i < n; i++)
                {
                    if(vet[i].nasc.ano >= 1990)
                    {
                        printf("Nome: %s\n", vet[i].nome);
                        printf("CPF: %d\n", vet[i].cpf);
                        printf("Sexo: %c\n", vet[i].sexo);
                        printf("Rua Comercial: %s\n", vet[i].end_com.rua);
                        printf("Cidade Comercial: %s\n", vet[i].end_com.cidade);
                        printf("Número Comercial: %d\n", vet[i].end_com.numero);
                        printf("Estado Comercial: %s\n", vet[i].end_com.estado);
                        printf("Complemento Comercial: %s\n", vet[i].end_com.complem);
                        printf("CEP Comercial: %d\n", vet[i].end_com.cep);
                        printf("Estado Civil: %c\n", vet[i].est_civil);
                        printf("Rua Residencial: %s\n", vet[i].end_res.rua);
                        printf("Cidade Residencial: %s\n", vet[i].end_res.cidade);
                        printf("Número Residencial: %d\n", vet[i].end_res.numero);
                        printf("Estado Residencial: %s\n", vet[i].end_res.estado);
                        printf("Complemento Residencial: %s\n", vet[i].end_res.complem);
                        printf("CEP Residencial: %d\n", vet[i].end_res.cep);
                        printf("Salário: %.2f\n", vet[i].salario);
                        printf("Telefone: (%d) %d\n", vet[i].tel.ddd, vet[i].tel.numero);
                        printf("Telefone Residencial: (%d) %d\n", vet[i].tel_res.ddd, vet[i].tel_res.numero);
                        printf("Identidade: %d\n", vet[i].id);
                        printf("Nascimento: %d/%d/%d\n", vet[i].nasc.dia, vet[i].nasc.mes, vet[i].nasc.ano);
                        printf("Data de Ingresso: %d/%d/%d\n", vet[i].ingresso.dia, vet[i].ingresso.mes, vet[i].ingresso.ano);
                        printf("\n");
                    }//if
                }//for
                op = 0;
                break;
            case 4:
                printf("<< Copiar dados de um cadastro para outro >>\n");
                printf("Cadastro que será copiado(0 - 4): ");
                scanf("%d", &pd);
                printf("Cadastro que será sobrescrito(0 - 4): ");
                scanf("%d", &po);

                for(int j = 0; j < 20; j++)
                    vet[po].nome[j] = vet[pd].nome[j];
                vet[po].cpf = vet[pd].cpf;
                vet[po].sexo = vet[pd].sexo;
                for(int j = 0; j < 50; j++)
                    vet[po].end_com.rua[j] = vet[pd].end_com.rua[j];
                for(int j = 0; j < 50; j++)
                    vet[po].end_com.cidade[j] = vet[pd].end_com.cidade[j];
                vet[po].end_com.numero = vet[pd].end_com.numero;
                for(int j = 0; j < 50; j++)
                    vet[po].end_com.estado[j] = vet[pd].end_com.estado[j];
                for(int j = 0; j < 50; j++)
                    vet[po].end_com.complem[j] = vet[pd].end_com.complem[j];
                vet[po].end_com.cep = vet[pd].end_com.cep;
                for(int j = 0; j < 50; j++)
                    vet[po].end_res.rua[j] = vet[pd].end_res.rua[j];
                for(int j = 0; j < 50; j++)
                    vet[po].end_res.cidade[j] = vet[pd].end_res.cidade[j];
                vet[po].end_res.numero = vet[pd].end_res.numero;
                for(int j = 0; j < 50; j++)
                    vet[po].end_res.estado[j] = vet[pd].end_res.estado[j];
                for(int j = 0; j < 50; j++)
                    vet[po].end_res.complem[j] = vet[pd].end_res.complem[j];
                vet[po].end_res.cep = vet[pd].end_res.cep;
                vet[po].salario = vet[pd].salario;
                vet[po].tel.ddd = vet[pd].tel.ddd;
                vet[po].tel.numero = vet[pd].tel.numero;
                vet[po].tel_res.ddd = vet[pd].tel_res.ddd;
                vet[po].tel_res.numero = vet[pd].tel_res.numero;
                vet[po].id = vet[pd].id;
                vet[po].nasc.dia = vet[pd].nasc.dia;
                vet[po].nasc.mes = vet[pd].nasc.mes;
                vet[po].nasc.ano = vet[pd].nasc.ano;
                vet[po].ingresso.dia = vet[pd].ingresso.dia;
                vet[po].ingresso.mes = vet[pd].ingresso.mes;
                vet[po].ingresso.ano = vet[pd].ingresso.ano;

                op = 0;
                break;
            case 5:
                op = 6;
                break;
            default:
                printf("\nOPÇÃO INVÁLIDA!!\nDigite uma opção válida: ");
                scanf("%d", &op);
                printf("\n");
                break;
        }//switch
    }//while
    printf("Até Logo!!!\n\n");

    free(vet);

    return 0;
}//main