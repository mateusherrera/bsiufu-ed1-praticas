#include <stdio.h>

int main(void)
{
	int contagem = 10;
	
	printf("<< Contagem Regressiva >>\n");
	while(contagem >= 0)
	{
		printf("%d.. ", contagem);
		contagem--;
	}//while
	
	printf("FIM!\n");
	
	return 0;
}//main