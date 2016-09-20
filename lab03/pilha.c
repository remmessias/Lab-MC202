#include "pilha.h"
#include <stdlib.h>

void criar(NoPilha **pilha) {
	*pilha = NULL;
}

void empilha(NoPilha **pilha, Informacoes info) {
	NoPilha *aux = malloc(sizeof(NoPilha));
	aux->info = info;
	aux->prox = *pilha;
	*pilha = aux;
}

int getTopo(NoPilha **pilha) {
	if (*pilha == NULL)
		return 0;
	return (*pilha)->info.brinquedo;
}

int estaVazia(NoPilha **pilha) {
	if ((*pilha) == NULL)
		return 1;
	return 0;
}

NoPilha *trocaNo(NoPilha *no1, NoPilha *no2) {
	no1->prox = no2->prox;
	no2->prox = no1;
	return no2;
}

NoPilha *ordena(NoPilha *pilha) {
	if (pilha == NULL) return NULL;

	if (pilha->prox != NULL && pilha->info.brinquedo < pilha->prox->info.brinquedo)
		pilha = trocaNo(pilha, pilha->prox);

	pilha->prox = ordena(pilha->prox);

	if (pilha->prox != NULL && pilha->info.brinquedo < pilha->prox->info.brinquedo) {
		pilha = trocaNo(pilha, pilha->prox);
		pilha->prox = ordena(pilha->prox);
	}

	return pilha;
}

Informacoes desempilha(NoPilha **pilha) {
	NoPilha *aux = *pilha;

	if (aux != NULL) {
		Informacoes info = aux->info;
		*pilha = aux->prox;
		free(aux);
		return info;
	}
	Informacoes retorno;
	retorno.cor = 'c';
	retorno.brinquedo = 0;
	retorno.antecessor = 0;

	return retorno;
}

void destroi(NoPilha **pilha) {
	NoPilha *prox;

	for (NoPilha *aux = *pilha; aux != NULL; aux = prox) {
		prox = aux->prox;
		free(aux);
	}
}
