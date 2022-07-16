#include <stdio.h>

void kmh_to_ms(void)
{
	double vel;
	double calc;
	
	printf("Digite a velocidade (km/h): ");
	scanf("%lf", &vel);
	getchar();
	calc = vel / 3.6;
	printf("A velocidade em m/s é %.2lf.\n", calc);
	
	return;
}//kmh_to_ms

void ms_to_kmh(void)
{
	double vel;
	double calc;
	
	printf("Digite a velocidade (m/s): ");
	scanf("%lf", &vel);
	getchar();
	calc = vel * 3.6;
	printf("A velocidade em km/h é %.2lf.\n", calc);
	
	return;
}//ms_to_kmh

void menu(void)
{
	char opcao = '0';
	
	while(opcao != '3')
	{
		printf("<< Conversor >>\n");
		printf("Opções:\n");
		printf("1 - para converter de km/h para m/s\n");
		printf("2 - para converter de m/s para hm/h\n");
		printf("q - para sair.\n");
		printf("Digite uma opção: ");
		scanf("%c", &opcao);
		getchar();
		
		if(opcao == '1')
		{
			kmh_to_ms();
			opcao = '0';
		}else if(opcao == '2'){
			ms_to_kmh();
			opcao = '0';
		}else{
			if(opcao == 'q')
			{
				opcao = '3';
			}else{
				printf("Opção inválida!!!\n");
				opcao = '0';
			}//if else
		}//if else
	}//while
	
	return;
}//menu

int main(void)
{
	menu();
	
	return 0;
}//main