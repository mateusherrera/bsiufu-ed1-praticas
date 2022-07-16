#include <stdio.h>

int main(void)
{
	unsigned long int fat = 11;
	unsigned long int mult = 3628800;
	
	printf("<< Fatorial >>\n");
	while(fat <= 15)
	{
		mult = mult * fat;
		printf("%lu! = %lu\n", fat, mult);
		fat++;
	}//for
	
	return 0;
}//main

/** Caso as variáveis sejam declaradas como "int", um erro ocorrerá a partir de 13!, porque faltarão bits para calcular os 
* valores, para que isso não ocorra deve-se usar tipos como "long int" ou "unsigned long int" que reservam maior quantidade
* de bits para realização das operações.
*/