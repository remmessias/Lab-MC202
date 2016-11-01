#include <printf.h>
#include "fila.h"
#include <stdio.h>

int getFrequencia(NoFila **no, int elemento) {
	NoFila * aux;

	for (aux = *no; aux != NULL; aux = aux->proximo) {
		if (aux->info.valor == elemento)
			return aux->info.frequencia;
	}

	return 0;
}

void incrementaFrequencia(NoFila **no, int elemento) {
	NoFila *aux;

	for (aux = *no; aux != NULL; aux = aux->proximo) {
		if (aux->info.valor == elemento)
			aux->info.frequencia++;
	}
}

int temElemento(NoFila **no, int elemento) {
	NoFila *aux;

	for (aux = *no; aux != NULL; aux = aux->proximo) {
		if (aux->info.valor == elemento)
			return 1;
	}

	return 0;
}

void escreveFila(NoFila **no) {
	NoFila *aux = *no;

	for (; aux != NULL; aux = aux->proximo) {
		printf("v: %d f: %d\n", aux->info.valor, aux->info.frequencia);
	}
}

void criaFila(NoFila **no) {
	*no = NULL;
}

int filaVazia(NoFila **no) {
	return (*no) == NULL;
}


void insereFila(NoFila **no, Informacoes info) {
	NoFila *novoElemento;
	NoFila *auxiliar;

	novoElemento = malloc(sizeof(NoFila));
	novoElemento->info = info;
	novoElemento->proximo = NULL;

	if (filaVazia(no)) {
		*no = novoElemento;
	}
	else {
		auxiliar = *no;
		while (auxiliar->proximo != NULL) {
			auxiliar = auxiliar->proximo;
		}

		auxiliar->proximo = novoElemento;
	}
}

Informacoes removeFila(NoFila **no) {
	NoFila *auxiliar;
	Informacoes retorno;

	if (!filaVazia(no)) {
		retorno = (*no)->info;
		auxiliar =  *no;
		*no = (*no)->proximo;
		free(auxiliar);
	}

	retorno.valor = -1;
	retorno.frequencia = -1;

	return retorno;
}