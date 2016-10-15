#include "arvore.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Arvore *criarArvore() {
	Arvore *arvore = NULL;

	if ((arvore = malloc(sizeof(Arvore))) == NULL) {
		return NULL;
	}

	arvore->raiz = NULL;
	return arvore;
}

NoArvore *criarNo() {
	NoArvore *no = NULL;

	if ((no = malloc(sizeof(NoArvore))) == NULL) {
		return NULL;
	}

	no->esquerda = NULL;
	no->direita = NULL;
	strcpy(no->arquivo, "");

	return no;
}

void inserirNo(Arvore *arvore, String arquivo) {
	NoArvore *no = NULL;
	NoArvore *proximo = NULL;
	NoArvore *ultimo = NULL;

	if (arvore->raiz == NULL) {
		no = criarNo();
		strcpy(no->arquivo, arquivo);
		arvore->raiz = no;
	} else {
		proximo = arvore->raiz;

		while (proximo != NULL) {
			ultimo = proximo;

			if (strcmp(arquivo, proximo->arquivo) < 0) {
				proximo = proximo->esquerda;

			} else if (strcmp(arquivo, proximo->arquivo) >= 0) {
				proximo = proximo->direita;
			}
		}

		no = criarNo();
		strcpy(no->arquivo, arquivo);
		if (ultimo != NULL) {
			if (strcmp(arquivo, ultimo->arquivo) < 0)
				ultimo->esquerda = no;
			if (strcmp(arquivo, ultimo->arquivo) >= 0)
				ultimo->direita = no;
		}
	}

	if (arvore->raiz)
		balancear(arvore);
}

void remover(Arvore *arvore, String arquivo, int *achou) {
	if (arvore->raiz) {
		removerNo(&arvore->raiz, arquivo, achou);
	}

	if (arvore->raiz)
		balancear(arvore);
}

void removerNo(NoArvore **no, String arquivo, int *achou) {
	if ((*no) != NULL) {
		if (comecaCom((*no)->arquivo, arquivo)) {
			*achou = 1;
			if (!(*no)->direita || !(*no)->esquerda)
				removerCaso1(no);
			else
				removerCaso2(*no);
		}
		if ((*no) != NULL) {
			if (comecaCom((*no)->arquivo, arquivo))
				removerNo(no, arquivo, achou);
			else {
				if ((*no)->esquerda != NULL)
					removerNo(&(*no)->esquerda, arquivo, achou);
				if ((*no)->direita != NULL)
					removerNo(&(*no)->direita, arquivo, achou);
			}
		}
	}
}

NoArvore *procurarNo(Arvore *arvore, String arquivo) {
	NoArvore *atual = arvore->raiz;

	while (atual && !comecaCom(atual->arquivo, arquivo)) {
		if (strcmp(arquivo, atual->arquivo) > 0)
			atual = atual->direita;
		else
			atual = atual->esquerda;
	}

	return atual;
}

void balancear(Arvore *arvore) {

	NoArvore *novaRaiz = NULL;

	novaRaiz = balancearNo(arvore->raiz);

	if (novaRaiz != arvore->raiz) {
		arvore->raiz = novaRaiz;
	}
}

NoArvore *balancearNo(NoArvore *no) {
	NoArvore *novaRaiz = NULL;

	if (no->esquerda)
		no->esquerda = balancearNo(no->esquerda);
	if (no->direita)
		no->direita = balancearNo(no->direita);

	int fb = fatorBalanceamento(no);

	if (fb >= 2) {

		if (fatorBalanceamento(no->esquerda) <= -1)
			novaRaiz = girarEsquerdaDireita(no);
		else
			novaRaiz = girarEsquerdaEsquerda(no);

	} else if (fb <= -2) {
		if (fatorBalanceamento(no->direita) >= 1)
			novaRaiz = girarDireitaEsquerda(no);
		else
			novaRaiz = girarDireitaDireita(no);

	} else {
		novaRaiz = no;
	}

	return novaRaiz;
}

NoArvore *girarEsquerdaEsquerda(NoArvore *no) {
	NoArvore *a = no;
	NoArvore *b = a->esquerda;

	a->esquerda = b->direita;
	b->direita = a;

	return (b);
}

NoArvore *girarEsquerdaDireita(NoArvore *no) {
	NoArvore *a = no;
	NoArvore *b = a->esquerda;
	NoArvore *c = b->direita;

	a->esquerda = c->direita;
	b->direita = c->esquerda;
	c->esquerda = b;
	c->direita = a;

	return (c);
}

NoArvore *girarDireitaEsquerda(NoArvore *no) {
	NoArvore *a = no;
	NoArvore *b = a->direita;
	NoArvore *c = b->esquerda;

	a->direita = c->esquerda;
	b->esquerda = c->direita;
	c->direita = b;
	c->esquerda = a;

	return (c);
}

NoArvore *girarDireitaDireita(NoArvore *no) {
	NoArvore *a = no;
	NoArvore *b = a->direita;

	a->direita = b->esquerda;
	b->esquerda = a;

	return (b);
}

int alturaNo(NoArvore *no) {
	int altura_esquerda = 0;
	int altura_direita = 0;

	if (no->esquerda)
		altura_esquerda = alturaNo(no->esquerda);
	if (no->direita)
		altura_direita = alturaNo(no->direita);

	return altura_direita > altura_esquerda ? ++altura_direita : ++altura_esquerda;
}

int fatorBalanceamento(NoArvore *no) {
	int fb = 0;

	if (no->esquerda)
		fb += alturaNo(no->esquerda);
	if (no->direita)
		fb -= alturaNo(no->direita);

	return fb;
}

void removerCaso2(NoArvore *remove) {
	NoArvore **sucessor;

	sucessor = &(remove->direita);
	while((*sucessor)->esquerda)
		sucessor = &((*sucessor)->esquerda);

	strcpy(remove->arquivo, (*sucessor)->arquivo);
	removerCaso1(sucessor);
}

void removerCaso1(NoArvore **no) {
	NoArvore *remove;
	remove = *no;
	if (remove->esquerda == NULL)
		*no = remove->direita;
	else
		*no = remove->esquerda;
	free(remove);
}

void listarPorPrefixo(NoArvore *no, String arquivo, int *achou) {

	if (no) {
		if (no->esquerda)
			listarPorPrefixo(no->esquerda, arquivo, achou);

		if (comecaCom(no->arquivo, arquivo)) {
			*achou = 1;
			printf("%s\n", no->arquivo);
		}

		if (no->direita)
			listarPorPrefixo(no->direita, arquivo, achou);
	}
}

void listarTudo(NoArvore *no) {
	if (no->esquerda)
		listarTudo(no->esquerda);

	printf("%s\n", no->arquivo);

	if (no->direita)
		listarTudo(no->direita);
}

void buscaAux(NoArvore *no, int profundidade) {
	int i = 0;

	if (no->esquerda)
		buscaAux(no->esquerda, profundidade + 2);

	for (i = 0; i < profundidade; i++)
		putchar(' ');
	printf("%s: %d\n", no->arquivo, fatorBalanceamento(no));

	if (no->direita)
		buscaAux(no->direita, profundidade + 2);
}

int arvoreEstaVazia(NoArvore *a) {
	return a == NULL;
}

void destroiNo (NoArvore* no) {
	if (!arvoreEstaVazia(no)){
		destroiNo(no->esquerda);
		destroiNo(no->direita);
		free(no);
	}
}

void destroiArvore(Arvore *arvore) {
	destroiNo(arvore->raiz);
	free(arvore);
}