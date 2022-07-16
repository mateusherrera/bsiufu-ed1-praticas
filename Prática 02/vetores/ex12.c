#include <stdio.h>

int main(void)
{
	double soma = 0.0;
	int bola[4];
	int ind_maior;
	int aux_verde = 0;
	int aux_azul = 0;
	int aux_amarelo = 0;
	int aux_vermelho = 0;
	
	printf("<< Probabilidades >>\nDigite a quantidade de bolinhas\n");
	printf("Verde: ");
	scanf("%d", &bola[0]);
	printf("Azul: ");
	scanf("%d", &bola[1]);
	printf("Amarelo: ");
	scanf("%d", &bola[2]);
	printf("Vermelho: ");
	scanf("%d", &bola[3]);
	ind_maior = 0;
	for(int i = 1; i < 4; i++)
	{
		if(ind_maior < bola[i]) ind_maior = i;
	}//for
	if(ind_maior == 0) aux_verde = 1;
	if(ind_maior == 1) aux_azul = 1;
	if(ind_maior == 2) aux_amarelo = 1;
	if(ind_maior == 3) aux_vermelho = 1;
	for(int i = 0; i < 4; i++)
		soma += bola[i];
	
	printf("\nProbabilidades\n");
	printf("Verde: %.2lf%%", bola[0] * 100.0 / soma);
	if(aux_verde == 1) printf("  << Maior probabilidade");
	printf("\nAzul: %.2lf%%", bola[1] * 100.0 / soma);
	if(aux_azul == 1) printf("  << Maior probabilidade");
	printf("\nAmarelo: %.2lf%%", bola[2] * 100.0 / soma);
	if(aux_amarelo == 1) printf("  << Maior probabilidade");
	printf("\nVermelho: %.2lf%%", bola[3] * 100.0 / soma);
	if(aux_vermelho == 1) printf("  << Maior probabilidade");
	printf("\n");
	
	return 0;
}//main