#include <stdlib.h>
#include "lista.h"
#include <stdio.h>

void criar (No **lista) {
	*lista = NULL;
}

void insere (No **lista, int numero) {
	No *novo, *atual = *lista;
	novo = malloc(sizeof(No));
	if (atual == NULL) {
		novo->numero = numero;
		novo->prox = NULL;
		*lista = novo;
	}
	else {
		while (atual->prox != NULL) {
			atual = atual->prox;
		}
		novo->numero = numero;
		novo->prox = NULL;
		atual->prox = novo;
	}
}

void destruir (No **lista) {
	No *atual, *proximo;
	proximo = *lista;
	while (proximo != NULL) {
		atual = proximo;
		proximo = atual->prox;
		free(atual);
	}
}

No *procura (No **lista, int numero) {
	No *atual = *lista;

	while (atual != NULL) {
		if (atual->numero == numero)
			return atual;
		atual = atual->prox;
	}
	return NULL;
}

void escreve (No **lista) {
	No *atual = *lista;

	while (atual != NULL) {
		printf("%d ", atual->numero);
		atual = atual->prox;
	}
}
