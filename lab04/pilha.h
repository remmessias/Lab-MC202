#ifndef LAB4_PILHA_H
#define LAB4_PILHA_H

//estrutura da pilha
typedef struct {
	int linha, coluna;
	char celula;
} Informacoes;

typedef struct Pilha {
	Informacoes info;
	struct Pilha *prox;
} Pilha;

/*
 * Função que cria uma pilha
 */
void criar(Pilha **pilha);

/*
 * Função que coloca um valor na pilha
 */
void empilha(Pilha **pilha, Informacoes info);

/*
 * Função que retorna o topo da pilha
 */
Informacoes getTopo(Pilha **pilha);

/*
 * Função que retira um valor da pilha
 */
Informacoes desempilha(Pilha **pilha);

/*
 * Função que destroi a pilha
 */
void destroi(Pilha **pilha);

#endif //LAB4_PILHA_H
