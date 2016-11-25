#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

void criarFila(Fila **fila) {
	*fila = NULL;
}

int filaVazia(Fila **fila) {
	if (*fila != NULL)
		return 0;
	return 1;
}

void insereFila(Fila **inicioFila, Pixel pixel) {
	Fila *novoElemento;
	Fila *auxiliar;
	novoElemento = malloc(sizeof(Fila));
	novoElemento->pixel = pixel;
	novoElemento->proximo = NULL;

	if (filaVazia(inicioFila)) {
		*inicioFila = novoElemento;
	}
	else {
		auxiliar = *inicioFila;
		while (auxiliar->proximo != NULL) {
			auxiliar = auxiliar->proximo;
		}
		auxiliar->proximo = novoElemento;
	}
}

void insereComecoFila(Fila **inicioFila, Pixel pixel) {
	Fila *novoElemento;
	novoElemento = malloc(sizeof(Fila));
	novoElemento->pixel = pixel;
	novoElemento->proximo = NULL;

	if (filaVazia(inicioFila)) {
		*inicioFila = novoElemento;
	}
	else {
		novoElemento->proximo = *inicioFila;
		*inicioFila = novoElemento;
	}
}

Pixel removeFila(Fila **inicioFila) {
	Fila *auxiliar;
	Pixel retorno;

	retorno.cor = retorno.distancia = -1;
	retorno.pai = NULL;

	if (!filaVazia(inicioFila)) {
		retorno = (*inicioFila)->pixel;
		auxiliar =  *inicioFila;
		*inicioFila = (*inicioFila)->proximo;
		free(auxiliar);
	}
	return retorno;
}

void destroiFila(Fila **fila) {
	Fila *aux1 = *fila;
	Fila *aux2;

	while (aux1 != NULL) {
		aux2 = aux1;
		aux1 = aux1->proximo;
		free(aux2);
	}
	free(aux1);
}