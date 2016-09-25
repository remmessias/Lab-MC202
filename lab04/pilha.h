#ifndef LAB04_PILHA_H
#define LAB04_PILHA_H

typedef struct {
	int linha, coluna;
	char celula;
} Informacoes;

typedef struct Pilha {
	Informacoes info;
	struct Pilha *prox;
} Pilha;

void criar(Pilha **pilha);

void empilha(Pilha **pilha, Informacoes info);

Pilha *getTopo(Pilha **pilha);

int estaVazia(Pilha **pilha);

Informacoes desempilha(Pilha **pilha);

void destroi(Pilha **pilha);

#endif
