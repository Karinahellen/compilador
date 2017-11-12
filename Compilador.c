#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define QTDE_TOTAL_LITERAIS 92 // total de símbolos permitidos
#define QTDE_LITERAIS 127 // total de símbolos da tabela ascii

#include "LiteraisTabela.h"
#include "PalavrasReservadas.h"
#include "SimbolosTabela.h"
#include "FuncoesCompilador.h"

int main()
{
    /* Preenche o vetor de literais presente na tabela ascii */
	preencher_tabela_literais();

	/* Preenche o vetor de palavras reservadas */
	preencher_palavras_reservadas();
	
	/* Iniciar a Tabela de Símbolos */
	inicializarTabelaSimbolo();

	int num, i, linha = 1;
	int contCaracter = 0;
	int programaVerificado = 0;
	int tipoVarEncontrada = 0;
	int cerquilhaEncontrada = 0;
	int posPalReservada = 0;
	int variavelValidada = 0;
	int fimVerificado = 0;
	char vetorCaracter [30];
	char vetorVariavel [30];
	
	for (i=0; i<=30; i++){
		vetorCaracter[i] = '\0';
		vetorVariavel[i] = '\0';
	}
	char c;
	
	FILE *fp;
	
	fp = fopen("novo.txt","r");
	
	if(!fp)
	{
   		printf( "Erro na abertura do arquivo");
	}

	/* Enquanto nao chegar ao final do arquivo */
	while((c = getc(fp) ) != EOF){

		/* Converte a STRING em INTEIRO*/
		num = (int) c;
		
		if(variavelValidada == 1){
			tipoVarEncontrada = 0;
			cerquilhaEncontrada = 0;
			variavelValidada = 0;
		}

		/* Desconsidera o Horizontal Tab */
		if(num != 9) {
			
			if(num == 10 && contCaracter == 0){
				/* incrementa +1 no contador de linhas */
				linha++;
			} else{
				
				if(tipoVarEncontrada == 1 && cerquilhaEncontrada == 0){
					if(num == 35){
						//printf("\nEncontrado #\n");
						cerquilhaEncontrada = 1;
					} else{
						erro(linha,num);
						break;
					}
				}
				
				if (tipoVarEncontrada == 1 && cerquilhaEncontrada == 1 && num != 35){
					verificarVariavel(num, vetorVariavel, &contCaracter, linha, &variavelValidada, &posPalReservada);
				}
				
				if(tipoVarEncontrada == 0 && cerquilhaEncontrada == 0){					
										
					if (isCaracterMinusculo(num)){ //verificar letras minusculas
						vetorCaracter[contCaracter] = num;
						contCaracter++;
		
					}else{
	
						if(num == 32 || num == 10){ // se o caracter for diferente de quebra e espaco
							
							//printf("\no vetor e: %s \n", vetorCaracter);
							
							if (programaVerificado == 0){
								isPrograma(&programaVerificado, vetorCaracter, &contCaracter, linha, num);
							}
							
							verificarPalavraReservada(vetorCaracter, &contCaracter, &posPalReservada);
		
							if (programaVerificado == 1){
								if(!isFim(vetorCaracter, &contCaracter, &fimVerificado)){
									//printf("\nFIM nao encontrado!\n");
								}
							}
					
							if(posPalReservada == 6 || posPalReservada == 7 || posPalReservada == 8){
								//printf("\nEncontrei tipo de variavel: %s \n", palavraReservada[posPalReservada]);
								if(num == 10){
									erro(linha,num);
								}
								tipoVarEncontrada = 1;
							}
							
							if (num == 10) {
								linha++;
							}
						}else if(tipoVarEncontrada == 0){
							//printf("\nNao e palavra reservada \n");
							erro(linha,num);
						}
					}
				
				}
			}	
		}
	}
	
	visualizarTabela(TABELA_SIMBOLOS);
	limparTabela(TABELA_SIMBOLOS);
	
	fclose(fp);
	return 0;
}
