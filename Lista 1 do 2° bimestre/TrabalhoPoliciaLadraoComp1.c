#include <stdio.h>
#include <math.h>

int main(){
	double milhasParaNos = 0.868976f;
	double rio = 12 * milhasParaNos;
	
	int d, vl, vp;
	double distanciaNos, percLadrao, percPolicia, tempoLadrao, tempoPolicia;
	
	printf("Digite o valor para a distancia entre os dois: ");
	scanf("%d",&d);
	
	printf("Digite o valor para a velocidade do ladrao: ");
	scanf("%d",&vl);
	
	printf("Digite o valor para a velocidade da policia: ");
	scanf("%d",&vp);
	
	percLadrao = rio;
	
	distanciaNos = d * milhasParaNos;
	
	percPolicia = sqrt((rio*rio)+(distanciaNos*distanciaNos));
	
	tempoLadrao = percLadrao / vl;
	tempoPolicia = percPolicia / vp;
	
	if(tempoLadrao >= tempoPolicia){
		printf("A policia alcancou.\n");
		
	} else{
		printf("A policia nao alcancou.\n");
		
	}
	
	return 0;
}
