#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	char nome[50], cpf[50], rg[50], rua[50], cidade[50], estado[5], cep[10];
	
	printf("Digite seu nome: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strcspn(nome, "\n")] = '\0';
	
	printf("Digite seu CPF: ");
	fgets(cpf, sizeof(cpf), stdin);
	cpf[strcspn(cpf, "\n")] = '\0';
	
	printf("Digite seu RG: ");
	fgets(rg, sizeof(rg), stdin);
	rg[strcspn(rg, "\n")] = '\0';
	
	printf("Digite seu endereço: ");
	fgets(rua, sizeof(rua), stdin);
	rua[strcspn(rua, "\n")] = '\0';
	
	printf("Digite sua cidade: ");
	fgets(cidade, sizeof(cidade), stdin);
	cidade[strcspn(cidade, "\n")] = '\0';
	
	printf("Digite seu estado: ");
	fgets(estado, sizeof(estado), stdin);
	estado[strcspn(estado, "\n")] = '\0';
	
	printf("Digite seu CEP: ");
	fgets(cep, sizeof(cep), stdin);
	cep[strcspn(cep, "\n")] = '\0';
	
	printf("D E C L A R A Ç Ã O\n\n");
	printf("Eu, %s, RG %s, CPF %s, residente a %s, %s-%s, CEP %s venho por meio desta declarar que vou estudar para a prova\n", nome, rg, cpf, rua, cidade, estado, cep);
	
	return 0;
}//main