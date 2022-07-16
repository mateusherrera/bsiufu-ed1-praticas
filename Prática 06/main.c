#include <stdio.h>
#include <stdlib.h>
#include "tadmatriz.h"


//Protótipo de imprimeMatriz
int imprimeMatriz(Matriz *vet, unsigned int linha, unsigned int coluna);

int main(void)
{
  unsigned int op = 0, linha1, coluna1, linha2, coluna2, pl, pc, max;
  Matriz *mat1, *mat2, *mat3;
  double *Linha, *Coluna;
  double num;

  printf("<< Tamanho das Matrizes >>\n");
  printf("Entre com o número de linhas da 1ª matriz: ");
  scanf("%u", &linha1);
  printf("Entre com o número de colunas da 1ª matriz: ");
  scanf("%u", &coluna1);
  printf("Entre com o número de linhas da 2ª matriz: ");
  scanf("%u", &linha2);
  printf("Entre com o número de colunas da 2ª matriz: ");
  scanf("%u", &coluna2);

  while(!(op == 10))
  {
    switch (op)
    {
      case 0:
        printf("\n<< Funções >>\n");
        printf("1 - Criar Matriz e Liberar Matriz.\n");
        printf("2 - Escrever Elemento e Acessar Elemento.\n");
        printf("3 - Preencher Matriz com Valores Aleatórios de 0 - X.\n");
        printf("4 - Somar Duas Matrizes.\n");
        printf("5 - Multiplicar Duas Matriz.\n");
        printf("6 - Multiplicar Matriz por Valor Escalar.\n");
        printf("7 - Calcular o Traço da Matriz.\n");
        printf("8 - Soma das Linhas e das Colunas.\n");
        printf("9 - Mudar Tamanho das Matrizes.\n");
        printf("10 - Sair.\n\n");
        printf("Entre com a opção desejada: ");
        scanf("%u", &op);
        if(op == 0) op = 11;
        break;
      case 1:
        printf("\n<< Criar Matriz >>\n");
        printf("Se igual a 0 deu certo se não errado: %d\n", criarMatriz(linha1, coluna2, &mat1));
        printf("\n<< Libera Matriz >>\n");
        printf("Se igual a 0 deu certo se não errado: %d\n", liberarMatriz(mat1));
        op = 0;
        break;
      case 2:
        printf("\n<< Escrever Elemento e Acessar Elemento >>\n");

        if(criarMatriz(linha1, coluna2, &mat1))
          printf("\n<< Erro ao alocar matriz!!! >>\n");
        else
        {
          printf("\n<< Leve em conta as posições de 1 à %u >>\n", linha1);
          printf("Qual a linha da posição deseja alterar: ");
          scanf("%u", &pl);
          printf("Qual a coluna da posição deseja alterar: ");
          scanf("%u", &pc);
          printf("Qual o número deseja colocar na posição %ux%u: ", pl, pc);
          scanf("%lf", &num);

          if(escreveElem(mat1, pl, pc, num))
            printf("\n<< Erro ao escrever número!!! >>\n");
          else
          {
            if(acessarElem(mat1, pl, pc, &num))
              printf("\n<< Erro ao acessar elemento!!! >>\n");
            else
              printf("\nNúmero escrito em %ux%u = %.2lf\n", pl, pc, num);
          }//else if
        }//else if

        liberarMatriz(mat1);

        op = 0;
        break;
      case 3:
        printf("\nEntre com o valor máximo do intervalo: ");
        scanf("%u", &max);
        printf("\n<< Preencher Matriz com Valores Aleatórios de 0 - %u >>\n", max);

        if(criarMatriz(linha1, coluna1, &mat1))
          printf("\n<< Erro ao alocar matriz!!! >>\n");
        else
        {
          if(preencherAleatorio(mat1, max))
            printf("\n<< Erro ao preencher matriz!!! >>\n");
          else
          {
            printf("\n<< Matriz Preenchida >>\n");
            if(imprimeMatriz(mat1, linha1, coluna1))
              printf("\n<< Erro ao acessar Elemento!!! >>\n");
          }//else if
        }//else if

        liberarMatriz(mat1);

        op = 0;
        break;
      case 4:
        printf("\n<< Somar Duas Matrizes >>\n");

        if(criarMatriz(linha1, coluna1, &mat1) || criarMatriz(linha2, coluna2, &mat2) || criarMatriz(linha1, coluna1, &mat3))
          printf("\n<< Erro ao alocar matriz!!! >>\n");
        else
        {
          if(preencherAleatorio(mat1, 5) || preencherAleatorio(mat2, 5))
            printf("\n<< Erro ao preencher matriz!!! >>\n");
          else
          {
            if(somarMatriz(mat1, mat2, mat3))
              printf("\n<< Erro ao somar matrizes!!! >>\n");
            else
            {
              printf("\n<< 1º Matriz >>\n");
              if(imprimeMatriz(mat1, linha1, coluna1))
                printf("\n<< Erro ao acessar Elemento!!! >>\n");
              else
              {
                printf("\n<< 2ª Matriz >>\n");
                if(imprimeMatriz(mat2, linha2, coluna2))
                  printf("\n<< Erro ao acessar Elemento!!! >>\n");
                else
                {
                  printf("\n<< Soma das Matrizes >>\n");
                  if(imprimeMatriz(mat3, linha1, linha2))
                    printf("\n<< Erro ao acessar Elemento!!! >>\n");
                }//else if
              }//else if
            }//else if
          }//else if
        }//else if

        liberarMatriz(mat1);
        liberarMatriz(mat2);
        liberarMatriz(mat3);

        op = 0;
        break;
      case 5:
        printf("\n<< Multiplicar Duas Matrizes >>\n");

        if(criarMatriz(linha1, coluna1, &mat1) || criarMatriz(linha2, coluna2, &mat2) || criarMatriz(linha1, coluna2, &mat3))
          printf("\n<< Erro ao alocar matriz!!! >>\n");
        else
        {
          if(preencherAleatorio(mat1, 5) || preencherAleatorio(mat2, 5))
            printf("\n<< Erro ao preencher matriz!!! >>\n");
          else
          {
            if(multiplicarMatriz(mat1, mat2, mat3))
              printf("\n<< Erro ao multiplicar matrizes!!! >>\n");
            else
            {
              printf("\n<< 1º Matriz >>\n");
              if(imprimeMatriz(mat1, linha1, coluna1))
                printf("\n<< Erro ao acessar Elemento!!! >>\n");
              else
              {
                printf("\n<< 2ª Matriz >>\n");
                if(imprimeMatriz(mat2, linha2, coluna2))
                  printf("\n<< Erro ao acessar Elemento!!! >>\n");
                else
                {
                  printf("\n<< Multiplicação das Matrizes >>\n");
                  if(imprimeMatriz(mat3, linha1, coluna2))
                    printf("\n<< Erro ao acessar Elemento!!! >>\n");
                }//else if
              }//else if
            }//else if
          }//else if
        }//else if

        liberarMatriz(mat1);
        liberarMatriz(mat2);
        liberarMatriz(mat3);

        op = 0;
        break;
      case 6:
        printf("\n<< Multiplicar Matriz por Valor Escalar. >>\n");

        if(criarMatriz(linha1, coluna1, &mat1))
          printf("\n<< Erro ao alocar matriz!!! >>\n");
        else
        {
          if(preencherAleatorio(mat1, 5))
            printf("\n<< Erro ao preencher matriz!!! >>\n");
          else
          {
            printf("\n<< Matriz Antes da Multiplicação Escalar >>\n");
            if(imprimeMatriz(mat1, linha1, coluna1))
              printf("\n<< Erro ao acessar Elemento!!! >>\n");
            else
            {
              printf("\nEntre com o valor escalar: ");
              scanf("%lf", &num);
              if(multMatEscalar(mat1, num))
                printf("\n<< Erro ao fazer a escalar!!! >>\n");
              else
              {
                printf("\n<< Matriz Multiplicada pela Escalar %.2lf >>\n", num);
                if(imprimeMatriz(mat1, linha1, coluna1))
                  printf("\n<< Erro ao acessar Elemento!!! >>\n");
              }//else if
            }//else if
          }//else if
        }//else if

        liberarMatriz(mat1);

        op = 0;
        break;
      case 7:
        printf("\n<< Calcular o Traço da Matriz >>\n");

        if(criarMatriz(linha1, coluna1, &mat1))
          printf("\n<< Erro ao alocar matriz!!! >>\n");
        else
        {
          if(preencherAleatorio(mat1, 5))
            printf("\n<< Erro ao preencher matriz!!! >>\n");
          else
          {
            printf("\n<< Matriz Preenchida >>\n");
            if(imprimeMatriz(mat1, linha1, coluna1))
              printf("\n<< Erro ao acessar Elemento!!! >>\n");

            if(tracoMatriz(mat1, &num))
              printf("\n<< Erro ao calcular traço da matriz >>\n");
            else
              printf("\nO traço da matriz é de: %.2lf\n", num);
          }//else if
        }//else if

        liberarMatriz(mat1);

        op = 0;
        break;
      case 8:
        printf("\n<< Soma das Linhas e das Colunas >>\n");

        if(criarMatriz(linha1, coluna1, &mat1))
          printf("\n<< Erro ao alocar matriz!!! >>\n");
        else
        {
          if(preencherAleatorio(mat1, 5))
            printf("\n<< Erro ao preencher matriz!!! >>\n");
          else
          {
            printf("\n<< Matriz Preenchida >>\n");
            if(imprimeMatriz(mat1, linha1, coluna1))
              printf("\n<< Erro ao acessar Elemento!!! >>\n");

            Linha = malloc(linha1 * sizeof(double));
            if(somaLinha(mat1, Linha, linha1))
              printf("\n<< Erro ao somar linhas!!! >>\n");
            else
            {
              printf("\n<< Soma das Linhas >>\n");
              for(int i = 0; i < linha1; i++)
                printf("Soma da Linha %d: %.2lf\n", i, Linha[i]);
              free(Linha);

              Coluna = malloc(coluna1 * sizeof(double));
              if(somaColuna(mat1, Coluna, coluna1))
                printf("\n<< Erro ao somar colunas!!! >>\n");
              else
              {
                printf("\n<< Soma das Colunas >>\n");
                for(int i = 0; i < coluna1; i++)
                  printf("Soma da Coluna %d: %.2lf\n", i, Coluna[i]);
                free(Coluna);
              }//else if
            }//else if
          }//else if
        }//else if

        liberarMatriz(mat1);

        op = 0;
        break;
      case 9:
        printf("\n<< Mudar Tamanho das Matrizes >>\n");
        printf("Entre com o número de linhas da 1ª matriz: ");
        scanf("%u", &linha1);
        printf("Entre com o número de colunas da 1ª matriz: ");
        scanf("%u", &coluna1);
        printf("Entre com o número de linhas da 2ª matriz: ");
        scanf("%u", &linha2);
        printf("Entre com o número de colunas da 2ª matriz: ");
        scanf("%u", &coluna2);

        op = 0;
        break;
      default:
        printf("\n\nOPAÇÃO INVÁLIDA!!!\n\n");
        op = 0;
        break;
    }//switch
  }//while

  return 0;
}//main

int imprimeMatriz(Matriz *vet, unsigned int linha, unsigned int coluna)
{
  double num;

  for(int i = 1; i <= linha; i++)
  {
    for(int j = 1; j <= coluna; j++)
    {
      if(acessarElem(vet, i, j, &num))
        return 1;
      else
        printf("%7.2lf", num);
    }//for
    printf("\n");
  }//for

  return 0;
}//imprimeMatriz
