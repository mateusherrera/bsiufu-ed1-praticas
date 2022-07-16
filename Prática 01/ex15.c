#include <stdio.h>
#include <math.h>

int main(void)
{
	int bit;
	
	printf("<< Conversor binário-decimal >>\n");
	printf("Entre com o número de bits: ");
	scanf("%d", &bit);
	
	{
		int bin[bit];
		int dec = 0;
		
		for(int i = 1, j = 0; i <= bit; i++, j++)
		{
			printf("Digite o bit # %d: ", i);
			scanf("%d", &bin[j]);
		}//for
		for(int i = bit - 1, j = 0; i >= 0; i--, j++)
			dec += bin[i] * (pow(2, j));
		printf("O número binário ");
		for(int i = 0; i < bit; i++)
			printf("%d", bin[i]);
		printf(" em decimal é %d\n", dec);
	}
	
	return 0;
}//main