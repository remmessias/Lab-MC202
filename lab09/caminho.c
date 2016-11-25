#include "caminho.h"
#include <stdlib.h>
#include <stdio.h>

void printaResposta(int resposta) {
	printf("Maria deve memorizar %d regioes.\n", resposta);
}

Pixel *procuraBranco(Img **img) {
	int i, j;
	Img *aux = *img;

	for (i = 0; i < aux->height; i++) {
		for (j = 0; j < aux->width; j++) {
			if (aux->matriz[i][j].cor == BRANCO)
				return &aux->matriz[i][j];
		}
	}

	return NULL;
}

int buscaLargura(Img **imagem, Pixel *pixel) {
	int i, j, qtd = 0;
	Img *aux = *imagem;
	Fila *fila;

	for (i = 0; i < aux->height; i++) {
		for (j = 0; j < aux->width; j++) {
			aux->matriz[i][j].distancia = 0;
			aux->matriz[i][j].pai = NULL;
			aux->matriz[i][j].marca = false;
		}
	}

	criarFila(&fila);

	pixel->distancia = 0;
	pixel->marca = true;

	insereFila(&fila, *pixel);

	while (!filaVazia(&fila)) {
		Pixel p = removeFila(&fila);

		//baixo
		if (p.i + 1 >= 0 && p.i + 1 < aux->height) {
			if (!aux->matriz[p.i + 1][p.j].marca) {
				if (p.cor == aux->matriz[p.i + 1][p.j].cor)
					aux->matriz[p.i + 1][p.j].distancia = p.distancia;
				else {
					aux->matriz[p.i + 1][p.j].distancia = p.distancia + 1;
				}

				if (aux->matriz[p.i + 1][p.j].cor == BRANCO && aux->matriz[p.i + 1][p.j].distancia > 0) {
					destroiFila(&fila);
					return aux->matriz[p.i + 1][p.j].distancia-1;
				}

				aux->matriz[p.i + 1][p.j].pai = malloc(sizeof(Pixel));

				*(aux->matriz[p.i + 1][p.j].pai) = p;

				if (aux->matriz[p.i + 1][p.j].distancia == p.distancia)
					insereComecoFila(&fila, aux->matriz[p.i + 1][p.j]);
				else
					insereFila(&fila, aux->matriz[p.i + 1][p.j]);
				aux->matriz[p.i + 1][p.j].marca = true;
			}
		}

		//cima
		if (p.i - 1 >= 0 && p.i - 1 < aux->height) {
			if (!aux->matriz[p.i - 1][p.j].marca) {
				if (p.cor == aux->matriz[p.i - 1][p.j].cor)
					aux->matriz[p.i - 1][p.j].distancia = p.distancia;
				else {
					aux->matriz[p.i - 1][p.j].distancia = p.distancia + 1;
				}

				if (aux->matriz[p.i - 1][p.j].cor == BRANCO && aux->matriz[p.i - 1][p.j].distancia > 0) {
					destroiFila(&fila);
					return aux->matriz[p.i - 1][p.j].distancia-1;
				}

				aux->matriz[p.i - 1][p.j].pai = malloc(sizeof(Pixel));

				*(aux->matriz[p.i - 1][p.j].pai) = p;

				if (aux->matriz[p.i - 1][p.j].distancia == p.distancia)
					insereComecoFila(&fila, aux->matriz[p.i - 1][p.j]);
				else
					insereFila(&fila, aux->matriz[p.i - 1][p.j]);

				aux->matriz[p.i - 1][p.j].marca = true;
			}
		}

		// esquerda
		if (p.j - 1 >= 0 && p.j - 1 < aux->width) {
			if (!aux->matriz[p.i][p.j - 1].marca) {
				if (p.cor == aux->matriz[p.i][p.j - 1].cor)
					aux->matriz[p.i][p.j - 1].distancia = p.distancia;
				else {
					aux->matriz[p.i][p.j - 1].distancia = p.distancia + 1;
				}

				if (aux->matriz[p.i][p.j - 1].cor == BRANCO && aux->matriz[p.i][p.j - 1].distancia > 0) {
					destroiFila(&fila);
					return aux->matriz[p.i][p.j - 1].distancia-1;
				}

				aux->matriz[p.i][p.j - 1].pai = malloc(sizeof(Pixel));

				*(aux->matriz[p.i][p.j - 1].pai) = p;

				if (aux->matriz[p.i][p.j - 1].distancia == p.distancia)
					insereComecoFila(&fila, aux->matriz[p.i][p.j - 1]);
				else
					insereFila(&fila, aux->matriz[p.i][p.j - 1]);

				aux->matriz[p.i][p.j - 1].marca = true;
			}
		}

		//direita
		if (p.j + 1 >= 0 && p.j + 1 < aux->width) {
			if (!aux->matriz[p.i][p.j + 1].marca) {
				if (p.cor == aux->matriz[p.i][p.j + 1].cor)
					aux->matriz[p.i][p.j + 1].distancia = p.distancia;
				else {
					aux->matriz[p.i][p.j + 1].distancia = p.distancia + 1;
				}

				if (aux->matriz[p.i][p.j + 1].cor == BRANCO && aux->matriz[p.i][p.j + 1].distancia > 0) {
					destroiFila(&fila);
					return aux->matriz[p.i][p.j + 1].distancia-1;
				}

				aux->matriz[p.i][p.j + 1].pai = malloc(sizeof(Pixel));

				*(aux->matriz[p.i][p.j + 1].pai) = p;

				if (aux->matriz[p.i][p.j + 1].distancia == p.distancia)
					insereComecoFila(&fila, aux->matriz[p.i][p.j + 1]);
				else
					insereFila(&fila, aux->matriz[p.i][p.j + 1]);

				aux->matriz[p.i][p.j + 1].marca = true;
			}
		}
	}

	return qtd;
}