#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"

No *criarNo(Informacao info) {
	No *novo;
	novo = malloc(sizeof(No));
	novo->info = info;
	return novo;
}

int codifica(String palavra, int tam) {
	int i, h = palavra[0];
	for (i = 1; palavra[i] != '\0'; i++)
		h = h * 256 + palavra[i];
	return h % tam;
}


void inserirHash(Informacao info, TabelaEspalhamento *tabela) {
	Hash *tabelaEsp = tabela->tabela;
	int index = codifica(info.palavra, tabela->quantidade);
	No *novo = criarNo(info);

	if (!tabelaEsp[index].inicio) {
		tabelaEsp[index].inicio = novo;
		tabelaEsp[index].qtdElemen = 1;
		return;
	}
	novo->proximo = (tabelaEsp[index].inicio);
	tabelaEsp[index].inicio = novo;
	tabelaEsp[index].qtdElemen++;
	return;
}

void destroiTabela(TabelaEspalhamento *tabela) {
	free(tabela->tabela);
}

void destroiListas(TabelaEspalhamento *tabela) {
	int i;

	for (i = 0; i < tabela->quantidade; i++) {
		No *aux1 = tabela->tabela[i].inicio, *aux2;

		while (aux1 != NULL) {
			aux2 = aux1;
			aux1 = aux1->proximo;
			free(aux2);
		}

		free(aux1);
	}
}