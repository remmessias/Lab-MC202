#ifndef LAB07_GERENCIACACHE_H
#define LAB07_GERENCIACACHE_H

#include "fila.h"
#include "filaPrioridade.h"

void leEspecificacoes(int *c, int *n, int *a);

void escreveAcessos(int qtdAcessos);

int calculaAcessos(NoFila **fila, FilaPrioridade *filaPrioridade);

void leAcessos(NoFila **fila, int qtdSolicitacao);

#endif //LAB07_GERENCIACACHE_H
