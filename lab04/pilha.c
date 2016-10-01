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

Informacoes getTopo(Pilha **pilha) {
	if (*pilha == NULL) {
		Informacoes info;
		info.coluna = -1;
		info.linha = -1;
		info.celula = 'z';
		return info;
	}
	return (*pilha)->info;
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