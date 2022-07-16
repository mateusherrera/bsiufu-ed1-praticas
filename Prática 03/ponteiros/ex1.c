#include <stdio.h>

int main(void)
{
	int val[5] = {2, 4, 5, 8, 10};
	unsigned long int end = &val[2];
	
	printf("Digite 6: ");
	scanf("%d", end);
	
	for(int i = 0; i < 5; i++)
		printf("%d  ", val[i]);
	printf("\n");
	
	return 0;
}//main