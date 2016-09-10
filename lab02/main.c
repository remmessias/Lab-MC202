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
 * Função que acessa uma chave em uma lista do jeito MTF
 */
int acessaMTF(No **lista, int chave) {
	return 0;
}

/*
 * Função que acessa uma chave em uma lista do jeito TR
 */
int acessaTR(No **lista, int chave) {
	return 0;
}

/*
 * Função que insere uma chave em uma lista do jeito MTF
 */
int insereMTF(No **lista, int chave) {
	return 0;
}

/*
 * Função que insere uma chave em uma lista do jeito TR
 */
int insereTR(No **lista, int chave) {
	return 0;
}

/*
 * Função que remove uma chave em uma lista do jeito MTF
 */
int removeMTF(No **lista, int chave) {
	return 0;
}

/*
 * Função que remove uma chave em uma lista do jeito TR
 */
int removeTR(No **lista, int chave) {
	return 0;
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
 * Função que escreve uma lista ou uma sublista na tela.
 */
void escreve(No **lista) {
	No *atual = *lista;

	while (atual != NULL) {
		printf("%d ", atual->chave);
		atual = atual->proximo;
	}
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

void leInstrucoes(No **listaMTF, No **listaTR, int requisicoes) {
	int custoMTF = 0, custoTR = 0, chave, i;
	char acao;

	for (i = 0; i < requisicoes; i++) {
		scanf(" %c %d", &acao, &chave);
		switch (acao) {
			case ACESSAR:
				//MTF
				custoMTF += acessaMTF(listaMTF, chave);
				//TR
				custoTR += acessaTR(listaTR, chave);
				break;
			case INSERIR:
				//MTF
				custoMTF += insereMTF(listaMTF, chave);
				//TR
				custoTR += insereTR(listaTR, chave);
				break;
			case REMOVER:
				//MTF
				custoMTF += removeMTF(listaMTF, chave);
				//TR
				custoTR += removeTR(listaTR, chave);
				break;
			default:
				break;
		}
	}
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