#include "auxiliar.h"
#include <stdio.h>

int verificarCor(NoPilha **lista, char cor, int elemento) {
	for (NoPilha *aux = *lista; aux != NULL; aux = aux->prox) {
		if (aux->info.brinquedo == -elemento && aux->info.cor != cor)
			return 0;
	}
	return 1;
}

int absoluto(int numero) {
	if (numero < 0)
		return -numero;
	return numero;
}

void empilhaInformacao(int elemento, NoPilha **pilhaBrinquedo) {
	Informacoes informacao;
	informacao.qtdAzul = 0;
	informacao.brinquedo = elemento;
	informacao.antecessor = getTopo(pilhaBrinquedo);
	empilha(pilhaBrinquedo, informacao);
}

void incrementaQtdAzulTopo(NoPilha **pilha) {
	if ((*pilha) != NULL) {
		(*pilha)->info.qtdAzul++;
	}
}

int temBrinquedo(NoPilha **pilha, int elemento) {
	for (NoPilha *aux = *pilha; aux != NULL; aux = aux->prox) {
		if (aux->info.brinquedo == elemento)
			return 1;
	}
	return 0;
}

void escreveResultado(NoPilha **pilha) {
	printf("sequencia valida pode ser colorida\n");

	for (NoPilha *aux = *pilha; aux != NULL; aux = aux->prox) {
		if (aux->info.cor == SIMBVERMELHO)
			printf("%d: %s\n", -aux->info.brinquedo, VERMELHO);
		else
			printf("%d: %s\n", -aux->info.brinquedo, AZUL);

	}
}

int leEColacaCor(NoPilha **pilhaBrinquedo, NoPilha **cores, int tamanho) {
	int elemento, i;
	Informacoes desempilhado;

	for (i = 0; i < tamanho; i++) {
		if ((i != 0 && i < tamanho - 1) && (*pilhaBrinquedo) == NULL) {
			printf(SAIDA);
			return 0;
		}
		else {
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
	}

	if (!estaVazia(pilhaBrinquedo)) {
		printf(SAIDA);
	}

	return 1;
}