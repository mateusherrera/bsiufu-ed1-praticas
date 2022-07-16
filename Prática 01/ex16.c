#include <stdio.h>
#include <math.h>

int main(void)
{
	double base = 2.0;
	double expoente = 1.0;
	double pos = 0.0;
	
	for(double i = 0.0; expoente <= 128.0; expoente = pow(base, i))
	{
		i += 1.0;
		pos = pow(base, expoente);
		printf("Com %lf bits é possível endereçar %lf posições de memória\n", expoente, pos);
	}//for
	
	return 0;
}//main