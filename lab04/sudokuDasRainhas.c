#include "sudokuDasRainhas.h"
#include <stdio.h>
#include <stdlib.h>

void lerInt (int *valor) {
	scanf(" %d", valor);
}

char** alocarMatriz(int ordem) {
	int i,j;

	char **m = malloc(ordem * sizeof(char*));

	for (i = 0; i < ordem; i++){
		m[i] = (char*) malloc(ordem * sizeof(char));
		for (j = 0; j < ordem; j++){
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

void escreveMatriz(char **matriz, int ordem) {
	int i, j;

	for (i = 0; i < ordem; i++) {
		for (j = 0; j < ordem; j++) {
			if (j == ordem-1)
				printf("%c\n", matriz[i][j]);
			else
				printf("%c ", matriz[i][j]);
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

int existeSolucao(char **matriz, int ordem) {
	Pilha *pilha;
	int qtdDamas = ordem, i = 0, j = 0;
	int empilhou = 0;

	criar(&pilha);

	while (qtdDamas > 0) {
		for (i = 0; i < ordem; i++) {
			for (j = 0; j < ordem; j++) {
				if (!temDamaNaLinha(&pilha, i)) {
					if (!temDamaNaColuna(&pilha, j)) {
						if (!temCelula(&pilha, matriz[i][j])) {
						 	if(!temDamaNasDiagonais(&pilha, i, j, matriz, ordem)) {
								Informacoes info;
								info.linha = i;
								info.coluna = j;
								info.celula = matriz[i][j];
								empilha(&pilha, info);
								empilhou = 1;
								break;
							}
							else {
								j++;
								continue;
							}
						}
						else {
							j++;
							continue;
						}
					}
					else {
						j++;
						continue;
					}
				}
				else {
					i++;
					j = -1;
					continue;
				}
			}
			if (empilhou == 1) {
				empilhou = 0;
				break;
			}
		}
		qtdDamas--;
	}

	destroi(&pilha);
	return 1;
}

//int verifica(int linha, int coluna, char **matriz, Pilha **pilha, int ordem) {
//
//	if (temDamaNaLinha(pilha, linha))
//		return 1;
//
//	if (temDamaNaColuna(pilha, coluna))
//		return 1;
//
//	if (temCelula(pilha, matriz[linha][coluna]))
//		return 1;
//
//	if (temDamaNasDiagonais(pilha, linha, coluna, matriz, ordem))
//		return 1;
//
//	return 0;
//}

int temDamaNasDiagonais(Pilha **pilha, int linha, int coluna, char **matriz, int ordem) {
	//verificar dama na parte de cima esquerda
	if (verificaSegundoQuadrante(linha-1, coluna-1, matriz, pilha))
		return 1;
	//verificar dama na parte de cima direita
	if (verificaPrimeiroQuadrante(linha-1, coluna+1, matriz, pilha, ordem))
		return 1;
	//verificar dama na parte de baixo esquerda
	if (verificaTerceiroQuadrante(linha+1, coluna-1, matriz, pilha, ordem))
		return 1;
	//verificar dama na parte de baixo direita
	if (verificaQuartoQuadrante(linha+1, coluna+1, matriz, pilha, ordem))
		return 1;

	return 0;
}

int verificaPrimeiroQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem) {
	if (linha < 0 || coluna > ordem)
		return 0;
	if(temDama(linha, coluna, pilha))
		return 1;

	return verificaPrimeiroQuadrante(linha-1, coluna+1, matriz, pilha, ordem);
}

int verificaSegundoQuadrante(int linha, int coluna, char **matriz, Pilha **pilha) {
	if (linha < 0 || coluna < 0)
		return 0;
	if(temDama(linha, coluna, pilha))
		return 1;

	return verificaSegundoQuadrante(linha-1, coluna-1, matriz, pilha);
}

int verificaTerceiroQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem) {
	if (linha > ordem|| coluna < 0)
		return 0;
	if(temDama(linha, coluna, pilha))
		return 1;

	return verificaTerceiroQuadrante(linha+1, coluna-1, matriz, pilha, ordem);
}

int verificaQuartoQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem) {
	if (linha > ordem|| coluna > ordem)
		return 0;
	if(temDama(linha, coluna, pilha))
		return 1;

	return verificaQuartoQuadrante(linha+1, coluna+1, matriz, pilha, ordem);
}

int temDama(int linha, int coluna, Pilha **pilha) {
	Pilha *aux;
	for (aux = *pilha; aux != NULL; aux = aux->prox) {
		if (aux->info.linha == linha && aux->info.coluna == coluna)
			return 1;
	}
	return 0;
}

int temCelula(Pilha **pilha, char celula) {
	Pilha *aux;
	for (aux = *pilha; aux != NULL; aux = aux->prox) {
		if (aux->info.celula == celula)
			return 1;
	}
	return 0;
}

int temDamaNaColuna(Pilha **pilha, int coluna) {
	Pilha *aux;
	for (aux = *pilha; aux != NULL; aux = aux->prox) {
		if (aux->info.coluna == coluna)
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

void escreveResposta(int existe) {
	if (existe)
		printf("Tem solucao.");
	else
		printf("Sem solucao.");
}