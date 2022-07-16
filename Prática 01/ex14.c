#include <stdio.h>

int main(void)
{
	int p;
	int n = 0;
	
	printf("<< Números Primos >>\n");
	printf("Entre com o valor: ");
	scanf("%d", &p);
	
	if(p % 2 == 0 && p != 2)
	{
		printf("O número %d não é primo\n", p);
	}else{
		for(int i = 1; i < p; i++)
			if(p % i == 0) n++;
	}//else
	if(n > 2)
	{
		printf("O número %d não é primo\n", p);
	}else{
		printf("O número %d é primo\n", p);
	}//else
	
	return 0;
}//main