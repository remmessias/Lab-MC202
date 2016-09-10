#include <stdio.h>
#include <stdlib.h>

#define ACESSAR 'a'
#define INSERIR 'i'
#define REMOVER 'r'

//////////////////////////////////////////////////////
//                                                  //
//                                                  //
//          Funções e definição de lista.           //
//      Todas as funções operam sobre uma lista     //
//                                                  //
//                                                  //
//////////////////////////////////////////////////////

// Definição de um nó (elemento da lista)
typedef struct No {
	int chave;
	struct No *proximo;
		struct No *anterior;
} No;

/*
 * Função que cria uma lista.
 */
void criar(No **lista) {
	*lista = NULL;
}

/*
 * Função que insere um novo elemento no final da lista.
 */
void insere(No **lista, int numero) {
	No *novo, *atual = *lista;
	novo = malloc(sizeof(No));
	if (atual == NULL) {
		novo->chave = numero;
		novo->proximo = NULL;
		novo->anterior = NULL;
		*lista = novo;
	}
	else {
		while (atual->proximo != NULL) {
			atual = atual->proximo;
		}
		novo->chave = numero;
		novo->proximo = NULL;
		novo->anterior = atual;
		atual->proximo = novo;
	}
}

/*
 * Função que escreve uma lista na tela.
 */
void escreve(No **lista) {
	No *atual = *lista;

	while (atual->proximo != NULL) {
		printf("%d ", atual->chave);
		atual = atual->proximo;
	}
	printf("%d\n", atual->chave);
}

/*
 * Função que inverte dois nós de uma lista
 */
void inverte(No **lista, No *no) {
	No *proximo = no->proximo;
	No *anterior = no->anterior;

	if (proximo == NULL) {
		anterior->anterior->proximo = no;
		no->anterior = anterior->anterior;
		no->proximo = anterior;
		anterior->anterior = no;
		anterior->proximo = proximo;
	}
	else if (anterior->anterior == NULL) {
		no->anterior = NULL;
		no->proximo = anterior;
		anterior->anterior = no;
		anterior->proximo = proximo;
		proximo->anterior = anterior;
		(*lista) = no;
	}
	else {
		anterior->anterior->proximo = no;
		no->anterior = anterior->anterior;
		no->proximo = anterior;
		anterior->anterior = no;
		anterior->proximo = proximo;
		proximo->anterior = anterior;
	}
}

/*
 * Função que coloca um nó no começo da lista
 */
void colocaComeco(No **lista, No *no) {

	if (no->proximo == NULL) {
		no->anterior->proximo = no->proximo;
		no->anterior = NULL;
		no->proximo = *lista;
		(*lista)->anterior = no;
	}
	else {
		no->anterior->proximo = no->proximo;
		no->proximo->anterior = no->anterior;
		no->anterior = NULL;
		no->proximo = *lista;
		(*lista)->anterior = no;
	}
}

/*
 * Função que acessa uma chave em uma lista do jeito MTF
 */
int acessaMTF(No **lista, int chave) {
	int custo = 0;
	No *atual;
	for (atual = *lista; atual->chave != chave; atual = atual->proximo) {
		custo++;
	}
	custo++;

	if (custo > 1)
		colocaComeco(lista, atual);

	*lista = atual;

	return custo;
}

/*
 * Função que acessa uma chave em uma lista do jeito TR
 */
int acessaTR(No **lista, int chave) {
	int custo = 0;
	No *atual;
	for (atual = *lista; atual->chave != chave; atual = atual->proximo) {
		custo++;
	}
	custo++;

	if (custo > 1)
		inverte(lista, atual);
	return custo;
}

/*
 * Função que insere uma chave em uma lista do jeito MTF
 */
int insereMTF(No **lista, int chave) {
	No *novo, *atual = *lista;
	int custo = 0;
	novo = malloc(sizeof(No));

	while (atual->proximo != NULL) {
		custo++;
		atual = atual->proximo;
	}
	custo += 2;
	novo->chave = chave;
	novo->proximo = NULL;
	novo->anterior = atual;
	atual->proximo = novo;

	return custo;
}

/*
 * Função que insere uma chave em uma lista do jeito TR
 */
