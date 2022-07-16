#include <stdio.h>

int main(void)
{
	char nome[13] = "José Augusto";
	
	for(int i = 0; i < 13; i++)
		printf("%c", *(nome + i));
	printf("\n");
	
	return 0;
}//main