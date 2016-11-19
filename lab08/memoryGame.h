#ifndef LAB08_MEMORYGAME_H
#define LAB08_MEMORYGAME_H

#include <stdbool.h>
#include "hashTable.h"
#include "list.h"

typedef struct {
	String palavra;
	bool acertou;
} Participantes;

/*
 * Função que dá inicio a busca de plavras para calcular a pontuação na rodada de cada participante
 */
void calculaPontuacao(Participantes palavrasParticipante[], String frase[], int participantes, int palavrasFrase,
					  int **pontuacao, int rodada, TabelaEspalhamento *tabelaEsp, String *palavras);

/*
 * Função que procura as possiveis palavras para continuação da frase
 */
void procuraRespostas(String frase[], int qtdPalavras, TabelaEspalhamento *tabela, int indice, NoLista **lista, String *palavras);

/*
 * Função que procura as possiveis palavras para continuação da frase (função recursiva para caso a frase tenha mais de uma palavra)
 */
void continuaProcurandoRespostas(String frase[], int posAnterior, int qtdPalavras, TabelaEspalhamento *tabela, int indice, NoLista **lista, String *palavras);

/*
 * Função que calcula a pontuação em cada rodada levando em conta as rodadas anteriores
 */
void calculaPorFase(int **pontuacao, int rodadas, int participantes);

/*
 * Função para fazer a somatatória da pontuação
 */
void soma(int **pontuacao, int j, int rodada);

/*
 * Função que escreve a resposta
 */
void escreveResposta(int **pontuacao, int rodadas, int participantes);

/*
 * Função que verifica se algum participante acertou
 */
bool alguemAcertou(Participantes *participante, int participantes);

/*
 * Função que le um inteiro
 */
void leInteiro(int *inteiro);

/*
 * Função que inicia o jogo lendo as frases de cada rodada e as opniões dos participantes
 */
void iniciaJogo(int rodadas, int participantes, TabelaEspalhamento *tabela, int **pontuacao, Participantes palavrasParticipante[], String *palavras);

/*
 * Função que le o texto
 */
void leTexto(TabelaEspalhamento *tabela, String *palavras);

/*
 * Função que conta quantas palavras tinha como resposta
 */
int somatoriaPalavra(NoLista **no);

/*
 * Função que libera uma matriz
 */
void liberaMatriz(int **matriz, int linhas);

/*
 * Função que aloca uma matriz
 */
int** alocarMatriz(int linhas, int colunas);

#endif //LAB08_MEMORYGAME_H
