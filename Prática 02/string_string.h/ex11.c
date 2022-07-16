#include <stdio.h>
#include <string.h>

int main(void)
{
	char buff[5];
	int pass = 0;
	
	printf("\nEntre com a senha: ");
	gets(buff);
	
	if(strcmp(buff, "1234"))
	{
		printf("\nSenha Errada \n");
	}else{
		printf("\nSenha Correta \n");
		pass = 1;
	}//if else
	
	if(pass)
	{
	/* O usuário acertou a senha, poderá continuar*/
	printf("\nAcesso liberado \n");
	}else{
	printf("\nAcesso negado \n");
	}//if else
	
	return 0;
}//main

/**
* a) Qual é a função do programa?
* R: Ler e verificar a senha digitada pelo usuário.
*
* b) Qual a saída quando a senha correta é digitada (senha correta: 1234)
* R: "Senha Correta
*     Acesso liberado"
*
* c) Qual a saída para as seguintes senhas
*    a. 123:
*           "Senha Errada
*            Acesso negado"
*    b. 12345:
*             "Senha Errada
*              Acesso negado"
*    c. 123456:
*              "Senha Errada
*               Acesso negado
*               *** stack smashing detected ***: <unknown> terminated
*               Abortado (imagem do núcleo gravada)"
*
* d) Em quais casos o programa obteve um comportamento inválido. Explique o motivo.
* R: Em casos que a senha digitada tem 5 digitos ou mais, porque o vetor de char que armazena a senha tem tamanho igual à 5.
*    Este comportamento se deve ao uso da função "gets()" ao invés de "fgets()".
*/