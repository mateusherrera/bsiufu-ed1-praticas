#include <stdio.h>

int main(void)
{
	int val[5] = {2, 4, 5, 8, 10};
	int a = 40;
	int *p = &a, *pval4 = &val[4];
	
	printf("Endereço &a = %lu\nEndereço &a(em hexadecimal) = %p\n", &a, &a);
	printf("Endereço p(&a) = %lu\nEndereço p(&a)(em hexadecimal) = %p\n", p, p);
	
	printf("Digite um novo valor para a: ");
	scanf("%d", p);
	
	printf("Digite 20: ");
	scanf("%d", pval4);
	
	printf("\nVariável val[0] = %d\n", val[0]);
	printf("Endereço val[0] = %lu\n", &val[0]);
	printf("Endereço val[0](em hexadecimal) = %p\n", &val[0]);
	
	printf("\nVariável a = %d\n", a);
	printf("Endereço a = %lu\n", &a);
	printf("Endereço a(em hexadecimal) = %p\n", &a);
	
	printf("\nVariável p = %lu\n", p);
	printf("Endereço p = %lu\n", &p);
	printf("Endereço p(em hexadecimal) = %p\n", &p);
	
	printf("\nVariável pval4 = %lu\n", pval4);
	printf("Endereço pval4 = %lu\n", &pval4);
	printf("Endereço pval4(em hexadecimal) = %p\n", &pval4);
	
	return 0;
}//main