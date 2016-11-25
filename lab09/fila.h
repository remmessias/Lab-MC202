#ifndef LAB9_FILA_H
#define LAB9_FILA_H

#include "imagem.h"

// ESTRUTURA DE UMA FILA
typedef struct Fila{
	Pixel pixel;
	struct Fila *proximo;
} Fila;

/*
 * Função que destroi uma fila
 */
void destroiFila(Fila **fila);

/*
 * Função que remove um elemento de uma fila
 */
Pixel removeFila(Fila **inicioFila);

/*
 * Função que insere um elemento na fila
 */
void insereFila(Fila **inicioFila, Pixel pixel);

/*
 * Função que insere no começo da fila
 */
void insereComecoFila(Fila **inicioFila, Pixel pixel);

/*
 * Função que verifica se uma fila é vazia
 */
int filaVazia(Fila **fila);

/*
 * Função que cria uma fila
 */
void criarFila(Fila **fila);

#endif //LAB9_FILA_H
