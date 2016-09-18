/*
 * Nome: Rebecca Moreira Messias RA:186416 Turma: F
 */

#include <stdio.h>
#include <stdlib.h>

#define SIMBVERMELHO 'v'
#define SIMBAZUL 'a'
#define AZUL "azul"
#define VERMELHO "vermelho"
#define SAIDA "sequencia invalida ou nao pode colorir\n"

//////////////////////////////////////////////////////////////
//                                                          //
//	   Definição e implementação de operações numa pilha    //
//                                                          //
//////////////////////////////////////////////////////////////

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
void criar(NoPilha **p) {
	*p = NULL;
}

/*
 * Função que empilha um nó
 */
void empilha(NoPilha **pilha, Informacoes info) {
	NoPilha *q = malloc(sizeof(NoPilha));
	q->info = info;
	q->prox = *pilha;
	*pilha = q;
}

/*
 * Função que desempilha um nó
 */
Informacoes desempilha(NoPilha **pilha) {
	NoPilha *q = *pilha;

	if (q != NULL) {
		Informacoes info = q->info;
		*pilha = q->prox;
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
 * Função que troca dois nós de uma lista
 */
NoPilha *troca(NoPilha *no1, NoPilha *no2) {
	no1->prox = no2->prox;
	no2->prox = no1;
	return no2;
}

/*
 * Função que ordena uma lista recursivamente
 */
NoPilha *ordena(NoPilha *pilha) {
	if (pilha == NULL) return NULL;

	if (pilha->prox != NULL && pilha->info.brinquedo < pilha->prox->info.brinquedo)
		pilha = troca(pilha, pilha->prox);

	pilha->prox = ordena(pilha->prox);

	if (pilha->prox != NULL && pilha->info.brinquedo < pilha->prox->info.brinquedo) {
		pilha = troca(pilha, pilha->prox);
		pilha->prox = ordena(pilha->prox);
	}

	return pilha;
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
 * Função que verifica se brinquedos com o mesmo número possuem mesma cor
 */
int verificarCor(NoPilha **lista, char cor, int elemento) {
	for (NoPilha *aux = *lista; aux != NULL; aux = aux->prox) {
		if (aux->info.brinquedo == elemento || aux->info.cor != cor)
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
	informacao.qtdAzul = 0;
	informacao.brinquedo = elemento;
	informacao.antecessor = getTopo(pilhaBrinquedo);
	empilha(pilhaBrinquedo, informacao);
}

/*
 * Função que incrementa a quantidade de brinquedos azuis
 * elemento no topo da lista
 */
void incrementaQtdAzulTopo(NoPilha **pilha) {
	if ((*pilha) != NULL) {
		(*pilha)->info.qtdAzul++;
	}
}

/*
 * Função que verifica se a lista já possui um determinado brinquedo
 * com o mesmo número
 */
int temBrinquedo(NoPilha **pilha, int elemento) {
	for (NoPilha *aux = *pilha; aux != NULL; aux = aux->prox) {
		if (aux->info.brinquedo == elemento)
			return 1;
	}

	return 0;
}

/*
 * Função que imprime a sequancia de cores de cada
 * brinquedo para o usuario
 */
void escreveResultado(NoPilha **pilha) {
	printf("sequencia valida pode ser colorida\n");

	for (NoPilha *aux = *pilha; aux != NULL; aux = aux->prox) {
		if (aux->info.cor == SIMBVERMELHO)
			printf("%d: %s\n", -aux->info.brinquedo, VERMELHO);
		else
			printf("%d: %s\n", -aux->info.brinquedo, AZUL);

	}
}

/*
 * Função que lê e coloca a cor em um determinado brinquedo
 */
int leEColacaCor(NoPilha **pilhaBrinquedo, NoPilha **cores, int tamanho) {
	int elemento, i;
	Informacoes desempilhado;

	for (i = 0; i < tamanho; i++) {
		scanf(" %d", &elemento);
		if (elemento < 0) {
			empilhaInformacao(elemento, pilhaBrinquedo);
		}
		else {
			desempilhado = desempilha(pilhaBrinquedo);
			if (absoluto(desempilhado.brinquedo) == elemento) {
				if ((desempilhado.qtdAzul + elemento) % 2 == 0) {
					if (verificarCor(cores, SIMBAZUL, elemento)) {
						incrementaQtdAzulTopo(pilhaBrinquedo);
						desempilhado.cor = SIMBAZUL;
						if (!temBrinquedo(cores, desempilhado.brinquedo))
							empilha(cores, desempilhado);
					}
					else {
						printf(SAIDA);
						return 0;
					}
				}
				else {
					if (verificarCor(cores, SIMBVERMELHO, elemento)) {
						desempilhado.cor = SIMBVERMELHO;
						if (!temBrinquedo(cores, desempilhado.brinquedo))
							empilha(cores, desempilhado);
					}
					else {
						printf(SAIDA);
						return 0;
					}
				}
			}
			else {
				printf(SAIDA);
				return 0;
			}
		}
	}

	if (!estaVazia(pilhaBrinquedo)) {
		printf(SAIDA);
	}

	return 1;
}

int main() {
	NoPilha *pilhaBrinquedo;
	NoPilha *cores;
	int tamanho;

	criar(&pilhaBrinquedo);
	criar(&cores);

	scanf("%d", &tamanho);
	if (tamanho%2 == 0) {
		if (leEColacaCor(&pilhaBrinquedo, &cores, tamanho)) {
			cores = ordena(cores);
			escreveResultado(&cores);
		}
	}
	else {
		printf(SAIDA);
	}
	destroi(&pilhaBrinquedo);
	destroi(&cores);

	return 0;
}