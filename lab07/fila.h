#ifndef LAB07_FILA_H
#define LAB07_FILA_H

#include <stdlib.h>

typedef struct NoFila {
	int valor;
	struct NoFila *proximo;
} NoFila;

void criaFila(NoFila **no);

int filaVazia(NoFila **no);

void insereFila(NoFila** no, int info);

int removeFila(NoFila **no);

int temElemento(NoFila **no, int elemento);

void destroiFila(NoFila **no);

int distancia(NoFila **fila, int valor);

#endif //LAB07_FILA_H