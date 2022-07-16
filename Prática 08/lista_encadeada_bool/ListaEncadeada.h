//Define retorno de sucesso
#define SUCCESS 0
//Define retorno de memória insuficiente
#define OUT_OF_MEMORY -1
//Define retorno de elemento não existe
#define ELEM_NOT_FOUND -2
//Define retorno de lista inválida
#define INVALID_LIST -3

//Definição de tipo Aluno
typedef struct{
  int matricula;
  char nome[30];
  float n1, n2, n3;
}Aluno;

//Definição de tipo Lista
typedef struct lista Lista;

//Protótipo de cria_lista
Lista* cria_lista(int);
//Protótipo de libera_lista
void libera_lista(Lista*);
//Protótipo de consulta_lista_pos
int consulta_lista_pos(Lista*, int, Aluno*);
//Protótipo de consulta_lista_mat
int consulta_lista_mat(Lista*, int, Aluno*);
//Protótipo de insere_lista_final
int insere_lista_final(Lista*, Aluno);
//Protótipo de insere_lista_inicio
int insere_lista_inicio(Lista*, Aluno);
//Protótipo de insere_lista_pos
int insere_lista_pos(Lista*, int, Aluno);
//Protótipo de insere_lista_ordenada
int insere_lista_ordenada(Lista*, Aluno);
//Protótipo de remove_lista
int remove_lista(Lista*, int);
//Protótipo de remove_lista_inicio
int remove_lista_inicio(Lista*);
//Protótipo de remove_lista_final
int remove_lista_final(Lista*);
//Protótipo de tamanho_lista
int tamanho_lista(Lista*);
//Protótipo de lista_cheia
int lista_cheia(Lista*);
//Protótipo de lista_vazia
int lista_vazia(Lista*);
//Protótipo de imprime_lista
int imprime_lista(Lista*);
