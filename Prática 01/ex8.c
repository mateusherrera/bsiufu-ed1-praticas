#include <stdio.h>

int main(void)
{
	int contagem;
	
	printf("Qual é o número inicial? ");
	scanf("%d", &contagem);
	
	printf("<< Contagem Progressiva >>\n");
	do{
		printf("%d.. ", contagem);
		contagem++;
	}while(contagem <= 0);
	printf("FIM!\n");
	
	return 0;
}//main

/** do .. while não é melhor opção para esse programa, porque caso o usuário digite um número fora da condição, o resultado será
* impresso na tela antes da validação feita pelo while.
*/