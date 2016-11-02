#ifndef LAB07_FILAPRIORIDADE_H
#define LAB07_FILAPRIORIDADE_H

#include "fila.h"

typedef struct {
	int capacidade, quantidade, estaCheio, estaVazio;
	int *cache;
} FilaPrioridade;

FilaPrioridade inicializaFila (int tamCache);

void insere (int info, FilaPrioridade *fila);

int temCache (int info, FilaPrioridade *fila);

int menorFilho(int i, FilaPrioridade *fila);

void troca(FilaPrioridade *fila, int pai, int menor);

void removeUltimoASerAcessado(NoFila **fila, FilaPrioridade *filaPrioridade);

void remover(FilaPrioridade *filaPrioridade, int pos);

#endif //LAB07_FILAPRIORIDADE_H
