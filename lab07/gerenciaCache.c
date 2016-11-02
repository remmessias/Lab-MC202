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
		Informacoes elemen = removeFila(fila);

		if (elemen.frequencia != -1 && elemen.valor != -1) {
			if (!temCache(elemen, filaPrioridade)) {

				if (filaPrioridade->estaCheio) {
					removeMin(filaPrioridade);
					decrementaFrequencia(fila, elemen.valor);
					elemen.frequencia--;
					insere(elemen, filaPrioridade);
					acessos++;
				}
				else {
					decrementaFrequencia(fila, elemen.valor);
					elemen.frequencia--;
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
		if (temElemento(fila, elemento)) {
			incrementaFrequencia(fila, elemento);
			Informacoes info;
			info.valor = elemento;
			info.frequencia = getFrequencia(fila, elemento);
			insereFila(fila, info);
		}
		else {
			Informacoes info;
			info.valor = elemento;
			info.frequencia = 1;
			insereFila(fila, info);
		}

	}
}