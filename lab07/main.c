#include <stdio.h>
#include "gerenciaCache.h"
#include "fila.h"
#include "filaPrioridade.h"

int main () {
	int tamCache, qtdElementos, qtdSolicitacao, elemento, acessos = 0, i;
	NoFila *fila;
	FilaPrioridade filaPrioridade;

	leEspecificacoes(&tamCache, &qtdElementos, &qtdSolicitacao);

	filaPrioridade.capacidade = tamCache;
	filaPrioridade.estaCheio = 0;
	filaPrioridade.quantidade = 0;

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

	while (fila != NULL) {
		Informacoes elemen = removeFila(&fila);

		if (elemen.frequencia != -1 && elemen.valor != -1) {
			if (!temCache(elemen, filaPrioridade)) {

				if (!filaPrioridade.estaCheio) {
					removeMin(filaPrioridade);
					filaPrioridade.quantidade--;
					decrementaFrequencia(&fila, elemen.valor);

					// reduz a frequencia no cache

					elemen.frequencia--;
					insere(elemen, filaPrioridade);
					filaPrioridade.quantidade++;
				}
				else {
					insere(elemen, filaPrioridade);
					filaPrioridade.quantidade++;
					if (filaPrioridade.quantidade == filaPrioridade.capacidade)
						filaPrioridade.estaCheio = 1;
					acessos++;
				}
			}
		}
	}

	printf("%d\n", acessos);

	destroiFila(&fila);

	return 0;
}
