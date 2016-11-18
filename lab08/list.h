#ifndef LAB06_LISTACLIENTES_H
#define LAB06_LISTACLIENTES_H

#include "hashTable.h"

typedef struct {
	String palavra;
	int qtd;
} Conteudo;

typedef struct NoLista {
	Conteudo conteudo;
	struct NoLista *prox;
} NoLista;

void criaLista(NoLista **no);

int listaVazia(NoLista **no);

void insereLista(NoLista **no, String palavra);

int procuraLista(NoLista **no, char *informacoes);

int getQuantidade(NoLista **no, char *informacoes);

void incrementaQuantidade(NoLista **no, char *informacoes);

void destroiLista(NoLista **no);

#endif //LAB06_LISTACLIENTES_H