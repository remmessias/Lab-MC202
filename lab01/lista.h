#ifndef LAB01_LISTA_H
#define LAB01_LISTA_H

typedef struct No {
	int numero;
	struct No *prox;
} No;

void criar (No **lista);

void insere (No **lista, int numero);

void destruir (No **lista);

No *procura (No **lista, int numero);

void escreve (No **lista);

#endif
