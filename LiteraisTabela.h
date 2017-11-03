int literal[QTDE_TOTAL_LITERAIS];

void preencher_tabela_literais() { // preencha o vetor de literais
	int i = 0, c = 0; // vari�veis auxiliares

	while(i < QTDE_LITERAIS) { // percorre todos os simbolos permitidos da tabela ascii
		if((i != 64) && (i != 96) && (i != 94) && (i != 126)) { // valida alguns caracteres n�o permitidos
			if((i == 10) || (i >= 32)) {  // SE encontre algum s�mbolo v�lido...
				literal[c] = i; // o valor � inserido no array de s�mbolos
				c++; // o array de s�mbolos � incrementado
			} // fim if (i == 10) || (i >= 32)
		} // fim (i != 64) && (i != 96) && (i != 94) && (i != 126)

		i++; // o valor de i � incrementado
	} // fim WHILE
} // fim preencher_tabela_literais
