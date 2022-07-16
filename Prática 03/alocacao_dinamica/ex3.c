#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *num;
	int n, par = 0, impar = 0;
	
	printf("Digite a quantidade de inteiros: ");
	scanf("%d", &n);
	num = (int *) malloc(n * sizeof(int));
	
	for(int i = 0; i < n; i++)
	{
		printf("Digite o inteiro %d: ", i + 1);
		scanf("%d", &num[i]);
	}//for
	for(int i = 0; i < n; i++)
	{
		if(num[i] % 2 == 0)
		{
			par++;
		}else{
			impar++;
		}//if else
	}//for
	
	printf("\n%d é(são) par(es).\n", par);
	printf("%d é(são) impar(es).\n", impar);
	
	free(num);
	
	return 0;
}//main