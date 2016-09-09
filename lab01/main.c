#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ORIGINAL "original"
#define PRIMEIRA "primeira"
#define SEGUNDA "segunda"
#define TERCEIRA "terceira"

//////////////////////////////////////////////////////
//                                                  //
//                                                  //
//          Funções e definição de lista.           //
//      Todas as funções operam sobre uma lista     //
//                                                  //
//                                                  //
//////////////////////////////////////////////////////

// Definição de um nó (elemento da lista)
typedef struct No {
	int numero;
	struct No *prox;
} No;

/*
 * Função que cria uma lista.
 */
void criar (No **lista) {
	*lista = NULL;
}

/*
 * Função que insere um novo elemento no final da lista.
 */
void insere (No **lista, int numero) {
	No *novo, *atual = *lista;
	novo = malloc(sizeof(No));
	if (atual == NULL) {
		novo->numero = numero;
		novo->prox = NULL;
		*lista = novo;
	}
	else {
		while (atual->prox != NULL) {
			atual = atual->prox;
		}
		novo->numero = numero;
		novo->prox = NULL;
		atual->prox = novo;
	}
}

/*
 * Função que procura na lista um nó com um determinado número.
 */
No *procura (No **lista, int numero) {
	No *atual = *lista;

	while (atual != NULL) {
		if (atual->numero == numero)
			return atual;
		atual = atual->prox;
	}
	return NULL;
}

/*
 * Função que escreve uma lista ou uma sublista na tela.
 */
void escreve (No **lista) {
	No *atual = *lista;

	while (atual->prox != NULL) {
		printf("%d ", atual->numero);
		atual = atual->prox;
	}
	printf("%d\n", atual->numero);
}

/*
 * Função que procura o último nó da lista.
 */
No *ultimo (No **lista) {
	No *atual = *lista;

	while (atual->prox != NULL) {
		atual = atual->prox;
	}

	return atual;
}

/*
 * Função que destrói a lista após ser utilizada.
 */
void destruir (No **lista) {
	No *atual, *proximo;
	proximo = *lista;
	while (proximo != NULL) {
		atual = proximo;
		proximo = atual->prox;
		free(atual);
	}
}

//////////////////////////////////////////////////////
//                                                  //
//                                                  //
//      Funções auxiliares que são utilizadas       //
//      pelo programa.                              //
//                                                  //
//                                                  //
//////////////////////////////////////////////////////

/*
 * Função que escreve uma sublista dado seu inicio e seu fim
 */
void imprimeSublista(char lista[9], No *inicio, No *fim) {
	printf("%s ", lista);
	while (inicio->numero != fim->numero) {
		printf("%d ", inicio->numero);
		inicio = inicio->prox;
	}
	printf("%d\n", fim->numero);
}

/*
 * Função que escreve a saída na tela para o usuário.
 */
void imprime(No *lista, int inicio, int meio, int fim, No *inicioPrimeiro, No *fimPrimeiro, No *inicioSegundo, No *fimSegundo, No *inicioTerceio, No *fimTerceiro) {
	printf("%s ", ORIGINAL);
	escreve(&lista);
	printf("m=%d, n=%d, p=%d\n", inicio, meio, fim);

	//imprime primeira parte
	imprimeSublista(PRIMEIRA, inicioPrimeiro, fimPrimeiro);
	//imprime segunda parte
	imprimeSublista(SEGUNDA, inicioSegundo, fimSegundo);
	//imprime terceira parte
	imprimeSublista(TERCEIRA, inicioTerceio, fimTerceiro);
}

/*
 * Função que consulta em quais nós cada subdivisão deve
 * começar e acabar. Além disso chama a função de impressão
 * para mostrar ao usuário a saida esperada.
 */
void subdivideLista(No *lista, int inicio, int meio, int fim) {
	No *inicioPrimeiro = procura(&lista, inicio);
	No *meioPrimeiro = procura(&lista, meio);
	No *fimPrimeiro = procura(&lista, fim);

	//se não houver um m para início da primeira lista
	if (inicioPrimeiro == NULL) {
		inicioPrimeiro = lista;
	}

	//se não houver um n para fim da primeira lista
	if (meioPrimeiro == NULL) {
		if (fimPrimeiro == NULL) {
			fimPrimeiro = ultimo(&lista);
		}
		meioPrimeiro = fimPrimeiro;
	}

	No *inicioSegundo = procura(&inicioPrimeiro, meio);
	No *fimSegundo = procura(&lista, fim);

	//se não houver um n para início da segunda lista
	if (inicioSegundo == NULL) {
		inicioSegundo = inicioPrimeiro;
	}

	//se não houver um p para fim da segunda lista
	if (fimSegundo == NULL) {
		fimSegundo = ultimo(&lista);
	}

	No *inicioTerceiro = procura(&inicioSegundo, fim);
	No *ultimoElemento = ultimo(&lista);

	//se não houver um p para início da terceira lista
	if (inicioTerceiro == NULL) {
		inicioTerceiro = inicioSegundo;
	}

	imprime(lista, inicio, meio, fim, inicioPrimeiro, meioPrimeiro, inicioSegundo, fimSegundo, inicioTerceiro, ultimoElemento);
}
/*
 * Função que lê os elementos da lista e os insere nela.
 */
void leLista(No **lista) {
	char s[1000];
	char *token;
	int elemento = -1;

	scanf("%[^\n]s", s);

	token = strtok(s, " ");
	while (token != NULL) {
		sscanf(token, "%d", &elemento);
		insere(lista, elemento);
		token = strtok(NULL, " ");
	}
}

int main () {
	No *lista;
	int inicio, meio, fim;

	criar(&lista);

	leLista(&lista);

	scanf(" %d %d %d", &inicio, &meio, &fim);

	subdivideLista(lista, inicio, meio, fim);

	destruir(&lista);

	return 0;
}