#include <stdio.h>

int main(void)
{
	double notas[5];
	double norm;
	double maior_nota;
	
	printf("<< Normalizando as notas >>\n");
	for(int i = 0; i < 5; i++)
	{
		printf("Entre com a nota do aluno %d: ", i + 1);
		scanf("%lf", &notas[i]);
	}//for
	
	maior_nota = notas[0];
	for(int i = 0; i < 5; i++)
	{
		if(maior_nota < notas[i]) maior_nota = notas[i];
	}//for
	
	norm = 100.0 / maior_nota;
	
	printf("Notas normalizadas:\n");
	for(int i = 0; i < 5; i++)
		printf("A nota do aluno %d é: %.2lf\n", i + 1, notas[i] * norm);
	
	return 0;
}//main