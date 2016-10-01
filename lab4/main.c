#include "sudokuDasRainhas.h"

int main() {
	int ordemTabuleiro, temSolucao;
	char **tabuleiro;

	lerInt(&ordemTabuleiro);

	tabuleiro = alocarMatriz(ordemTabuleiro);
	lerMatriz(tabuleiro, ordemTabuleiro);
	temSolucao = existeSolucao(tabuleiro, ordemTabuleiro);
	escreveResposta(temSolucao);
	liberaMatriz(tabuleiro, ordemTabuleiro);

	return 0;
}