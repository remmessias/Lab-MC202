#ifndef LAB07_FILAPRIORIDADE_H
#define LAB07_FILAPRIORIDADE_H

#include "fila.h"

#define MAX_CACHE 10000

typedef struct {
	int capacidade, quantidade, estaCheio;
	Informacoes cache[MAX_CACHE];
} FilaPrioridade;

void removeMin (FilaPrioridade fila);

void insere (Informacoes info, FilaPrioridade fila);

int temCache (Informacoes, FilaPrioridade fila);

#endif //LAB07_FILAPRIORIDADE_H
