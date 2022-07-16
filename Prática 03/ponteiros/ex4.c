#include <stdio.h>

int main(void)
{
	int val[5] = {2, 4, 6, 8, 20};
	int *pval;
	
	for(int i = 0; i < 5; i++)
	{
		pval = &val[i];
		*pval = *pval - 1;
		printf("%d  ", *pval);
	}//for
	printf("\n");
	
	return 0;
}//main