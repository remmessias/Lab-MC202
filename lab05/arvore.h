#ifndef LAB05_ARVORE_H
#define LAB05_ARVORE_H

#include "auxiliar.h"

//Definição da estrutura de uma árvore
typedef struct NoArvore {
	struct NoArvore *esquerda;
	struct NoArvore *direita;
	String arquivo;
} NoArvore;

typedef struct Arvore {
	NoArvore *raiz;
} Arvore;

/*
 * Função que cria uma árvore
 */
Arvore *criarArvore();

/*
 * Função que cria um nó
 */
NoArvore *criarNo();

/*
 * Função que indica a altura do nó na árvore
 */
int alturaNo(NoArvore *no);

/*
 * Função que verifica se a árvore esta vazia
 */
int arvoreEstaVazia(NoArvore *a);

/*
 * Função que calcula o fator de balanceamento de um nó
 */
int fatorBalanceamento(NoArvore *no);

// INÍCIO DO CONJUNTO DE FUNÇÕES PARA BALANCEAR UMA ÁRVORE
NoArvore *girarEsquerdaEsquerda(NoArvore *no);

NoArvore *girarEsquerdaDireita(NoArvore *no);

NoArvore *girarDireitaEsquerda(NoArvore *no);

NoArvore *girarDireitaDireita(NoArvore *no);

NoArvore *balancearNo(NoArvore *no);

void balancear(Arvore *arvore);
// FIM DO CONJUNTO DE FUNÇÕES PARA BALANCEAR UMA ÁRVORE

/*
 * Função que insere um nó numa árvore
 */
void inserirNo(Arvore *arvore, String arquivo);

 // INÍCIO DO CONJUNTO DE FUNÇÕES PARA REMOVER UM NÓ DE UMA ÁRVORE
void remover(Arvore *arvore, String arquivo, int *achou);

void removerNo(NoArvore **no, String arquivo, int *achou);

void removerCaso1(NoArvore **no);

void removerCaso2(NoArvore *no);
// FIM DO CONJUNTO DE FUNÇÕES PARA REMOVER UM NÓ DE UMA ÁRVORE

/*
 * Função que procura um nó em uma árvore
 */
NoArvore *procurarNo(Arvore *arvore, String arquivo);

/*
 * Função que lista os nós de uma árvore que começa com uma substring
 */
void listarPorPrefixo(NoArvore *no, String arquivo, int *achou);

/*
 * Função que lista todos os nós de uma árvore
 */
void listarTudo(NoArvore *no);

/*
 * Função que destróis uma árvore
 */
void destroiArvore(Arvore *arvore);

/*
 * Função que destroi o nó de uma árvore
 */
void destroiNo(NoArvore* no);

#endif
