#ifndef LAB06_FILA_H
#define LAB06_FILA_H

#include "tipos.h"

void criar(Cliente **fila);

int vazia(Cliente **fila);

void insere(Cliente **fila, Informacoes info);

Cliente *remover(Cliente **fila);

void exibe(Cliente **fila);

void destroi(Cliente **fila);

#endif //LAB06_FILA_H
