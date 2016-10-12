#ifndef LAB05_ARVORE_H
#define LAB05_ARVORE_H

#include "auxiliar.h"

typedef struct NoArvore {
	struct NoArvore *esquerda;
	struct NoArvore *direita;
	String arquivo;
} NoArvore;

typedef struct Arvore {
	NoArvore *raiz;
} Arvore;

Arvore *criarArvore();

NoArvore *criarNo();

int alturaNo(NoArvore *no);

int arvoreEstaVazia(NoArvore *a);

int fatorBalanceamento(NoArvore *no);

NoArvore *girarEsquerdaEsquerda(NoArvore *no);

NoArvore *girarEsquerdaDireita(NoArvore *no);

NoArvore *girarDireitaEsquerda(NoArvore *no);

NoArvore *girarDireitaDireita(NoArvore *no);

NoArvore *balancearNo(NoArvore *no);

void balancear(Arvore *arvore);

void inserirNo(Arvore *arvore, String arquivo);

void remover(Arvore *arvore, String arquivo, int *achou);

void removerNo(NoArvore **no, String arquivo, int *achou);

void removerCaso1(NoArvore **no);

void removerCaso2(NoArvore *no);

NoArvore *procurarNo(Arvore *arvore, String arquivo);

void listarPorPrefixo(NoArvore *no, String arquivo, int *achou);

void buscaAux(NoArvore *no, int profundidade);

void listarTudo(NoArvore *no);

void destroiArvore(Arvore *arvore);

void destroiNo(NoArvore* no);

#endif
