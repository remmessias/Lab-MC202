#ifndef LAB09_IMAGEM_H
#define LAB09_IMAGEM_H

#include <stdbool.h>

// DEFINIÇÃO DE PIXEL E DA ESTRUTURA DA IMAGEM
typedef struct Pixel{
	int cor, distancia, i, j;
	bool marca;
	struct Pixel *pai;
}Pixel;

typedef struct {
	int width, height;
	Pixel **matriz;
} Img;

/*
 * Função que lê uma imagem
 */
Img *lerImagem();

/*
 * Função que libera uma imagem
 */
void liberaImagem(Img *img);

#endif //LAB09_IMAGEM_H