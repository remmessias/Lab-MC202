#ifndef LAB07_FILAPRIORIDADE_H
#define LAB07_FILAPRIORIDADE_H

#include "fila.h"

#define MAX_CACHE 10000

typedef struct {
	int capacidade, quantidade, estaCheio;
	Informacoes *cache;
} FilaPrioridade;

FilaPrioridade inicializaFila (int tamCache);

void removeMin (FilaPrioridade fila);

void insere (Informacoes info, FilaPrioridade fila);

int temCache (Informacoes info, FilaPrioridade fila);

#endif //LAB07_FILAPRIORIDADE_H
