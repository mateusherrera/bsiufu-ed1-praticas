#include <stdio.h>
#include <string.h>

int main(void)
{
	char buff[6];
	int pass = 0;
	
	printf("\nEntre com a senha: ");
	fgets(buff, sizeof(buff), stdin);
	buff[strcspn(buff, "\n")] = '\0';
	
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
* a) Pense em uma solução para o problema do exercício 11 que utiliza fgets.
*    Considere que o tamanho máximo de uma senha são 4 dígitos.
*    R: Linha 10 - 11: "fgets(buff, sizeof(buff), stdin);
*                       buff[strcspn(buff, "\n")] = '\0';"
*       O ideal é um vetor de tamanho 6 nesse caso, pois com um de tamanho 5, caso se digite "12345" o 5 será trocado por '\0'
*       e o programa entenderá a senha como correta.
*
* b) Teste com os seguintes valores
*    a. 123:
*           "Senha Errada
*            Acesso negado"
*    b. 12345:
*             "Senha Errada
*              Acesso negado"
*    c. 123456:
*              "Senha Errada
*               Acesso negado"
*/