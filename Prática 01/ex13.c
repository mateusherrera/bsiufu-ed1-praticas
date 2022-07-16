#include <stdio.h>

int main(void)
{
	int n;
	
	printf("<< Múltiplos >>\n");
	printf("Entre com o valor de n: ");
	scanf("%d", &n);
	{
		int mult[n];
		int i = 0;
		int j = 0;
		
		printf("Entre com o valor de i: ");
		scanf("%d", &i);
		printf("Entre com o valor de j: ");
		scanf("%d", &j);
		
		for(int x = 0, y = 0; x < n; y++)
		{
			if((y % i == 0) || (y % j == 0))
			{
				mult[x] = y;
				x++;
			}//if
		}//for
		
		printf("Os múltiplos de i ou j são: ");
		for(int z = 0, w = 0; z < n; z++)
		{
			if(w == 0)
			{
				printf("%d", mult[z]);
				w = 1;
			}else{
				printf(",");
				printf(" %d", mult[z]);
			}//else
		}//for
		printf("\n");
	}
	
	return 0;
}//main