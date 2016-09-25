#include "pilha.h"
#include <stdlib.h>

void criar(Pilha **pilha) {
	*pilha = NULL;
}

void empilha(Pilha **pilha, Informacoes info) {
	Pilha *aux = malloc(sizeof(Pilha));
	aux->info = info;
	aux->prox = *pilha;
	*pilha = aux;
}

int estaVazia(Pilha **pilha) {
	if ((*pilha) == NULL)
		return 1;
	return 0;
}

Informacoes desempilha(Pilha **pilha) {
	Pilha *aux = *pilha;

	if (aux != NULL) {
		Informacoes info = aux->info;
		*pilha = aux->prox;
		free(aux);
		return info;
	}
	Informacoes retorno;
	retorno.linha = -1;
	retorno.coluna = -1;
	retorno.celula = 'a';

	return retorno;
}

void destroi(Pilha **pilha) {
	Pilha *prox;

	for (Pilha *aux = *pilha; aux != NULL; aux = prox) {
		prox = aux->prox;
		free(aux);
	}
}