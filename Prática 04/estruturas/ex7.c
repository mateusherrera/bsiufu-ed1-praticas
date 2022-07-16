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

    printf("Variável n = %d\n", n);
    printf("Endereço n = %lu\n", &n);
    printf("Endereço n(hexadecimal) = %p\n\n", &n);

    printf("Variável dias = %d\n", dias);
    printf("Endereço dias = %lu\n", &dias);
    printf("Endereço dias(hexadecimal) = %p\n\n", &dias);

    printf("Variável consumo[0] = %f\n", consumo[0]);
    printf("Endereço consumo[0] = %lu\n", &consumo[0]);
    printf("Endereço consumo[0](hexadecimal) = %p\n\n", &consumo[0]);

    printf("Variável consumo_total = %f\n", consumo_total);
    printf("Endereço consumo_total = %lu\n", &consumo_total);
    printf("Endereço consumo_total(hexadecimal) = %p\n\n", &consumo_total);

    printf("Variável vet[0].nome = %s\n", vet[0].nome);
    printf("Endereço vet[0].nome[0] = %lu\n", &vet[0].nome[0]);
    printf("Endereço vet[0].nome[0](hexadecimal) = %p\n\n", &vet[0].nome[0]);

    printf("Variável vet[0].pot = %f\n", vet[0].pot);
    printf("Endereço vet[0].pot = %lu\n", &vet[0].pot);
    printf("Endereço vet[0].pot(hexadecimal) = %p\n\n", &vet[0].pot);

    printf("Variável vet[0].temp = %f\n", vet[0].temp);
    printf("Endereço vet[0].temp = %lu\n", &vet[0].temp);
    printf("Endereço vet[0].temp(hexadecimal) = %p\n\n", &vet[0].temp);

    free(vet);

    return 0;
}//main

