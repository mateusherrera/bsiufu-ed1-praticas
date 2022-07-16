#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *num = (int *) malloc(5 * sizeof(int));
	
	for(int i = 0; i < 5; i++)
	{
		printf("Digite o inteiro %d: ", i + 1);
		scanf("%d", &num[i]);
	}//for
	
	for(int i = 0; i < 5; i++)
		printf("%4d", num[i]);
	printf("\n");
	
	free(num);
	
	return 0;
}//main