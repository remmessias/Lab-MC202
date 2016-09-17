/*
 * Nome: Rebecca Moreira Messias RA:186416 Turma: F
 */

#include <stdio.h>
#include <stdlib.h>

typedef  struct NoPilha {
	int dado;
	struct NoPilha *prox;
} NoPilha;

void criar(NoPilha **p) {
	*p = NULL;
}

void empilha (NoPilha **p, int dado) {
	NoPilha *q = malloc(sizeof(NoPilha));
	q->dado = dado;
	q->prox = *p;
	*p = q;
}

int desempilha (NoPilha **p) {
	NoPilha *q = *p;

	if (q != NULL) {
		int dado = q->dado;
		*p = q->prox;
		free(q);
		return dado;
	}

	return 0;
}

int procura (NoPilha **p, int dado) {
	for (NoPilha *q = *p; q != NULL; q = q->prox) {
		if (q->dado == dado) {
			return 1;
		}
	}

	return 0;
}

void escreve (NoPilha **p) {
	for (NoPilha *q = *p; q != NULL; q = q->prox) {
		if (q->prox == NULL)
			printf("%d\n", q->dado);
		else
			printf("%d ", q->dado);
	}
}

void destroi (NoPilha **p) {
	NoPilha *prox;

	for (NoPilha *q = *p; q != NULL; q = prox) {
		prox = q->prox;
		free(q);
	}
}

int absoluto (int numero) {
	if (numero < 0)
		return -numero;

	return numero;
}

int main () {
	NoPilha *pilhaBrinquedo;
	int tamanho, elemento, desempilhado, i;

	criar(&pilhaBrinquedo);

	scanf("%d", &tamanho);

	 /*
	  * 1- Ler N números (N é a variável tamanho)
	  * 	1.1- Se o número for negativo empilhar
	  * 	1.2- Se for positivo desempilhar
	  * 	1.3- verificar se o módulo são iguais
	  * 		1.2.1- Se for
	  *
	  */


	for (i = 0; i < tamanho; i ++) {
		scanf(" %d", &elemento);
		if (elemento < 0)
			empilha(&pilhaBrinquedo, elemento);
		else {
			desempilhado = desempilha(&pilhaBrinquedo);

			if (absoluto(desempilhado) == elemento) {

			}
			else {
				printf("sequencia invalida ou nao pode colorir");
				break;
			}
		}
	}






	return 0;
}

