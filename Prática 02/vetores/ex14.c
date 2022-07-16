#include <stdio.h>

typedef struct
{
	int matricula;
	char cs;
	double CRA;
} ALUNOS;

int main(void)
{
	unsigned int alunos;
	
	printf("<< Universidade X >>\n");
	printf("Quantos alunos serão cadastrados: ");
	scanf("%u", &alunos);
	while(alunos > 10000)
	{
		printf("Limite de alunos é 10000!!\n");
		printf("Digite uma quantidade válida: ");
		scanf("%u", &alunos);
	}//while
	{
		ALUNOS universidade[alunos];
		
		for(int i = 0; i < alunos; i++)
		{
			printf("Entre com o número do aluno: ");
			scanf("%d", &universidade[i].matricula);
			printf("Entre com a classe social do aluno %d: ", universidade[i].matricula);
			getchar();
			scanf("%c", &universidade[i].cs);
			printf("Entre com o CRA do aluno %d: ", universidade[i].matricula);
			scanf("%lf", &universidade[i].CRA);
			printf("\n");
		}//for
		
		printf("==== Alunos Cadastrados ====\n");
		for(int i = 0; i < alunos; i++)
			printf("Número: %d Classe Social: %c CRA: %.2lf\n", universidade[i].matricula, universidade[i].cs, universidade[i].CRA);
	}
	
	return 0;
}//main