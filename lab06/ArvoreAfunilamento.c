#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreAfunilamento.h"
#include "rotacao.h"

SplayTreeNode *criaNo(Ingrediente data) {
	SplayTreeNode *node = malloc(sizeof(SplayTreeNode));
	node->l = NULL;
	node->r = NULL;
	node->ingrediente = data;

	return node;
}

void insereArvore(SplayTreeNode **rootPtr, SplayTreeNode *addNode){
	SplayTreeNode *root = *rootPtr;
	if(root==NULL){
		*rootPtr = addNode;
		return;
	}else{
		if(strcmp(addNode->ingrediente.nome, root->ingrediente.nome) < 0){
			insereArvore(&root->l, addNode);
			rightRotate(rootPtr);
		}else if(strcmp(addNode->ingrediente.nome, root->ingrediente.nome) >= 0){
			insereArvore(&root->r, addNode);
			leftRotate(rootPtr);
		}
	}
}

SplayTreeNode *excluiArvore(SplayTreeNode **rootPtr, SplayTreeNode *deleteNode){
	SplayTreeNode *node = NULL, *root = *rootPtr;
	if(root == NULL) {
		return NULL;
	}
	else {
		if(root == deleteNode){
			*rootPtr = NULL;
			if(root->l){
				if(root->l->r){
					*rootPtr = root->l->r;
					root->l->r= NULL;
					(*rootPtr)->l= root->l;
				}else
					*rootPtr = root->l;
				(*rootPtr)->r = root->r;
			}else
				*rootPtr = root->r;
		}else{
			if(strcmp(deleteNode->ingrediente.nome, root->ingrediente.nome) < 0){
				if(root->l->r == deleteNode )
					leftRightRotate(rootPtr);
				rightRotate(rootPtr);
			}else if(strcmp(deleteNode->ingrediente.nome, root->ingrediente.nome) >= 0){
				if(root->r->l == deleteNode)
					rightLeftRotate(rootPtr);
				leftRotate(rootPtr);
			}
			node = excluiArvore(rootPtr, deleteNode);
		}
	}

	return node;
}

SplayTreeNode *procuraArvore(SplayTreeNode **rootPtr, SplayTreeNode *targetNode){
	SplayTreeNode *root = *rootPtr;
	if(root==NULL) {
		return NULL;
	}
	else {
		if(strcmp(targetNode->ingrediente.nome, root->ingrediente.nome) == 0) {
			*rootPtr = targetNode;
		} else if(strcmp(targetNode->ingrediente.nome, root->ingrediente.nome) >= 0) {
			procuraArvore(&root->r, targetNode);
			leftRotate(rootPtr);
		} else if(strcmp(targetNode->ingrediente.nome, root->ingrediente.nome)< 0) {
			procuraArvore(&root->l, targetNode);
			rightRotate(rootPtr);
		}
	}

	return targetNode;
}

void escreveArvore(SplayTreeNode **root) {
	SplayTreeNode *aux = *root;

	if (aux != NULL) {
		if (aux->l) {
			escreveArvore(&aux->l);
		}

		printf("n: %s\n", aux->ingrediente.nome);

		if (aux->r) {
			escreveArvore(&aux->r);
		}
	}
}

void destroiArvore(SplayTreeNode **root) {
	SplayTreeNode *aux = *root;

	if (aux != NULL) {
		destroiArvore(&aux->l);
		destroiArvore(&aux->r);
		free(aux);
	}
}

/*
int main() {
	SplayTreeNode *root = NULL;
	int t;
	char op;

	for (int i = 0; i < 20; i++) {
		scanf(" %c", &op);
		switch (op) {
			case 'a':
				scanf(" %d", &t);
				SplayTreeNode *novo = createNode(t);
				insereArvore(&root, novo);
				writeSplayTree(&root);
				break;
			case 'r':
				scanf(" %d", &t);
				SplayTreeNode *del = createNode(t);
				excluiArvore(&root, del);
				writeSplayTree(&root);
				break;
			case 'f':
				scanf(" %d", &t);
				SplayTreeNode *found = createNode(t);
				procuraArvore(&root, found);
				escreveArvore(&root);
				break;
		}
		printf("%s------------------------------------------------\n", root->ingrediente.nome);
	}
	return 0;
}*/
