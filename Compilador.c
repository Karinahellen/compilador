#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define QTDE_TOTAL_LITERAIS 92 // total de símbolos permitidos
#define QTDE_SIMBOLOS 127 // total de símbolos da tabela ascii

#include "LiteraisTabela.h"
#include "FuncoesCompilador.h" 
#include "PalavrasReservadas.h"

int main()
{
    /* Preenche o vetor de literais presente na tabela ascii */
	preencher_tabela_literais(); 
	
	/* Preenche o vetor de palavras reservadas */	
	preencher_palavras_reservadas();
	
	int num, linha = 0, anterior=0;
	
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
				anterior = num; /* anterior recebe o numero atual */
			} 
		}
		
		/* imprime o caracter lido */
	    printf("%c", c); 
	}
	
	printf("linha: %i",linha);
	
	fclose(fp);
	return 0;
}
