
//Função que retorna erro
void erro(int linha, char num){
	printf("\nErro na linha: %i \nO erro e: %c \n", linha, num);
	limparTabela(TABELA_SIMBOLOS);
	exit(0);
}

//Função que verifica se o caracter é minusculo
int isCaracterMinusculo (char num){
	if (num >= 97 && num <= 122){
		return 1;
	}
	return 0;
}

//Função que verifica se o caracter é maiusculo
int isCaracterMaiusculo (char num){
	if (num >= 65 && num <= 90){
		return 1;
	}
	return 0;
}

//Função que verifica se o caracter é um número
int isCaracterNumerico (char num){
	if (num >= 48 && num <= 57){
		return 1;
	}
	return 0;
}

//Função que verifica palavra reservada "programa"
int isPrograma (int *programaVerificado, char *vetorCaracter, int *contCaracter, int linha, char num){
	if(strcasecmp("programa", vetorCaracter) == 0) {
		memset(vetorCaracter,0,strlen(vetorCaracter));
		*contCaracter = 0;
		*programaVerificado = 1;
	}else{
		erro(linha, num);
	}
}

//Função que compara as palavras lidas no arquivo com as palavras reservadas do vetor
void verificarPalavraReservada(char *vetorCaracter, int *contCaracter, int *posPalReservada){
	int i;
	for(i=1; i < 9; i++){
		if (strcasecmp(palavraReservada[i], vetorCaracter) == 0){
			memset(vetorCaracter,0,strlen(vetorCaracter));
			*contCaracter = 0;
			*posPalReservada = i;
		}							
	}
}

//Função que valida a variavel
void verificarVariavel (char num, char *vetorVariavel, int *contCaracter, int linha, int *variavelValidada, int *posPalReservada){
	if(isCaracterMinusculo(num) || isCaracterMaiusculo(num) || isCaracterNumerico(num)){
		vetorVariavel[*contCaracter] = num;
		*contCaracter += 1;
	}else if (num == 32 || num == 44 || num == 59){
		validarNomeVariavel(contCaracter, vetorVariavel, linha, num);
		//printf("\nVariavel - %s\n", vetorVariavel);
		
		if(num == 59){
			*contCaracter = 0;
			*variavelValidada = 1;
			inserirFimTabela(TABELA_SIMBOLOS, palavraReservada[*posPalReservada], vetorVariavel, "null");
			memset(vetorVariavel,0,strlen(vetorVariavel));
			*posPalReservada = 0;
		}
	}else{
		erro(linha,num);
	}
}

//Função que vai percorrer a variavel, validando os caracteres
void validarNomeVariavel(int *contCaracter, char *vetorVariavel, int linha, char num){
	int i;
	for(i = 0; i < *contCaracter; i++){
		int caracterVariavel = vetorVariavel[i];
		if(i == 0){
			if (!isCaracterMinusculo(caracterVariavel)){
				erro(linha,num);
			}
		}else{
			if(!isCaracterMinusculo(caracterVariavel) && !isCaracterMaiusculo(caracterVariavel) && !isCaracterNumerico(caracterVariavel)){
				erro(linha,num);
			}
		}
	}
}

//Função que verifica se chegou no FIM
int isFim (char *vetorCaracter, int *contCaracter, int *fimVerificado){
	if(strcasecmp("fim", vetorCaracter) == 0){
		memset(vetorCaracter,0,strlen(vetorCaracter));
		*contCaracter = 0;
		*fimVerificado = 1;	
		return 1;
	}
	return 0;
}


