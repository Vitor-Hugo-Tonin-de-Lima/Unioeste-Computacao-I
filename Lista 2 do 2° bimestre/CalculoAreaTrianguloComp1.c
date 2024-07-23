#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	
	int coordenadas[3][3];		//Matriz para armazenar os valores
	double resultado;		//Variavel para armazenar o resultado da operação
	
	//Loop para o usuário inserir o valor de cada ponto individualmente
	for(int i=0;i<3;i++){
		printf("Digite as coordenadas do vertice %d: ",i+1);
		scanf("%d%d", &coordenadas[0][i], &coordenadas[1][i]);
		coordenadas[2][i] = 1;
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d ", coordenadas[i][j]);
		}
		printf("\n");
	}
	
	//Calculo da determinante da matriz
	int diagonaisPrincipais = 0;
	int diagonaisSecundarias = 0;
	
	diagonaisPrincipais += coordenadas[0][0] * coordenadas[1][1];
	diagonaisPrincipais += coordenadas[0][1] * coordenadas[1][2];
	diagonaisPrincipais += coordenadas[0][2] * coordenadas[1][0];
	
	diagonaisSecundarias += coordenadas[0][2] * coordenadas[1][1];
	diagonaisSecundarias += coordenadas[0][1] * coordenadas[1][0];
	diagonaisSecundarias += coordenadas[0][0] * coordenadas[1][2];

	resultado = diagonaisPrincipais - diagonaisSecundarias;
	
	//Calculo do restante da operação	
	if(resultado < 0){
		resultado = resultado * (-1);
	}
	resultado = resultado / 2;
	
	//Impressão do resultado
	printf("A area do triangulo e de: %.2lf", resultado);
	
	return 0;
}
