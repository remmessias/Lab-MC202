#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"
#include "memoryGame.h"

void escreveResposta(int **pontuacao, int rodadas, int participantes);

int main () {
	int participantes, rodadas, qtdPalavrasFrase, i, j;
	TabelaEspalhamento tabela;
	Informacao info;
	String *palavras;
	int **pontuacao;

	scanf(" %d", &tabela.quantidade);

	tabela.tabela = malloc(sizeof(Hash) * tabela.quantidade);

	palavras = malloc(sizeof(String) * tabela.quantidade);

	for (i = 0; i < tabela.quantidade; i++) {
		scanf(" %s", info.palavra);
		info.chave = info.posicao = i;
		inserirHash(info, &tabela);
		strcpy(palavras[i], info.palavra);
	}

	scanf(" %d %d", &rodadas, &participantes);

	pontuacao = malloc(sizeof(int*)*rodadas);

	for (i = 0; i < rodadas; i++) {
		pontuacao[i] = malloc(sizeof(int) * participantes);
	}

	for (i = 0; i < rodadas; i++) {
		for (j = 0; j < participantes; j++) {
			pontuacao[i][j] = 0;
		}
	}

	Participantes palavrasParticipante[participantes];

	for (i = 0; i < rodadas; i++) {
		scanf(" %d", &qtdPalavrasFrase);

		String frase[qtdPalavrasFrase];

		for (j = 0; j < qtdPalavrasFrase; j++) {
			scanf(" %s", frase[j]);
		}

		for (j = 0; j < participantes; j++) {
			scanf(" %s", palavrasParticipante[j].palavra);
		}

		calculaPontuacao(palavrasParticipante, frase, participantes, qtdPalavrasFrase, pontuacao, i, &tabela, palavras);
	}

	calculaPorFase(pontuacao, rodadas, participantes);
	escreveResposta(pontuacao, rodadas, participantes);

	destroiListas(&tabela);
	destroiTabela(&tabela);

	return 0;
}

void escreveResposta(int **pontuacao, int rodadas, int participantes) {
	int i, j;
	for (i = 0; i < rodadas; i++) {
		printf("Rodada %d:", i+1);
		for (j = 0; j < participantes; j++) {
			printf(" %4d", pontuacao[i][j]);
		}
		printf("\n");
	}
}