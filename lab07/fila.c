#include <printf.h>
#include "fila.h"
#include <stdio.h>

int temElemento(NoFila **no, int elemento) {
	NoFila *aux;

	for (aux = *no; aux != NULL; aux = aux->proximo) {
		if (aux->valor == elemento)
			return 1;
	}

	return 0;
}

void criaFila(NoFila **no) {
	*no = NULL;
}

int filaVazia(NoFila **no) {
	return (*no) == NULL;
}


void insereFila(NoFila **no, int info) {
	NoFila *novoElemento;
	NoFila *auxiliar;

	novoElemento = malloc(sizeof(NoFila));
	novoElemento->valor = info;
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

int removeFila(NoFila **no) {
	NoFila *auxiliar;
	int retorno;

	if (!filaVazia(no)) {
		retorno = (*no)->valor;
		auxiliar =  *no;
		*no = (*no)->proximo;
		free(auxiliar);
	}
	else {
		retorno = -1;
	}

	return retorno;
}

int distancia(NoFila **fila, int valor) {
	NoFila *aux;
	int qtdNos = 0;

	for (aux = *fila; aux->valor != valor; aux = aux->proximo) {
		qtdNos++;
	}

	return qtdNos;
}

void destroiFila(NoFila **no) {
	NoFila *aux = *no;
	NoFila *temp;

	while (aux != NULL) {
		temp = aux;
		aux = aux->proximo;
		free(temp);
	}

}