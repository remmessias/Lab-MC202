#include "rotacao.h"

void rightRotate(SplayTreeNode **nodePtr) {
	SplayTreeNode *currentRoot = (*nodePtr)->l;
	SplayTreeNode *newRoot = currentRoot->r;
	currentRoot->r = (*nodePtr);
	(*nodePtr)->l = newRoot;
	*nodePtr = currentRoot;
}

void leftRotate(SplayTreeNode **nodePtr) {
	SplayTreeNode *currentRoot = (*nodePtr)->r;
	SplayTreeNode *newRoot = currentRoot->l;
	currentRoot->l = (*nodePtr);
	(*nodePtr)->r = newRoot;
	*nodePtr = currentRoot;
}

void leftRightRotate(SplayTreeNode **nodePtr) {
	SplayTreeNode *currentRoot = *nodePtr;
	leftRotate(&currentRoot->l);
	rightRotate(&(*nodePtr));
}

void rightLeftRotate(SplayTreeNode **nodePtr) {
	SplayTreeNode *currentRoot = *nodePtr;
	rightRotate(&currentRoot->r);
	leftRotate(&(*nodePtr));
}