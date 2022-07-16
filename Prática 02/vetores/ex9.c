#include <stdio.h>

int main(void)
{
	unsigned int alunos;
	
	printf("<< Média de n alunos. Máximo 100 alunos >>\n");
	printf("Entre com o número de alunos: ");
	scanf("%u", &alunos);
	while(alunos > 100)
	{
		printf("Erro! O número máximo de alunos permitido é 100.\n");
		printf("Entre com o número de alunos: ");
		scanf("%u", &alunos);
	}//while
	{
		double notas[alunos];
		double media = 0.0;
		
		for(int i = 0; i < alunos; i++)
		{
			printf("Digite a nota do aluno %d: ", i + 1);
			scanf("%lf", &notas[i]);
		}//for
		
		for(int i = 0; i < alunos; i++)
			media += notas[i];
		media /= alunos;
		
		printf("Relatório de Notas\n");
		for(int i = 0; i < alunos; i++)
			printf("A nota do aluno %d é: %.2lf\n", i + 1, notas[i]);
		printf("A média da turma é: %.2lf\n", media);
	}
	
	return 0;
}//main