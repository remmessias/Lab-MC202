#ifndef LAB08_MEMORYGAME_H
#define LAB08_MEMORYGAME_H

#include <stdbool.h>
#include "hashTable.h"
#include "list.h"

typedef struct {
	String palavra;
	bool acertou;
} Participantes;

void calculaPontuacao(Participantes palavrasParticipante[], String frase[], int participantes, int palavrasFrase,
					  int **pontuacao, int rodada, TabelaEspalhamento *tabelaEsp, String *palavras);

void procuraRespostas(String frase[], int qtdPalavras, TabelaEspalhamento *tabela, int indice, NoLista **lista, String *palavras);

void continuaProcurandoRespostas(String frase[], int posAnterior, int qtdPalavras, TabelaEspalhamento *tabela, int indice, NoLista **lista, String *palavras);

void calculaPorFase(int **pontuacao, int rodadas, int participantes);

void soma(int **pontuacao, int j, int rodada);

bool alguemAcertou(Participantes *participante, int participantes);

int somatoriaPalavra(NoLista **no);

#endif //LAB08_MEMORYGAME_H
