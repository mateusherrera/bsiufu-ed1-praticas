#include <stdio.h>

int main(void)
{
	int fat = 1;
	int mult = 1;
	
	printf("<< Fatorial >>\n");
	while(fat <= 10)
	{
		mult = mult * fat;
		printf("%d! = %d\n", fat, mult);
		fat++;
	}//for
	
	return 0;
}//main