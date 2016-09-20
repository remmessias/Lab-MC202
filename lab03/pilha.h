#ifndef LAB03_PILHA_H
#define LAB03_PILHA_H

// Struct que contém as informações do nó
typedef struct {
	int brinquedo, antecessor, qtdAzul;
	char cor;
} Informacoes;

// Struct que representa cada nó da pilha
typedef struct NoPilha {
	Informacoes info;
	struct NoPilha *prox;
} NoPilha;

/*
 * Função que cria uma pilha
 */
void criar(NoPilha **pilha);

/*
 * Função que empilha um nó
 */
void empilha(NoPilha **pilha, Informacoes info);

/*
 * Função que retorna o nó do topo da pilha
 */
int getTopo(NoPilha **pilha);

/*
 * Função que verifica se uma pilha esta vazia
 */
int estaVazia(NoPilha **pilha);

/*
 * Função que troca dois nós de uma lista
 */
NoPilha *trocaNo(NoPilha *no1, NoPilha *no2);

/*
 * Função que ordena uma lista recursivamente
 */
NoPilha *ordena(NoPilha *pilha);

/*
 * Função que desempilha um nó
 */
Informacoes desempilha(NoPilha **pilha);

/*
 * Função que destroi a pilha
 */
void destroi(NoPilha **pilha);

#endif //LAB03_PILHA_H
