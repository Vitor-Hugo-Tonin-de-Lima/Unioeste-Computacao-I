#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
	
	//Declaracao das variaveis
	char entrada[100];		//Valor do usuario
	char digitos[100];		//Resultado a ser devolvido 
	int contador = 0;		//Contador para escrever a string de resposta
	int decimais, numeroEncontrado, negativo;		//Variaveis para serem usadas em condicionais
	decimais = numeroEncontrado = negativo = 1;
	
	//Recebe a expressao do usuario
	printf("Digite a sentenca a ser processada: \n");
	fgets(entrada, sizeof(entrada), stdin);
	
	//Elimina a quebra de linha no final da string se houver
	int tamanho = strlen(entrada);
	if (entrada[tamanho - 1] == '\n') {
            entrada[tamanho - 1] = '\0';
        }
	
	//Comeca a leitura
	for(int i=0;i<strlen(entrada);i++){
		//Verifica se trata-se de um digito(0-9)
		int digito = isdigit(entrada[i]);
		
		if(numeroEncontrado){					//Verifica se a ja encontrou um numero
			if(digito == 0){
				if(entrada[i] == '+'){			//Ignora o sinal positivo
					numeroEncontrado = 0;
					
				} else if(entrada[i] == '-'){	//Verifica se a expressao e negativa
					negativo = 0;
					numeroEncontrado = 0;
					
				} else if(entrada[i] == '.'){	//Verifica se o numero inicia como decimal
					digitos[contador] = '0';
					contador++;
					digitos[contador] = '.';
					contador++;
					decimais == 0; 
					
				} else if(isspace(entrada[i])){	//Ignora espacos em branco
				
				}else{							//Finaliza o loop se nao reconhecer um numero
					break;
				}
				
			} else if(digito){					
					digitos[contador] = entrada[i];
					contador++;
					numeroEncontrado = 0;
				}
				
		} else{									//Continua a leitura de um numero ja encontrado
			if(digito){
				digitos[contador] = entrada[i];
				contador++;
				
			} else if(decimais){				//Verifica se ja estao sendo escritos valores decimais
				if(entrada[i] == '.'){
					if(entrada[i-1] == '+' || entrada[i-1] == '-'){
						digitos[contador] = '0';
						contador++;
					}
					digitos[contador] = '.';
					contador++;
					decimais = 0;
				} else{	
					break;
				}
					
			} else{								//Encerra o loop caso nao consiga fazer a leitura de um numero
				break;
			}
		}
	}
	
	digitos[contador] = '\0';					//Adiciona o digito nulo ao final da string
	
    if (contador == 0) {						//Retorna zero se nenhum valor foi encontrado
        strcpy(digitos, "Resultado: 0.00");
    }

    if (negativo == 0) {						//Imprime o valor encontrado
        printf("Resultado: -%s\n", digitos);
    } else {
        printf("Resultado: %s\n", digitos);
    }
	
	return 0;
}
