int literal[QTDE_TOTAL_LITERAIS];

void preencher_tabela_literais() { // preencha o vetor de literais
	int i = 0, c = 0; // variáveis auxiliares

	while(i < QTDE_LITERAIS) { // percorre todos os simbolos permitidos da tabela ascii
		if((i != 64) && (i != 96) && (i != 94) && (i != 126)) { // valida alguns caracteres não permitidos
			if((i == 10) || (i >= 32)) {  // SE encontre algum símbolo válido...
				literal[c] = i; // o valor é inserido no array de símbolos
				c++; // o array de símbolos é incrementado
			} // fim if (i == 10) || (i >= 32)
		} // fim (i != 64) && (i != 96) && (i != 94) && (i != 126)

		i++; // o valor de i é incrementado
	} // fim WHILE
} // fim preencher_tabela_literais
