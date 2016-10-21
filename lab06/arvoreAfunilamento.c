#include "arvoreAfunilamento.h"
#include <string.h>
#include<stdio.h>
#include<stdlib.h>

SplayTreeNode *root;

void rotacaoDireita(SplayTreeNode **no) {
	SplayTreeNode *aux = *no;

	SplayTreeNode *T = aux->l;
	SplayTreeNode *B = T->r;
	SplayTreeNode *D = aux->p;
	if (D) {
		if (D->r == aux)
			D->r = T;
		else
			D->l = T;
	}
	
	if (B)
		B->p = aux;
	
	T->p = D;
	T->r = aux;

	aux->p = T;
	aux->l = B;
}

void rotacaoEsquerda(SplayTreeNode **no) {
	SplayTreeNode *aux = *no;

	SplayTreeNode *T = aux->r;
	SplayTreeNode *B = T->l;
	SplayTreeNode *D = aux->p;
	
	if (D) {
		if (D->r == aux)
			D->r = T;
		else
			D->l = T;
	}
	
	if (B)
		B->p = aux;
	
	T->p = D;
	T->l = aux;

	aux->p = T;
	aux->r = B;
}

void afunila(SplayTreeNode **no) {
	SplayTreeNode *aux = *no;

	while (true) {
		SplayTreeNode *p = aux->p;
		
		if (!p)
			break;
		
		SplayTreeNode *pp = p->p;
		
		if (!pp) { //Zig
			if (p->l == aux)
				rotacaoDireita(&p);
			else
				rotacaoEsquerda(&p);
			
			break;
		}
		
		if (pp->l == p) {
			if (p->l == aux) { //ZigZig
				rotacaoDireita(&pp);
				rotacaoDireita(&p);
			}
			else { //ZigZag
				rotacaoEsquerda(&p);
				rotacaoDireita(&pp);
			}
		}
		else {
			if (p->l == aux) { //ZigZag
				rotacaoDireita(&p);
				rotacaoEsquerda(&pp);
			}
			else { //ZigZig
				rotacaoEsquerda(&pp);
				rotacaoEsquerda(&p);
			}
		}
	}
	
	root = aux;
}

void insereSplayTree(SplayTreeNode **no, Ingrediente ingrediente) {
	SplayTreeNode *aux = *no;

	if (!root) {
		aux = malloc(sizeof(SplayTreeNode));
		aux->l = NULL;
		aux->r = NULL;
		aux->p = NULL;
		aux->ingrediente = ingrediente;
		return;
	}
	
	while (true) {
		if (strcmp(aux->ingrediente.nome, ingrediente.nome) == 0)
			break; // not multiset
		
		if (strcmp(ingrediente.nome, aux->ingrediente.nome) < 0) {
			if (aux->l)
				aux = aux->l;
			else {
				aux->l = malloc(sizeof(SplayTreeNode));
				aux->l->p = aux;
				aux->l->r = NULL;
				aux->l->l = NULL;
				aux->l->ingrediente = ingrediente;
				aux = aux->l;
				break;
			}
		}
		else {
			if (aux->r)
				aux = aux->r;
			else {
				aux->r = malloc(sizeof(SplayTreeNode));
				aux->r->p = aux;
				aux->r->r = NULL;
				aux->r->l = NULL;
				aux->r->ingrediente = ingrediente;
				aux = aux->r;
				break;
			}
		}
	}

	afunila(&aux);
}

void imprimeInordem(SplayTreeNode **no) {
	SplayTreeNode *aux = *no;

	if (!aux)
		return;

	imprimeInordem(&aux->l);
	
	printf("v: %s ", aux->ingrediente.nome);
	
	if (aux->l)
		printf("l: %s ", aux->l->ingrediente.nome);
	
	if (aux->r)
		printf("r: %s ", aux->r->ingrediente.nome);
	
	puts("");

	imprimeInordem(&aux->r);
}

SplayTreeNode *procura(SplayTreeNode **no, Ingrediente ingrediente) {
	SplayTreeNode *aux = *no;

	if (!aux) {
		return NULL;
	}

	while (aux) {
		if (strcmp(aux->ingrediente.nome, ingrediente.nome) == 0)
			break;
		if (strcmp(ingrediente.nome, aux->ingrediente.nome) < 0) {
			if (aux->l)
				aux = aux->l;
			else
				break;
		}
		else {
			if (aux->r)
				aux = aux->r;
			else
				break;
		}
	}

	afunila(&aux);
	
	if (strcmp(aux->ingrediente.nome, ingrediente.nome) == 0)
		return aux;
	else
		return NULL;
}

bool apaga(SplayTreeNode **no, Ingrediente ingrediente) {
	SplayTreeNode *aux1 = procura(no, ingrediente);

	if (!aux1)
		return false;

	afunila(&aux1);

	SplayTreeNode *aux2 = aux1->l;

	if (!aux2) {
		root = aux1->r;
		root->p = NULL;
		free(aux1);
		return true;
	}

	while (aux2->r)
		aux2 = aux2->r;

	if (aux1->r) {
		aux2->r = aux1->r;
		aux1->r->p = aux2;
	}

	root = aux1->l;
	root->p = NULL;

	free(aux1);

	return true;
}

void destroiSplayTree (SplayTreeNode **no) {
	SplayTreeNode *aux = *no;

	if (aux->l != NULL)
		destroiSplayTree(&aux->l);

	if (aux->r != NULL)
		destroiSplayTree(&aux->r);

	free(aux);
}

//int main() {
//	for (int i = 0; i < 20; i++) {
//		int t;
//
//		scanf("%d", &t);
//
//		if (t != 0 && t != -1)
//			insere(t);
//		else if (t == 0) {
//			scanf("%d", &t);
//
//			if (!procura(t))
//				printf("Couldn't procura %d!\n", t);
//			else
//				printf("Found %d!\n", t);
//		}
//		else {
//
//			scanf("%d", &t);
//			if (apaga(t))
//				printf("Deleted %d!\n", t);
//			else
//				printf("Couldn't procura %d!\n", t);
//		}
//		if (root)
//			printf("root: %d\n", root->v);
//
//		imprimeInordem(root);
//	}
//}
