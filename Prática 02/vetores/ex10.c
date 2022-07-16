#include <stdio.h>

int main(void)
{
	int A[3];
	int B[3];
	int C[3];
	
	printf("<< Subtração de vetores >>\n");
	for(int i = 0; i < 3; i++)
	{
		printf("Digite o valor %d de A: ", i + 1);
		scanf("%d", &A[i]);
	}//for
	for(int i = 0; i < 3; i++)
	{
		printf("Digite o valor %d de B: ", i + 1);
		scanf("%d", &B[i]);
	}//for
	for(int i = 0; i < 3; i++)
		C[i] = A[i] - B[i];
	
	printf("O vetor C, definido como C = A-B é (%d", C[0]);
	for(int i = 1; i < 3; i++)
		printf(", %d", C[i]);
	printf(")\n");
	
	return 0;
}//main