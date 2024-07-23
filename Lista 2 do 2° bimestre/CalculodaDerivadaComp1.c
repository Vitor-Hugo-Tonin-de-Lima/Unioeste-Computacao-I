#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
	
	char termosEntrada[100];			//String dos termos de entrada
	char polinomios[5][20];				//Array de strings a serem derivados
	int coeficientesResposta[5];		//Array de coeficientes derivados
	int expoentesResposta[5];			//Array de expoentes derivados
	int quantidadeTermos = 1;			//Variável que armazena quantos termos estão presentes
	char *termo, *variavel;				//Ponteiros para utilizar no strtok
	
	while(1){
		//Insere a quantidade de termos da expressão
		printf("Digite a quantidade de termos da espressao: \n");
		scanf("%d",&quantidadeTermos);
		
		//Encerra o programa se o numero digitado for 0
		if(quantidadeTermos == 0){
			break;
		}
		
		//Limpa o buffer de entrada
		fflush(stdin);
		
		//Recebe o valor para a expressão como uma string
		printf("Digite a expressao a ser derivada: \n");
		fgets(termosEntrada, sizeof(termosEntrada), stdin);
		
		//Separa as strings de acordo com os espaços, pulando o sinal de "+"
		termo = strtok(termosEntrada," ");
		for(int i=0;i<quantidadeTermos;i++){
			if(strcmp(termo,"+") != 0){
				for(int j=0;j<sizeof(termo);j++){
					polinomios[i][j] = termo[j];
				}	
			}else{
				i--;
			}
			termo = strtok(NULL, " ");
		}
		
		//Separa os coeficientes e expoentes de cada polinômio, derivando eles e armazenando novamente
		for(int i=0;i<quantidadeTermos;i++){
			variavel = strtok(polinomios[i],"x");
			int coeficiente = atoi(variavel);
			
			variavel = strtok(NULL,"x");
			int expoente = atoi(variavel);
			
			coeficiente *= expoente;
			expoente -= 1;
			
			coeficientesResposta[i] = coeficiente;
			expoentesResposta[i] = expoente;
		}
		
		//Imprime os resultados da operacao
		printf("A expressao derivada esta a seguir: \n");
		printf("%dx%d",coeficientesResposta[0],expoentesResposta[0]);
			
		for(int i=1;i<quantidadeTermos;i++){
			printf(" + %dx%d",coeficientesResposta[i],expoentesResposta[i]);
		}
		
		printf("\n");
	}
	
	return 0;
}
