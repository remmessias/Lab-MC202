#include "sudokuDasRainhas.h"

int main () {
	int ordemTabuleiro, temSolucao;
	char **tabuleiroP;
	char **tabuleiroG;

	lerInt(&ordemTabuleiro);

	if (ordemTabuleiro <= 9) {
		tabuleiroP = alocarMatriz(ordemTabuleiro);
		lerMatriz(tabuleiroP, ordemTabuleiro);
		escreveMatriz(tabuleiroP, ordemTabuleiro);
		temSolucao = existeSolucao(tabuleiroP, ordemTabuleiro);
		escreveResposta(temSolucao);
		liberaMatriz(tabuleiroP, ordemTabuleiro);
	}
	else {
		tabuleiroG = alocarMatriz(ordemTabuleiro);
		lerMatriz(tabuleiroG, ordemTabuleiro);
		escreveMatriz(tabuleiroG, ordemTabuleiro);
		temSolucao = existeSolucao(tabuleiroG, ordemTabuleiro);
		escreveResposta(temSolucao);
		liberaMatriz(tabuleiroG, ordemTabuleiro);
	}

	return 0;
}