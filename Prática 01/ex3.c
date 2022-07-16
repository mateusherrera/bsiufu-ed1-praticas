#include <stdio.h>

int main(void)
{
	printf("<< Contagem Regressiva >>\n");
	for(int contagem = 10; contagem >= 0; contagem--)
		printf("%d.. ", contagem);
	printf("FIM!\n");
	
	return 0;
}//main