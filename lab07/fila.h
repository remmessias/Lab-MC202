#ifndef LAB07_FILA_H
#define LAB07_FILA_H

#include <stdlib.h>

typedef struct NoFila {
	int valor;
	struct NoFila *proximo;
} NoFila;

/*
 * Função para criar uma fila
 */
void criaFila(NoFila **no);

/*
 * função que verifica d=se uma fila esta vazia
 */
int filaVazia(NoFila **no);

/*
 * Função que insere um elemento na fila
 */
void insereFila(NoFila** no, int info);

/*
 * Função que remove um elemento da fila
 */
int removeFila(NoFila **no);

/*
 * Função que verifica se a fila possui um elemento
 */
int temElemento(NoFila **no, int elemento);

/*
 * Função que verifica destroi uma fila
 */
void destroiFila(NoFila **no);

/*
 * Função que conta a distância do nó em relação ao começo da fila
 */
int distancia(NoFila **fila, int valor);

#endif //LAB07_FILA_H