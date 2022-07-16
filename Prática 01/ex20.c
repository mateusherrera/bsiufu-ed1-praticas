#include <stdio.h>

int main(void)
{
	int n;
	int num = 1;
	
	printf("Entre com um valor inteiro e positivo para n: ");
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			printf("%d ", num);
			num++;
		}
		printf("\n");
	}//for
	
	return 0;
}//main