#include <stdio.h>

int main(void)
{
	int val[5] = {2, 4, 5, 8, 10};
	int *pval = &val[0];
	
	printf("Digite 6: ");
	scanf("%d", pval + 2);
	
	for(int i = 0; i < 5; i++)
	{
		pval = &val[i];
		printf("%d  ", *pval);
	}//for
	printf("\n");
	
	printf("\nVariável val[0] = %d\n", val[0]);
	printf("Endereço val[0] = %lu\n", &val[0]);
	printf("Endereço val[0](em hexadecimal) = %p\n", &val[0]);
	
	printf("\nVariável pval = %lu\n", pval);
	printf("Endereço pval = %lu\n", &pval);
	printf("Endereço pval(em hexadecimal) = %p\n", &pval);
	
	return 0;
}//main