/**
Endereço:              Conteúdo     Nome da Variável        Tipo
---                    ---          ---                     ---
94627033768544          'n'          vet[0].nome[0]          char
94627033768545          'o'          vet[0].nome[1]          char
94627033768546          'm'          vet[0].nome[2]          char
94627033768547          'e'          vet[0].nome[3]          char
94627033768548          '_'          vet[0].nome[4]          char
94627033768549          '1'          vet[0].nome[5]          char
94627033768550          '\0'         vet[0].nome[6]          char
94627033768551          lx           vet[0].nome[7]          char
94627033768552          lx           vet[0].nome[8]          char
94627033768553          lx           vet[0].nome[9]          char
94627033768554          lx           vet[0].nome[10]         char
94627033768555          lx           vet[0].nome[11]         char
94627033768556          lx           vet[0].nome[12]         char
94627033768557          lx           vet[0].nome[13]         char
94627033768558          lx           vet[0].nome[14]         char
94627033768559          lx           vet[0].nome[15]         char
94627033768560          1.0          vet[0].pot              float
94627033768561          1.0          vet[0].pot              float
94627033768562          1.0          vet[0].pot              float
94627033768563          1.0          vet[0].pot              float
94627033768564          1.0          vet[0].temp             float
94627033768565          1.0          vet[0].temp             float
94627033768566          1.0          vet[0].temp             float
94627033768567          1.0          vet[0].temp             float

Endereço:              Conteúdo     Nome da Variável        Tipo
---                    ---          ---                     ---
94627033768568          'n'          vet[1].nome[0]          char
94627033768569          'o'          vet[1].nome[1]          char
94627033768570          'm'          vet[1].nome[2]          char
94627033768571          'e'          vet[1].nome[3]          char
94627033768572          '_'          vet[1].nome[4]          char
94627033768573          '2'          vet[1].nome[5]          char
94627033768574          '\0'         vet[1].nome[6]          char
94627033768575          lx           vet[1].nome[7]          char
94627033768576          lx           vet[1].nome[8]          char
94627033768577          lx           vet[1].nome[9]          char
94627033768578          lx           vet[1].nome[10]         char
94627033768579          lx           vet[1].nome[11]         char
94627033768580          lx           vet[1].nome[12]         char
94627033768581          lx           vet[1].nome[13]         char
94627033768582          lx           vet[1].nome[14]         char
94627033768583          lx           vet[1].nome[15]         char
94627033768584          1.0          vet[1].pot              float
94627033768585          1.0          vet[1].pot              float
94627033768586          1.0          vet[1].pot              float
94627033768587          1.0          vet[1].pot              float
94627033768588          1.0          vet[1].temp             float
94627033768589          1.0          vet[1].temp             float
94627033768590          1.0          vet[1].temp             float
94627033768591          1.0          vet[1].temp             float

Endereço:              Conteúdo     Nome da Variável        Tipo
---                    ---          ---                     ---
94627033768592          'n'          vet[2].nome[0]          char
94627033768593          'o'          vet[2].nome[1]          char
94627033768594          'm'          vet[2].nome[2]          char
94627033768595          'e'          vet[2].nome[3]          char
94627033768596          '_'          vet[2].nome[4]          char
94627033768597          '3'          vet[2].nome[5]          char
94627033768598          '\0'         vet[2].nome[6]          char
94627033768599          lx           vet[2].nome[7]          char
94627033768600          lx           vet[2].nome[8]          char
94627033768601          lx           vet[2].nome[9]          char
94627033768602          lx           vet[2].nome[10]         char
94627033768603          lx           vet[2].nome[11]         char
94627033768604          lx           vet[2].nome[12]         char
94627033768605          lx           vet[2].nome[13]         char
94627033768606          lx           vet[2].nome[14]         char
94627033768607          lx           vet[2].nome[15]         char
94627033768608          1.0          vet[2].pot              float
94627033768609          1.0          vet[2].pot              float
94627033768610          1.0          vet[2].pot              float
94627033768611          1.0          vet[2].pot              float
94627033768612          1.0          vet[2].temp             float
94627033768613          1.0          vet[2].temp             float
94627033768614          1.0          vet[2].temp             float
94627033768615          1.0          vet[2].temp             float

Endereço:              Conteúdo     Nome da Variável        Tipo
---                    ---          ---                     ---
94627033768616          'n'          vet[3].nome[0]          char
94627033768617          'o'          vet[3].nome[1]          char
94627033768618          'm'          vet[3].nome[2]          char
94627033768619          'e'          vet[3].nome[3]          char
94627033768620          '_'          vet[3].nome[4]          char
94627033768621          '4'          vet[3].nome[5]          char
94627033768622          '\0'         vet[3].nome[6]          char
94627033768623          lx           vet[3].nome[7]          char
94627033768624          lx           vet[3].nome[8]          char
94627033768625          lx           vet[3].nome[9]          char
94627033768626          lx           vet[3].nome[10]         char
94627033768627          lx           vet[3].nome[11]         char
94627033768628          lx           vet[3].nome[12]         char
94627033768629          lx           vet[3].nome[13]         char
94627033768630          lx           vet[3].nome[14]         char
94627033768631          lx           vet[3].nome[15]         char
94627033768632          1.0          vet[3].pot              float
94627033768633          1.0          vet[3].pot              float
94627033768634          1.0          vet[3].pot              float
94627033768635          1.0          vet[3].pot              float
94627033768636          1.0          vet[3].temp             float
94627033768637          1.0          vet[3].temp             float
94627033768638          1.0          vet[3].temp             float
94627033768639          1.0          vet[3].temp             float

Endereço:              Conteúdo     Nome da Variável        Tipo
---                    ---          ---                     ---
94627033768640          'n'          vet[4].nome[0]          char
94627033768641          'o'          vet[4].nome[1]          char
94627033768642          'm'          vet[4].nome[2]          char
94627033768643          'e'          vet[4].nome[3]          char
94627033768644          '_'          vet[4].nome[4]          char
94627033768645          '5'          vet[4].nome[5]          char
94627033768646          '\0'         vet[4].nome[6]          char
94627033768647          lx           vet[4].nome[7]          char
94627033768648          lx           vet[4].nome[8]          char
94627033768649          lx           vet[4].nome[9]          char
94627033768650          lx           vet[4].nome[10]         char
94627033768651          lx           vet[4].nome[11]         char
94627033768652          lx           vet[4].nome[12]         char
94627033768653          lx           vet[4].nome[13]         char
94627033768654          lx           vet[4].nome[14]         char
94627033768655          lx           vet[4].nome[15]         char
94627033768656          1.0          vet[4].pot              float
94627033768657          1.0          vet[4].pot              float
94627033768658          1.0          vet[4].pot              float
94627033768659          1.0          vet[4].pot              float
94627033768660          1.0          vet[4].temp             float
94627033768661          1.0          vet[4].temp             float
94627033768662          1.0          vet[4].temp             float
94627033768663          1.0          vet[4].temp             float

Endereço:              Conteúdo     Nome da Variável        Tipo
---                    ---          ---                     ---
...
140732435321472         5            n                       int
140732435321473         5            n                       int
140732435321474         5            n                       int
140732435321475         5            n                       int
140732435321476         2            dias                    int
140732435321477         2            dias                    int
140732435321478         2            dias                    int
140732435321479         2            dias                    int
140732435321480         10.0         consumo_total           float
140732435321481         10.0         consumo_total           float
140732435321482         10.0         consumo_total           float
140732435321483         10.0         consumo_total           float

Endereço:              Conteúdo     Nome da Variável        Tipo
---                    ---          ---                     ---
...
140732435321504         2.0          consumo[0]              float
140732435321505         2.0          consumo[0]              float
140732435321506         2.0          consumo[0]              float
140732435321507         2.0          consumo[0]              float
140732435321508         2.0          consumo[1]              float
140732435321509         2.0          consumo[1]              float
140732435321510         2.0          consumo[1]              float
140732435321511         2.0          consumo[1]              float
140732435321512         2.0          consumo[2]              float
140732435321513         2.0          consumo[2]              float
140732435321514         2.0          consumo[2]              float
140732435321515         2.0          consumo[2]              float
140732435321516         2.0          consumo[3]              float
140732435321517         2.0          consumo[3]              float
140732435321518         2.0          consumo[3]              float
140732435321519         2.0          consumo[3]              float
140732435321520         2.0          consumo[4]              float
140732435321521         2.0          consumo[4]              float
140732435321522         2.0          consumo[4]              float
140732435321523         2.0          consumo[4]              float
*/