#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void criar(Cliente **fila) {
	*fila = malloc(sizeof(Cliente));
	(*fila)->prox = NULL;
}

int vazia(Cliente **fila) {
	return (*fila) == NULL;
}

void insere(Cliente **fila, Informacoes info) {
	Cliente *novo;
	criar(&novo);
	novo->info = info;

	if (vazia(fila))
		*fila = novo;
	else {
		Cliente *tmp = *fila;

		while (tmp->prox != NULL)
			tmp = tmp->prox;

		tmp->prox = novo;
	}
}


Cliente *remover(Cliente **fila) {
	if (*fila == NULL)
		return NULL;

	Cliente *tmp = (*fila)->prox;
	(*fila)->prox = tmp->prox;
	return tmp;
}


void exibe(Cliente **fila) {
	if (!vazia(fila)) {
		Cliente *tmp = (*fila)->prox;

		while (tmp != NULL) {
			printf("%5d", tmp->info.senha);
			tmp = tmp->prox;
		}

		printf("\n");
	}
}

void destroi(Cliente **fila) {
	if (!vazia(fila)) {
		Cliente *proxNode, *atual;
		atual = *fila;

		while (atual != NULL) {
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}
