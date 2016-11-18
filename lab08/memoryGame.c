#include "memoryGame.h"
#include <string.h>

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

bool alguemAcertou(Participantes *participante, int participantes) {
	int i;
	for (i = 0; i < participantes; i++) {
		if (participante[i].acertou)
			return true;
	}
	return false;
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

void soma(int **pontuacao, int j, int rodada) {
	if (rodada != 0)
		pontuacao[rodada][j] += pontuacao[rodada-1][j];

	if (pontuacao[rodada][j] < 0)
		pontuacao[rodada][j] = 0;
}