int insereTR(No **lista, int chave) {
	No *novo, *atual = *lista;
	int custo = 0;
	novo = malloc(sizeof(No));

	while (atual->proximo != NULL) {
		custo++;
		atual = atual->proximo;
	}
	custo += 2;
	novo->chave = chave;
	novo->proximo = NULL;
	novo->anterior = atual;
	atual->proximo = novo;

	inverte(lista, novo);

	return custo;
}

/*
 * Função que remove uma chave em uma lista do jeito MTF
 */
int removeMTF(No **lista, int chave) {
	No *atual = *lista;
	int custo = 0;

	while (atual->chave != chave) {
		custo++;
		atual = atual->proximo;
	}
	custo++;
	atual->proximo->anterior = atual->anterior;
	atual->anterior->proximo = atual->proximo;
	free(atual);

	return custo;
}

/*
 * Função que remove uma chave em uma lista do jeito TR
 */
int removeTR(No **lista, int chave) {
	No *atual = *lista;
	int custo = 0;
	while (atual->chave != chave) {
		custo++;
		atual = atual->proximo;
	}
	custo++;
	if (atual->anterior == NULL) {
		atual->proximo->anterior = NULL;
		(*lista) = atual->proximo;
		free(atual);
	}
	else if (atual->proximo == NULL) {
		atual->anterior->proximo = NULL;
		free(atual);
	}
	else {
		atual->proximo->anterior = atual->anterior;
		atual->anterior->proximo = atual->proximo;
		free(atual);
	}


	return custo;
}

/*
 * Função que lê chaves e os insere na lista
 */
void leLista(No **listaMTF, No **listaTR, int tamanho) {
	int elemento = -1, i;
	for (i = 0; i < tamanho; i++) {
		scanf(" %d", &elemento);
		insere(listaMTF, elemento);
		insere(listaTR, elemento);
	}
}

/*
 * Função que verifica se uma lista esta vazia
 */
int estaVazia(No **lista) {
	if ((*lista) != NULL)
		return 0;
	return 1;
}

/*
 * Função que destrói a lista após ser utilizada.
 */
void destruir(No **lista) {
	No *atual, *proximo;
	proximo = *lista;
	while (proximo != NULL) {
		atual = proximo;
		proximo = atual->proximo;
		free(atual);
	}
}

////////////////////// FIM OPERAÇÕES TRIVIAIS COM A LISTA

/*
 * Função que escreve a saída na tela para o usuário
 */
void escreveSaida(No **listaMTF, No **listaTR, int custoMTF, int custoTR) {
	printf("%d\n", custoMTF);
	if (estaVazia(listaMTF))
		printf("\n");
	else
		escreve(listaMTF);
	printf("%d\n", custoTR);
	if (estaVazia(listaTR))
		printf("\n");
	else
		escreve(listaTR);
}

void leInstrucoes(No **listaMTF, No **listaTR, int requisicoes) {
	int custoMTF = 0, custoTR = 0, chave, i;
	char acao;

	for (i = 0; i < requisicoes; i++) {
		scanf(" %c %d", &acao, &chave);
		switch (acao) {
			case ACESSAR:
				custoMTF += acessaMTF(listaMTF, chave);
				custoTR += acessaTR(listaTR, chave);
				break;
			case INSERIR:
				custoMTF += insereMTF(listaMTF, chave);
				custoTR += insereTR(listaTR, chave);
				break;
			case REMOVER:
				custoMTF += removeMTF(listaMTF, chave);
				custoTR += removeTR(listaTR, chave);
				break;
			default:
				break;
		}
	}

	escreveSaida(listaMTF, listaTR, custoMTF, custoTR);
}

int main() {
	No *listaMTF;
	No *listaTR;
	int tamanhoInicial, numRequisicoes;

	criar(&listaMTF);
	criar(&listaTR);

	scanf("%d %d", &tamanhoInicial, &numRequisicoes);

	leLista(&listaMTF, &listaTR, tamanhoInicial);

	leInstrucoes(&listaMTF, &listaTR, numRequisicoes);

	destruir(&listaMTF);
	destruir(&listaTR);

	return 0;
}