#include <stdio.h>

int main(void)
{
	int v1 = 1;
	double v2 = 2;
	char c = 'a';
	int *p_v1;
	double *p_v2;
	char *p_c;
	
	p_v1 = &v1;
	p_v2 = &v2;
	p_c = &c;
	
	printf("\nEndereço de v1 %lu", p_v1);
	printf("\nEndereço de v2 %lu", p_v2);
	printf("\nEndereço de c %lu\n", p_c);
	
	printf("\nEndereço + 1 de v1 %lu", p_v1 + 1);
	printf("\nEndereço + 1 de v2 %lu", p_v2 + 1);
	printf("\nEndereço + 1 de c %lu\n", p_c + 1);
	
	printf("\nEndereço + 2 de v1 %lu", p_v1 + 2);
	printf("\nEndereço + 2 de v2 %lu", p_v2 + 2);
	printf("\nEndereço + 2 de c %lu\n", p_c + 2);
	
	printf("\nEndereço - 1 de v1 %lu", p_v1 - 1);
	printf("\nEndereço - 1 de v2 %lu", p_v2 - 1);
	printf("\nEndereço - 1 de c %lu\n", p_c - 1);
	
	printf("\nEndereço - 2 de v1 %lu", p_v1 - 2);
	printf("\nEndereço - 2 de v2 %lu", p_v2 - 2);
	printf("\nEndereço - 2 de c %lu\n\n", p_c - 2);
	
	return 0;
}//main

/**
* Nome variável/   Endereço var-2     Endereço var-1     Endereço var     Endereço var+1     Endereço var+2
* Endereços
*    -                   -                  -                  -                -                  -
* p_v1            140728773266060    140728773266064   140728773266068   140728773266072    140728773266076
* p_v2            140728773266056    140728773266064   140728773266072   140728773266080    140728773266088
* P_c             140728773266078    140728773266079   140728773266080   140728773266081    140728773266082
*/