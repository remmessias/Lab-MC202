#ifndef LAB4_PILHA_H
#define LAB4_PILHA_H

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

Informacoes getTopo(Pilha **pilha);

Informacoes desempilha(Pilha **pilha);

void destroi(Pilha **pilha);

#endif //LAB4_PILHA_H
