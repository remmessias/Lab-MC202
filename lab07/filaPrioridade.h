#ifndef LAB07_FILAPRIORIDADE_H
#define LAB07_FILAPRIORIDADE_H

#include "fila.h"

typedef struct {
	int capacidade, quantidade, estaCheio, estaVazio;
	Informacoes *cache;
} FilaPrioridade;

FilaPrioridade inicializaFila (int tamCache);

void removeMin (FilaPrioridade *fila);

void insere (Informacoes info, FilaPrioridade *fila);

int temCache (Informacoes info, FilaPrioridade *fila);

int menorFilho(int i, FilaPrioridade *fila);

void troca(FilaPrioridade *fila, int pai, int menor);

#endif //LAB07_FILAPRIORIDADE_H
