/*
 * Nome: Rebecca Moreira Messias RA: 186416 Turma: F
 */
#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"
#include "memoryGame.h"

int main () {
	int participantes, rodadas;
	TabelaEspalhamento tabela;
	String *palavras;
	int **pontuacao;

	leInteiro(&tabela.quantidade);

	tabela.tabela = malloc(sizeof(Hash) * tabela.quantidade);

	palavras = malloc(sizeof(String) * tabela.quantidade);

	leTexto(&tabela, palavras);

	leInteiro(&rodadas);
	leInteiro(&participantes);

	pontuacao = alocarMatriz(rodadas, participantes);

	Participantes palavrasParticipante[participantes];

	iniciaJogo(rodadas, participantes, &tabela, pontuacao, palavrasParticipante, palavras);

	calculaPorFase(pontuacao, rodadas, participantes);
	escreveResposta(pontuacao, rodadas, participantes);

	destroiListas(&tabela);
	destroiTabela(&tabela);
	liberaMatriz(pontuacao, rodadas);
	free(palavras);

	return 0;
}