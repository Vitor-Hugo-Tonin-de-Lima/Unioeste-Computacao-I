#include <stdio.h>
#include <math.h>

int main(){
	
	double f1, f2, f3, d1, d2, d3, k1, k2, k3, rigidezSerie, rigidezParalelo;
	
	printf("Digite os valores para as tres forcas respectivamente: ");
	scanf("%lf%lf%lf", &f1, &f2, &f3);
	
	printf("Digite os valores para as tres deflexoes respectivamente: ");
	scanf("%lf%lf%lf", &d1, &d2, &d3);
	
	k1 = f1/d1;
	k2 = f2/d2;
	k3 = f3/d3;
	
	//Associação em série
	
	rigidezParalelo = (k1 + k2 + k3);
	
	//Associação em paralelo
	
	rigidezSerie = (1/(1/k1 + 1/k2 + 1/k3));
	
	printf("\nRigidez de cada mola: %.2lf %.2lf %.2lf", k1, k2, k3);
	printf("\nRigidez em paralelo: %.2lf", rigidezParalelo);
	printf("\nRigidez em serie: %.2lf", rigidezSerie);
	
	return 0;
}
