struct registroTabelaSimbolo{
	char tipo[9];
	char nome[100];
	char valor[100];
	struct registroTabelaSimbolo *prox;
};

typedef struct registroTabelaSimbolo registroTabelaSimbolo;

registroTabelaSimbolo *TABELA_SIMBOLOS;

void inicializarTabelaSimbolo()
{
	TABELA_SIMBOLOS = (registroTabelaSimbolo *) malloc(sizeof(registroTabelaSimbolo));
	
	if(!TABELA_SIMBOLOS){
		
		printf("Sem memoria disponivel!\n");
		exit(1);
		
	}else{
		
		TABELA_SIMBOLOS->prox = NULL;
		
	}
}

int isTabelaVazia(registroTabelaSimbolo *TABELA_SIMBOLOS)
{
	if(TABELA_SIMBOLOS->prox == NULL)
		return 1;
	else
		return 0;
}

registroTabelaSimbolo *aloca(char *tipo, char *nome, char *valor)
{
	registroTabelaSimbolo *novo=(registroTabelaSimbolo *) malloc(sizeof(registroTabelaSimbolo));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		strcpy(novo->tipo, tipo);
		strcpy(novo->nome, nome);
		strcpy(novo->valor, valor);
		return novo;
	}
}

int inserirFimTabela(registroTabelaSimbolo *TABELA_SIMBOLOS, char *tipo, char *nome, char *valor)
{
	registroTabelaSimbolo *novo=aloca(tipo, nome, valor);
	novo->prox = NULL;
	
	if(isTabelaVazia(TABELA_SIMBOLOS))
		TABELA_SIMBOLOS->prox=novo;
	else{
		registroTabelaSimbolo *registro = TABELA_SIMBOLOS->prox;
		
		while(registro->prox != NULL){
			if((strcmp(registro->tipo, tipo) == 0) && (strcmp(registro->nome, nome) == 0)) // verifica se o tipo e o nome da variável encontrada é igual ao tipo e o nome da variável do identificador de usuário da vez (conforme o laço)
				return 0;
				
			registro = registro->prox;
		}
		
		if((strcmp(registro->tipo, tipo) == 0) && (strcmp(registro->nome, nome) == 0)) // verifica se o tipo da variável encontrada é igual ao tipo da variável do identificador de usuário da vez (conforme o laço)
			return 0;
			
		registro->prox = novo;
	}
	return 1;
}

int verificarExistenciaVariavel(registroTabelaSimbolo *TABELA_SIMBOLOS, char *nome)
{
	registroTabelaSimbolo *registro = TABELA_SIMBOLOS->prox;
	
	while(registro->prox != NULL){
		if(strcmp(registro->nome, nome) == 0){ // verifica se o tipo e o nome da variável encontrada é igual ao tipo e o nome da variável do identificador de usuário da vez (conforme o laço)
			return 1;
			break;
		}
		registro = registro->prox;
	}
	
	if(strcmp(registro->nome, nome) == 0) // verifica se o tipo da variável encontrada é igual ao tipo da variável do identificador de usuário da vez (conforme o laço)
		return 1;
	
	return 0;
}

void alterarValorVariavel(registroTabelaSimbolo *TABELA_SIMBOLOS, char *nome, char *valor)
{
	registroTabelaSimbolo *registro = TABELA_SIMBOLOS->prox;
	
	while(registro->prox != NULL){
		if(strcmp(registro->nome, nome) == 0){ // verifica se o tipo e o nome da variável encontrada é igual ao tipo e o nome da variável do identificador de usuário da vez (conforme o laço)
			strcpy(registro->valor, valor);
			break;
		}
		registro = registro->prox;
	}
	
	if(strcmp(registro->nome, nome) == 0) // verifica se o tipo da variável encontrada é igual ao tipo da variável do identificador de usuário da vez (conforme o laço)
		strcpy(registro->valor, valor);
}

void visualizarTabela(registroTabelaSimbolo *TABELA_SIMBOLOS)
{
	//system("clear");
	if(isTabelaVazia(TABELA_SIMBOLOS)){
		printf("Tabela de Simbolos vazia!\n\n");
		return ;
	}
	
	registroTabelaSimbolo *registro;
	registro = TABELA_SIMBOLOS->prox;
	printf("TABELA DE SIMBOLOS:\n\n");
	printf("%-13s | %-13s | %-13s \n\n", "TIPO", "NOME", "VALOR");
	while( registro != NULL){
		printf("%-13s | %-13s | %-13s \n", registro->tipo, registro->nome, registro->valor);
		registro = registro->prox;
	}
}

void limparTabela(registroTabelaSimbolo *TABELA_SIMBOLOS)
{
	if(!isTabelaVazia(TABELA_SIMBOLOS)){
		registroTabelaSimbolo *proxNode, *atual;
		
		atual = TABELA_SIMBOLOS->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

