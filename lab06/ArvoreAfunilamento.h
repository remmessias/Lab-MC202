#ifndef SPLAYTREE_SPLAYTREES_H
#define SPLAYTREE_SPLAYTREES_H

#include "tipos.h"

SplayTreeNode *criaNo(Ingrediente data);
void insereArvore(SplayTreeNode **rootPtr, SplayTreeNode *addNode);
SplayTreeNode *excluiArvore(SplayTreeNode **rootPtr, SplayTreeNode *deleteNode);
SplayTreeNode *procuraArvore(SplayTreeNode **rootPtr, SplayTreeNode *targetNode);
void escreveArvore(SplayTreeNode **root);
void destroiArvore(SplayTreeNode **root);

#endif //SPLAYTREE_SPLAYTREES_H
