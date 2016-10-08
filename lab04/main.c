/*
 * Nome: Rebecca Moreira Messias RA: 186416 Turma: F
 *
 * Observação: O lab não esta passando em um teste,
 * tentei refazer o lab de outras maneiras, mas não
 * consegui fazer de uma forma que reduzisse o tempo
 * de execução. Se possível gostaria de receber sugestões
 * do que eu poderia melhorar no lab para que o tempo de
 * execução se reduza na maneira que fiz (utilizando uma
 * pilha).
 *
 * Obrigada e boa correção :)
 */

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