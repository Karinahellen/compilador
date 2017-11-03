#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define QTDE_TOTAL_LITERAIS 92 // total de símbolos permitidos
#define QTDE_LITERAIS 127 // total de símbolos da tabela ascii

#include "LiteraisTabela.h"
//#include "FuncoesCompilador.h" 
#include "PalavrasReservadas.h"

int main()
{
    /* Preenche o vetor de literais presente na tabela ascii */
	preencher_tabela_literais(); 
	
	/* Preenche o vetor de palavras reservadas */	
	preencher_palavras_reservadas();
	
	/*int i;
	
	for(i = 0; i<10; i++ ){
		printf("%s \n", palavraReservada[i]);
	}*/
	
	int num, linha = 1, anterior=0;
	
	char vetorCaracter [50];
	memset(vetorCaracter,0,strlen(vetorCaracter));	
	int contCaracter = 0;
		
	FILE *fp;
	char c;
	fp = fopen("novo.txt","r");
	if(!fp)
	{
   		printf( "Erro na abertura do arquivo");    
	}
	
	/* Enquanto nao chegar ao final do arquivo */
	while((c = getc(fp) ) != EOF){   
	
		/* Converte a STRING em INTEIRO*/
		num = (int) c; 
		
		/* Desconsidera o Horizontal Tab */
		if(num != 9) { 	
			/* Se VL for igual a QUEBRA DE LINHA acrescente +1 ao número de linhas */
			if(num == 10) {  
				/* incrementa +1 no contador de linhas */
				linha++; 		
			}else{ 
				if (num >= 97 && num <= 122){ //verificar letras minusculas
					/*anterior = num; /* anterior recebe o numero atual */
					
					    vetorCaracter[contCaracter] = num;				
						 contCaracter++;						 					 
						 printf("%c",num);	
				
				
				}else{
					 if(num == 32 || num == 10){ // se o caracter for diferente de quebra e espaco
							printf("\n o vetor e: %s \n", vetorCaracter);
						if (strcasecmp("programa9", vetorCaracter) == 0){
							printf("palavra encontrada");
						}
												 					 					
				   	}else{
				   			printf("\n nao e palavra reservada \n");
							printf("Erro na linha: %i",linha);
							printf(" \n %i \n",num);	
							break;
					   }										
				
				}			
			} 
		}			

	}	
	fclose(fp);
	return 0;
}
