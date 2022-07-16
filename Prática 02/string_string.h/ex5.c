#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char nomecomp[40], nome[40], sobrenome[40];
	int pos;
	
	printf("<< Vetor de Char >>\n");
	printf("Digite um nome e um sobrenome: ");
	fgets(nomecomp, sizeof(nomecomp), stdin);
	nomecomp[strcspn(nomecomp, "\n")] = '\0';
	
	pos = strcspn(nomecomp, " ");
	strncpy(nome, nomecomp, pos);
	printf("Nome: %s\n", nome);
	
	pos++;
	for(int i = 0; nomecomp[pos] != '\0'; i++, pos++)
		sobrenome[i] = nomecomp[pos];
	printf("Sobrenome: %s\n", sobrenome);
	
	return 0;
}//main