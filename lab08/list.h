#ifndef LAB06_LISTACLIENTES_H
#define LAB06_LISTACLIENTES_H

#include "hashTable.h"

// Definiçã da estrutura da lista

typedef struct {
	String palavra;
	int qtd;
} Conteudo;

typedef struct NoLista {
	Conteudo conteudo;
	struct NoLista *prox;
} NoLista;

/*
 * Função que cria uma lista
 */
void criaLista(NoLista **no);

/*
 * Função que verifica se uma lista esta vazia
 */
int listaVazia(NoLista **no);

/*
 * Função que insere numa lista
 */
void insereLista(NoLista **no, String palavra);

/*
 * Função que procura uma informação na lista
 */
int procuraLista(NoLista **no, char *informacoes);

/*
 * Função que calcula a quantidade de elementos totais ela deveria ter
 */
int getQuantidade(NoLista **no, char *informacoes);

/*
 * Função que incrementa a quantidade de um elemento
 */
void incrementaQuantidade(NoLista **no, char *informacoes);

/*
 * Função que destroi uma lista
 */
void destroiLista(NoLista **no);

#endif //LAB06_LISTACLIENTES_H