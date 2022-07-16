#include <stdio.h>

int main(void)
{
	char letra = 'h';
	int chance = 5;
	char resp;
	
	printf("<< Forca de uma letra só >>\n");
	do{
		printf("Qual a letra? ");
		scanf("%c", &resp);
		getchar();
		chance--;
		
		if(resp == letra)
		{
			printf("ACERTOU!\n");
			chance = 0;
		}else if (chance == 0 || chance == 1){
			if(chance == 0){
				printf("Acabaram suas chances. A letra correta é '%c'\n", letra);
			}else{
				printf("Última chance!!!\n");
			}//if else
		}else{
			printf("Errado! Você tem mais %d chances\n", chance);
		}//if else
	}while(chance != 0);
	
	return 0;
}//main