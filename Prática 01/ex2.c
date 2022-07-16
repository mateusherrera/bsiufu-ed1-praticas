#include <stdio.h>

int main(void)
{
	int contagem = 10;
	
	printf("<< Contagem Regressiva >>\n");
	do{
		printf("%d.. ", contagem);
		contagem--;
	}while(contagem >= 0);
	printf("FIM!\n");
	
	return 0;
} //main