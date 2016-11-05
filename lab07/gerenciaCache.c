#include <stdio.h>
#include "gerenciaCache.h"

void leEspecificacoes (int *c, int *n, int *a) {
	scanf(" %d %d %d", c, n, a);
}

void escreveAcessos(int qtdAcessos) {
	printf("%d\n", qtdAcessos);
}

int calculaAcessos(NoFila **fila, FilaPrioridade *filaPrioridade) {
	int acessos = 0;
	while (*fila != NULL) {
		int elemen = removeFila(fila);

		if (elemen != -1) {
			if (!temCache(elemen, filaPrioridade)) {
				if (filaPrioridade->estaCheio) {
					//procurar o ultimo a ser chamado ou o que não vai mais ser chamado e remove-lo
					removeUltimoASerAcessado(fila, filaPrioridade);
					insere(elemen, filaPrioridade);
					acessos++;
				}
				else {
					insere(elemen, filaPrioridade);
					acessos++;
				}
			}
		}
	}

	return acessos;
}

void leAcessos(NoFila **fila, int qtdSolicitacao) {
	int i, elemento;
	for (i = 0; i < qtdSolicitacao; i++) {
		scanf(" %d", &elemento);
		insereFila(fila, elemento);
	}
}