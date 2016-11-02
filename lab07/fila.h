#ifndef LAB07_FILA_H
#define LAB07_FILA_H

#include <stdlib.h>

typedef struct {
	int valor, frequencia;
} Informacoes;

typedef struct NoFila {
	Informacoes info;
	struct NoFila *proximo;
} NoFila;

void criaFila(NoFila **no);

int filaVazia(NoFila **no);

void insereFila(NoFila** no, Informacoes info);

Informacoes removeFila(NoFila **no);

int temElemento(NoFila **no, int elemento);

void incrementaFrequencia(NoFila **no, int elemento);

void decrementaFrequencia(NoFila **no, int elemento);

int getFrequencia(NoFila **no, int elemento);

void destroiFila(NoFila **no);

#endif //LAB07_FILA_H