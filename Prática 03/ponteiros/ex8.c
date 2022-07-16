#include <stdio.h>

int main(void)
{
	int x;
	double y;
	void *p;
	
	p = &x;
	printf("Digite um inteiro: ");
	scanf("%d", (int *) p);
	p = &y;
	printf("Digite um double: ");
	scanf("%lf", (double *) p);
	
	p = &x;
	printf("\nInteiro: %d\n", *((int *) p));
	p = &y;
	printf("Double: %.2lf\n", *((double *) p));
	
	return 0;
}//main