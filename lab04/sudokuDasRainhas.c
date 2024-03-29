#include "sudokuDasRainhas.h"
#include <stdio.h>
#include <stdlib.h>

void lerInt(int *valor) {
	scanf(" %d", valor);
}

char **alocarMatriz(int ordem) {
	int i, j;

	char **m = malloc(ordem * sizeof(char *));

	for (i = 0; i < ordem; i++) {
		m[i] = (char *) malloc(ordem * sizeof(char));
		for (j = 0; j < ordem; j++) {
			m[i][j] = 0;
		}
	}

	return m;
}

void lerMatriz(char **matriz, int ordem) {
	int i, j;

	for (i = 0; i < ordem; i++) {
		for (j = 0; j < ordem; j++) {
			scanf(" %c", &matriz[i][j]);
		}
	}
}

void liberaMatriz(char **matriz, int ordem) {
	int i;
	for (i = 0; i < ordem; i++) {
		free(matriz[i]);
	}
	free(matriz);
}

void escreveResposta(int existe) {
	if (existe)
		printf("Tem solucao.\n");
	else
		printf("Sem solucao.\n");
}

int existeSolucao(char **matriz, int ordem) {
	Pilha *ondeTemDamas;
	int qtdDamasFixada = ordem, i;
	int coluna;

	criar(&ondeTemDamas);

	Informacoes info;
	info.linha = 0;
	info.coluna = 0;
	info.celula = matriz[info.linha][info.coluna];
	empilha(&ondeTemDamas, info);
	qtdDamasFixada--;

	while (qtdDamasFixada > 0) {
		Informacoes topo = getTopo(&ondeTemDamas);
		coluna = topo.coluna + 1;
		for (i = 0; i < ordem; i++) {
			if (!temDamaNaLinha(&ondeTemDamas, i) && !temCelula(&ondeTemDamas, matriz[i][coluna]) &&
				!(verificaSegundoQuadrante(i - 1, coluna - 1, matriz, &ondeTemDamas) ||
				  verificaPrimeiroQuadrante(i - 1, coluna + 1, matriz, &ondeTemDamas, ordem) ||
				  verificaTerceiroQuadrante(i + 1, coluna - 1, matriz, &ondeTemDamas, ordem) ||
				  verificaQuartoQuadrante(i + 1, coluna + 1, matriz, &ondeTemDamas, ordem))) {
				info.linha = i;
				info.coluna = coluna;
				info.celula = matriz[i][coluna];
				empilha(&ondeTemDamas, info);
				qtdDamasFixada--;
				break;
			}
			else {
				if (i == ordem - 1) {
					do {
						info = desempilha(&ondeTemDamas);
						qtdDamasFixada++;
						i = info.linha;
						coluna = info.coluna;
						if (info.linha == -1 && info.coluna == -1) {
							destroi(&ondeTemDamas);
							return 0;
						}
					} while (info.linha == ordem - 1);
				}
				continue;
			}
		}
	}

	destroi(&ondeTemDamas);
	return 1;
}

int temCelula(Pilha **pilha, char celula) {
	Pilha *aux;
	for (aux = *pilha; aux != NULL; aux = aux->prox) {
		if (aux->info.celula == celula)
			return 1;
	}
	return 0;
}

int temDamaNaLinha(Pilha **pilha, int linha) {
	Pilha *aux;
	for (aux = *pilha; aux != NULL; aux = aux->prox) {
		if (aux->info.linha == linha)
			return 1;
	}
	return 0;
}

int verificaPrimeiroQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem) {
	if (linha < 0 || coluna > ordem)
		return 0;
	if (temDama(linha, coluna, pilha))
		return 1;

	return verificaPrimeiroQuadrante(linha - 1, coluna + 1, matriz, pilha, ordem);
}

int verificaSegundoQuadrante(int linha, int coluna, char **matriz, Pilha **pilha) {
	if (linha < 0 || coluna < 0)
		return 0;
	if (temDama(linha, coluna, pilha))
		return 1;

	return verificaSegundoQuadrante(linha - 1, coluna - 1, matriz, pilha);
}

int verificaTerceiroQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem) {
	if (linha > ordem || coluna < 0)
		return 0;
	if (temDama(linha, coluna, pilha))
		return 1;

	return verificaTerceiroQuadrante(linha + 1, coluna - 1, matriz, pilha, ordem);
}

int verificaQuartoQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem) {
	if (linha > ordem || coluna > ordem)
		return 0;
	if (temDama(linha, coluna, pilha))
		return 1;

	return verificaQuartoQuadrante(linha + 1, coluna + 1, matriz, pilha, ordem);
}

int temDama(int linha, int coluna, Pilha **pilha) {
	Pilha *aux;
	for (aux = *pilha; aux != NULL; aux = aux->prox) {
		if (aux->info.linha == linha && aux->info.coluna == coluna)
			return 1;
	}
	return 0;
}