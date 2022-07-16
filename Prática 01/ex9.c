#include <stdio.h>

int main(void)
{
	int contagem;
	
	printf("Qual é o número inicial? ");
	scanf("%d", &contagem);
	
	printf("<< Contagem Progressiva >>\n");
	for(;contagem <= 0; contagem++)
		printf("%d.. ", contagem);
	printf("FIM!\n");
	
	return 0;
}//main