#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "Student.h"

//Valor máximo de alunos por lista
#define MAX 100
//SUCCESS
#define SUCCESS 0
//OUT_OF_MEMORY
#define OUT_OF_MEMORY -1
//ELEM_NOT_FOUND
#define ELEM_NOT_FOUND -2

//Define tipo Alunos
typedef struct aluno Alunos;
//Define tipo Lista
typedef struct Lista Lista;

//Protótipo de criaLista
Lista* criaLista(void);
//Protótipo de liberaLista
void liberaLista(Lista* vet);
//Protótipo de consultaListaPos
int consultaListaPos(Lista *vet, unsigned int pos, Alunos *aluno);
//Protótipo de consultaListaMat
int consultaListaMat(Lista *vet, int mat, Alunos *aluno);
//Protótipo de insereListaFinal
int insereListaFinal(Lista *vet, Alunos aluno);
//Protótipo de insereListaInicio
int insereListaInicio(Lista *vet, Alunos aluno);
//Protótipo de insereListaOrdenada
int insereListaOrdenada(Lista *vet, Alunos aluno);
//Protótipo de removeLista
int removeLista(Lista *vet, int mat);
//Protótipo de removeListaOtimizada
int removeListaOtimizada(Lista *vet, int mat);
//Protótipo de removeListaInicio
int removeListaInicio(Lista *vet);
//Protótipo de removeListaFinal
int removeListaFinal(Lista *vet);
//Protótipo de listaCheia
int listaCheia(Lista *vet);
//Protótipo de listaVazia
int listaVazia(Lista *vet);
//Protótipo de tamLista
int tamLista(Lista* vet);
//Protótipo de imprimeLista
int imprimeLista(Lista *vet);

#endif