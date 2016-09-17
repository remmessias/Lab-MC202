/*
 * Nome: Rebecca Moreira Messias RA:186416 Turma: F
 */

#include <stdio.h>
#include <stdlib.h>

#define VERMELHO 'v'
#define AZUL 'a'
#define SAIDA "sequencia invalida ou nao pode colorir\n"

//////////////////////////////////////////////////////////////
//                                                          //
//	   Definição e implementação de operações numa pilha    //
//                                                          //
//////////////////////////////////////////////////////////////

// Struct que contém as informações do nó
typedef struct {
	int brinquedo, antecessor;
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
void criar(NoPilha **p) {
	*p = NULL;
}

/*
 * Função que empilha um nó
 */
void empilha(NoPilha **p, Informacoes info) {
	NoPilha *q = malloc(sizeof(NoPilha));
	q->info = info;
	q->prox = *p;
	*p = q;
}

/*
 * Função que desempilha um nó
 */
Informacoes desempilha(NoPilha **p) {
	NoPilha *q = *p;

	if (q != NULL) {
		Informacoes info = q->info;
		*p = q->prox;
		free(q);
		return info;
	}
	Informacoes retorno;
	retorno.cor = 'c';
	retorno.brinquedo = 0;
	retorno.antecessor = 0;

	return retorno;
}

/*
 * Função que retorna o nó do topo da pilha
 */
int getTopo(NoPilha **p) {
	if (*p == NULL)
		return 0;
	return (*p)->info.brinquedo;
}

/*
 * Função que verifica se uma pilha esta vazia
 */
int estaVazia(NoPilha **pilha) {
	if ((*pilha) == NULL)
		return 1;
	return 0;
}

/*
 * Função que destroi a pilha
 */
void destroi(NoPilha **p) {
	NoPilha *prox;

	for (NoPilha *q = *p; q != NULL; q = prox) {
		prox = q->prox;
		free(q);
	}
}

// FIM DA DEFINIÇÃO E OPERAÇÕES COM A PILHA

/*
 * Função que verifica quantos brinquedos tem dentro de uma boneca
 */
int quantosAzuis(NoPilha **p, int dado) {
	int qtdAzuis = 0;
	NoPilha *pilha = *p;

	if (pilha == NULL)
		return 0;

	for (; pilha != NULL; pilha = pilha->prox) {
		if (pilha->info.antecessor == -dado && pilha->info.cor == AZUL) {
			qtdAzuis++;
		}
	}

	return qtdAzuis;
}

/*
 * Função que verifica se brinquedos com o mesmo número possuem mesma cor
 */
int verificarCor(NoPilha **lista, char cor, int elemento) {
	for (NoPilha *aux = *lista; aux != NULL; aux = aux->prox) {
		if (aux->info.brinquedo == elemento && aux->info.cor != cor)
			return 0;
	}
	return 1;
}

/*
 * Função que tira módulo de um número
 */
int absoluto(int numero) {
	if (numero < 0)
		return -numero;
	return numero;
}

/*
 * Função que prepara uma variavel informação para ser empilhada
 */
void empilhaInformacao(int elemento, NoPilha **pilhaBrinquedo) {
	Informacoes informacao;
	informacao.brinquedo = elemento;
	informacao.antecessor = getTopo(pilhaBrinquedo);
	empilha(pilhaBrinquedo, informacao);
}

/*
 * Função que seta cor
 */
void leEColacaCor(NoPilha **pilhaBrinquedo, NoPilha **cores, int tamanho) {
	int elemento, qtdAzul, i;
	Informacoes desempilhado;

	for (i = 0; i < tamanho; i++) {
		scanf(" %d", &elemento);
		if (elemento < 0) {
			empilhaInformacao(elemento, pilhaBrinquedo);
		}
		else {
			desempilhado = desempilha(pilhaBrinquedo);
			if (absoluto(desempilhado.brinquedo) == elemento) {
				qtdAzul = quantosAzuis(cores, elemento);

				if ((qtdAzul + elemento) % 2 == 0) {
					if (verificarCor(cores, AZUL, elemento)) {
						desempilhado.cor = AZUL;
						empilha(cores, desempilhado);
					}
					else {
						printf(SAIDA);
						break;
					}
				}
				else {
					if (verificarCor(cores, VERMELHO, elemento)) {
						desempilhado.cor = VERMELHO;
						empilha(cores, desempilhado);
					}
					else {
						printf(SAIDA);
						break;
					}
				}
			}
			else {
				printf(SAIDA);
				break;
			}
		}
	}

	if (!estaVazia(pilhaBrinquedo)) {
		printf(SAIDA);
	}
}

int main() {
	NoPilha *pilhaBrinquedo;
	NoPilha *cores;
	int tamanho;

	criar(&pilhaBrinquedo);
	criar(&cores);

	scanf("%d", &tamanho);

	leEColacaCor(&pilhaBrinquedo, &cores, tamanho);

	destroi(&pilhaBrinquedo);
	destroi(&cores);

	return 0;
}