#include "memoryGame.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void calculaPontuacao(Participantes palavrasParticipante[], String frase[], int participantes, int palavrasFrase,
					  int **pontuacao, int rodada, TabelaEspalhamento *tabelaEsp, String *palavras) {
	int i;
	NoLista *no;

	criaLista(&no);

	procuraRespostas(frase, palavrasFrase, tabelaEsp, 0, &no, palavras);

	for (i = 0; i < participantes; i++) {
		int ocorrencia = getQuantidade(&no, palavrasParticipante[i].palavra);
		if (ocorrencia == -1) {
			palavrasParticipante[i].acertou = false;
		}
		else {
			palavrasParticipante[i].acertou = true;
			pontuacao[rodada][i] = 100 * ocorrencia;
		}
	}

	if (alguemAcertou(palavrasParticipante, participantes)) {
		for (i = 0; i < participantes; i++) {
			if (!palavrasParticipante[i].acertou) {
				pontuacao[rodada][i] = - 10 * somatoriaPalavra(&no);
			}
		}
	}

	destroiLista(&no);
}

int somatoriaPalavra(NoLista **no) {
	NoLista *aux;
	int quantidade = 0;
	for (aux = *no; aux != NULL; aux = aux->prox) {
		quantidade += aux->conteudo.qtd;
	}
	return quantidade;
}

void leInteiro(int *inteiro) {
	scanf(" %d", inteiro);
}

bool alguemAcertou(Participantes *participante, int participantes) {
	int i;
	for (i = 0; i < participantes; i++) {
		if (participante[i].acertou)
			return true;
	}
	return false;
}

void iniciaJogo(int rodadas, int participantes, TabelaEspalhamento *tabela, int **pontuacao, Participantes palavrasParticipante[], String *palavras) {
	int i, j, qtdPalavrasFrase;
	for (i = 0; i < rodadas; i++) {
		scanf(" %d", &qtdPalavrasFrase);

		String frase[qtdPalavrasFrase];

		for (j = 0; j < qtdPalavrasFrase; j++) {
			scanf(" %s", frase[j]);
		}

		for (j = 0; j < participantes; j++) {
			scanf(" %s", palavrasParticipante[j].palavra);
		}

		calculaPontuacao(palavrasParticipante, frase, participantes, qtdPalavrasFrase, pontuacao, i, tabela, palavras);
	}
}

void leTexto(TabelaEspalhamento *tabela, String *palavras) {
	int i;
	Informacao info;
	for (i = 0; i < tabela->quantidade; i++) {
		scanf(" %s", info.palavra);
		info.chave = info.posicao = i;
		inserirHash(info, tabela);
		strcpy(palavras[i], info.palavra);
	}
}

void procuraRespostas(String frase[], int qtdPalavras, TabelaEspalhamento *tabela, int indice, NoLista **lista, String *palavras) {
	int hashIndex = codifica(frase[indice], tabela->quantidade);
	No *myNode;

	myNode = tabela->tabela[hashIndex].inicio;

	if (!myNode)
		return;

	while (myNode != NULL) {
		if (strcmp(myNode->info.palavra, frase[indice]) == 0) {
			if (indice == qtdPalavras - 1) {
				insereLista(lista, palavras[myNode->info.posicao + 1]);
			}
			else {
				continuaProcurandoRespostas(frase, myNode->info.posicao, qtdPalavras, tabela, indice + 1, lista, palavras);
			}
		}
		myNode = myNode->proximo;
	}
}

void continuaProcurandoRespostas(String frase[], int posAnterior, int qtdPalavras, TabelaEspalhamento *tabela, int indice, NoLista **lista, String *palavras) {
	int hashIndex = codifica(frase[indice], tabela->quantidade);
	No *myNode;

	myNode = tabela->tabela[hashIndex].inicio;

	if (!myNode)
		return;

	while (myNode != NULL) {
		if (strcmp(myNode->info.palavra, frase[indice]) == 0) {
			if (myNode->info.posicao == posAnterior + 1) {
				if (indice == qtdPalavras - 1) {
					insereLista(lista, palavras[myNode->info.posicao + 1]);
				}
				else {
					continuaProcurandoRespostas(frase, myNode->info.posicao, qtdPalavras, tabela, indice + 1, lista, palavras);
				}
			}
		}
		myNode = myNode->proximo;
	}
}

void calculaPorFase(int **pontuacao, int rodadas, int participantes) {
	int i, j;

	for (i = 0; i < rodadas; i++) {
		for (j = 0; j < participantes; j++) {
			soma(pontuacao, j, i);
		}
	}
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

void soma(int **pontuacao, int j, int rodada) {
	if (rodada != 0)
		pontuacao[rodada][j] += pontuacao[rodada-1][j];

	if (pontuacao[rodada][j] < 0)
		pontuacao[rodada][j] = 0;
}

int** alocarMatriz(int linhas, int colunas){
	int i,j;

	int **m = malloc(linhas * sizeof(int*));

	for (i = 0; i < linhas; i++){
		m[i] = (int*) malloc(colunas * sizeof(int));
		for (j = 0; j < colunas; j++){
			m[i][j] = 0;
		}
	}
	return m;
}

void liberaMatriz(int **matriz, int linhas) {
	int i;
	for (i = 0; i < linhas; i++) {
		free(matriz[i]);
	}
	free(matriz);
}