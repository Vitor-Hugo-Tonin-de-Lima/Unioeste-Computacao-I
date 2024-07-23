#include <stdio.h>

int main(){
	
	int numerosDiv = 0;
	int numeros[15];
	int soma = 0;
	
	while(numerosDiv < 15){
		int numero;
		
		printf("Digite um numero divisivel por 3: ");
		scanf("%d",&numero);
		
		if((numero % 3) == 0){
			numeros[numerosDiv] = numero;
			numerosDiv += 1;
		} else{
			printf("O numero inserido nao e divisivel por 3.\n");
		}
	}
	
	for(int i=0;i<15;i++){
		soma += numeros[i];
	}
	
	printf("A soma dos numeros inseridos e: %d", soma);
	
	return 0;
}
