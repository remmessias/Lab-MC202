#ifndef LAB06_LISTACLIENTES_H
#define LAB06_LISTACLIENTES_H

#include "tipos.h"

void criaListaClientes(Cliente **no);

int listaClientesVazia(Cliente **no);

void insereListaClientes(Cliente **no, Informacoes ingrediente);

Informacoes removeListaClientes(Cliente **no);

void escreveListaClientes(Cliente **no);

#endif //LAB06_LISTACLIENTES_H
