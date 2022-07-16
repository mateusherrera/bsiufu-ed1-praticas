#include <stdio.h>

int main(void)
{
	int v[5];
	int v1[5] = {2, 2, 2, 2, 2};
	int v2[5] = {3, 3, 3, 3, 3};
	
	printf("<< Pares e Ímpares >>\n");
	for(int i = 0, i1 = 0, i2 = 0; i < 5; i++)
	{
		printf("Digite o valor %d: ", i + 1);
		scanf("%d", &v[i]);
		if(v[i] % 2 != 0)
		{
			v1[i1] = v[i];
			i1++;
		}else{
			v2[i2] = v[i];
			i2++;
		}//if else
	}//for
	
	printf("Ímpares: ");
	for(int i = 0; i < 5 && v1[i] % 2 != 0; i++)
		printf("%d  ", v1[i]);
	printf("\nPares: ");
	for(int i = 0; i < 5 && v2[i] % 2 == 0; i++)
		printf("%d  ", v2[i]);
	printf("\n");
	
	return 0;
}//main