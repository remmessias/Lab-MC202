#ifndef LAB06_ARVOREAFUNILAMENTO_H
#define LAB06_ARVOREAFUNILAMENTO_H

#include "tipos.h"

void rotacaoDireita(SplayTreeNode **no);

void rotacaoEsquerda(SplayTreeNode **no);

void afunila(SplayTreeNode **no);

void insereSplayTree(SplayTreeNode **no, Ingrediente ingrediente);

void imprimeInordem(SplayTreeNode **no);

SplayTreeNode *procura(SplayTreeNode **no, Ingrediente ingrediente);

bool apaga(SplayTreeNode **no, Ingrediente ingrediente);

void destroiSplayTree (SplayTreeNode **no);

#endif