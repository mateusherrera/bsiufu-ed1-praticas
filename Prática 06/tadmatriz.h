//Typedef para struct matriz
typedef struct matriz Matriz;

//Protótipo de criarMatriz
int criarMatriz(unsigned int linha, unsigned int coluna, Matriz **vet);

//Protótipo de liberarMatriz
int liberarMatriz(Matriz *vet);

//Protótipo de escreveElem
int escreveElem(Matriz *vet, unsigned int i, unsigned int j, double num);

//Protótipo de acessarElem
int acessarElem(Matriz *vet, unsigned int i, unsigned int j, double *num);

//Protótipo de preencherAleatorio
int preencherAleatorio(Matriz *vet, unsigned int max);

//Protótipo de somarMatriz
int somarMatriz(Matriz *vet1, Matriz *vet2, Matriz *vet3);

//Protótipo de multiplicarMatriz
int multiplicarMatriz(Matriz *vet1, Matriz *vet2, Matriz *vet3);

//Protótipo de multMatEscalar
int multMatEscalar(Matriz *vet, double escalar);

//Protótipo de tracoMatriz
int tracoMatriz(Matriz *vet, double *traco);

//Protótipo de somaLinha
int somaLinha(Matriz *vet, double *Linha, unsigned int linha);

//Protótipo de somaColuna
int somaColuna(Matriz *vet, double *Coluna, unsigned int coluna);
