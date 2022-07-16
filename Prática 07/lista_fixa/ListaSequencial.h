//Valor máximo de alunos por lista
#define MAX 100

//Informações de um aluno
typedef struct{
  int matricula;
  char nome[30];
  float n1, n2, n3;
}Alunos;

//Define tipo Lista
typedef struct Lista Lista;

//Protótipo de criaLista
int criaLista(Lista **vet);

//Protótipo de liberaLista
int liberaLista(Lista *vet);

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

//Protótipo de imprimeLista
int imprimeLista(Lista *vet);
