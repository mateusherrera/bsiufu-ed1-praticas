#include <stdio.h>

int main(void)
{
	double jose = 50000.0;
	double carlos = 25000.0;
	double jx = 800.0;
	double cx = 3000.0;
	double mes = 0.0;
	double ano = 0.0;
	
	while(carlos <= jose)
	{
		carlos += cx;
		jose += jx;
		mes++;
	}//while
	ano = mes / 12.0;
	printf("Carlos terá mais dinheiro que José depois de %.1lf ano(s).\n", ano);
	
	return 0;
}//main