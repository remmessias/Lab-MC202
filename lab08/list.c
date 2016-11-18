#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void criaLista(NoLista **no) {
	*no = NULL;
}

int listaVazia(NoLista **no) {
	if ((*no) != NULL )
		return 0;
	return 1;
}

void insereLista(NoLista **no, String informacoes) {
	if (!procuraLista(no, informacoes)) {
		NoLista *novoElemento;
		NoLista *auxiliar;
		novoElemento = malloc(sizeof(NoLista));
		strcpy(novoElemento->conteudo.palavra, informacoes);
		novoElemento->conteudo.qtd = 1;
		novoElemento->prox = NULL;

		if (listaVazia(no)) {
			*no = novoElemento;
		}
		else {
			auxiliar = *no;
			while (auxiliar->prox != NULL) {
				auxiliar = auxiliar->prox;
			}
			auxiliar->prox = novoElemento;
		}
	}
	else {
		incrementaQuantidade(no, informacoes);
	}
}

void incrementaQuantidade(NoLista **no, char *informacoes) {
	NoLista *aux;

	for (aux = *no; aux != NULL; aux = aux->prox) {
		if (strcmp(aux->conteudo.palavra, informacoes) == 0)
			aux->conteudo.qtd++;
	}
}

int getQuantidade(NoLista **no, char *informacoes) {
	NoLista *aux;

	for (aux = *no; aux != NULL; aux = aux->prox) {
		if (strcmp(aux->conteudo.palavra, informacoes) == 0)
			return aux->conteudo.qtd;
	}

	return -1;
}

int procuraLista(NoLista **no, char *informacoes) {
	NoLista *aux;

	for (aux = *no; aux != NULL; aux = aux->prox) {
		if (strcmp(aux->conteudo.palavra, informacoes) == 0)
			return 1;
	}

	return 0;
}

void destroiLista(NoLista **no) {
	NoLista *prox;

	for (NoLista *aux = *no; aux != NULL; aux = prox) {
		prox = aux->prox;
		free(aux);
	}
}