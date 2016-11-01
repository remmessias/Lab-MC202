#include <stdio.h>
#include "gerenciaCache.h"
#include "fila.h"

int main () {
	int tamCache, qtdElementos, qtdSolicitacao, elemento, i;
	NoFila *fila;

	leEspecificacoes(&tamCache, &qtdElementos, &qtdSolicitacao);

	criaFila(&fila);

	for (i = 0; i < qtdSolicitacao; i++) {
		scanf(" %d", &elemento);
		if (temElemento(&fila, elemento)) {
			incrementaFrequencia(&fila, elemento);
			Informacoes info;
			info.valor = elemento;
			info.frequencia = getFrequencia(&fila, elemento);
			insereFila(&fila, info);
		}
		else {
			Informacoes info;
			info.valor = elemento;
			info.frequencia = 1;
			insereFila(&fila, info);
		}

	}

	escreveFila(&fila);

	/*
	 * Crio uma fila com as solicitacoes
	 *
	 * Cria uma fila de prioridade cache com qtdElementos
	 *
	 * Leio cada solicitacao e coloco na fila com a sua frequencia
	 *
	 * crio uma fila de prioridades com base na frequencia
	 *
	 */

	return 0;
}
