#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int numero;
	struct No *prox;
} No;

void criar (No **lista) {
	*lista = NULL;
}

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

void destruir (No **lista) {
	No *atual, *proximo;
	proximo = *lista;
	while (proximo != NULL) {
		atual = proximo;
		proximo = atual->prox;
		free(atual);
	}
}

No *procura (No **lista, int numero) {
	No *atual = *lista;

	while (atual != NULL) {
		if (atual->numero == numero)
			return atual;
		atual = atual->prox;
	}
	return NULL;
}

void escreve (No **lista) {
	No *atual = *lista;

	while (atual->prox != NULL) {
		printf("%d ", atual->numero);
		atual = atual->prox;
	}
	printf("%d\n", atual->numero);
}

No *ultimo (No **lista) {
	No *atual = *lista;

	while (atual->prox != NULL) {
		atual = atual->prox;
	}

	return atual;
}

void imprime(No *lista, int m, int n, int p, No *mP, No *nP, No *nS, No *pS, No *pT, No *last) {
	printf("original ");
	escreve(&lista);
	printf("m=%d, n=%d, p=%d\n", m, n, p);

	//imprime primeira parte
	printf("primeira ");
	while (mP->numero != nP->numero) {
		printf("%d ", mP->numero);
		mP = mP->prox;
	}
	printf("%d\n", nP->numero);

	//imprime segunda parte
	printf("segunda ");
	while (nS->numero != pS->numero) {
		printf("%d ", nS->numero);
		nS = nS->prox;
	}
	printf("%d\n", nS->numero);

	//imprime terceira parte
	printf("terceira ");
	while (pT->numero != last->numero) {
		printf("%d ", pT->numero);
		pT = pT->prox;
	}
	printf("%d\n", pT->numero);
}

void subdivideLista(No *lista, int m, int n, int p) {
	No *mP = procura(&lista, m);
	No *nP = procura(&lista, n);
	No *pP = procura(&lista, p);
	No *nS = procura(&mP, n);
	No *pS = procura(&lista, p);
	No *pT = procura(&nS, p);
	No *last = ultimo(&lista);

	if (mP == NULL) {
		mP = lista;
	}

	if (nP == NULL) {
		if (pP == NULL) {
			pP = ultimo(&lista);
		}
		nP = pP;
	}

	if (nS == NULL) {
		nS = mP;
	}

	if (pS == NULL) {
		pS = ultimo(&lista);
	}

	if (pT == NULL) {
		pT= nS;
	}

	imprime(lista, m, n, p, mP, nP, nS, pS, pT, last);
}

int main () {
	No *lista;
	int elemento, m, n, p;

	criar(&lista);

	while (scanf("%d", &elemento) == 1) {
		insere(&lista, elemento);
		if (getchar() == '\n')
			break;
	}

	scanf(" %d %d %d", &m, &n, &p);

	subdivideLista(lista, m, n, p);

	destruir(&lista);

	return 0;
}