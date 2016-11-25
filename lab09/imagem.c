#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "imagem.h"

Img *lerImagem() {
    Img *img;
    char peek;
    int i, j, r, g, b;

    assert(img = malloc(sizeof(*img)));

	scanf("P3 ");

	while((peek = (char) getchar()) == '#')
		scanf("%*[^\r\n]%*[\r\n]");

	ungetc(peek,stdin);

	assert(scanf("%d %d %*d", &img->width, &img->height)==2);

    assert(img->matriz = malloc(sizeof(*img->matriz) * img->height));

    for (i = 0; i < img->height; i++) {
        assert(img->matriz[i] = malloc(sizeof(**img->matriz) * img->width));
		for (j = 0; j < img->width; j++) {
            assert(scanf("%d%d%d", &r, &g, &b)==3);
            img->matriz[i][j].cor = (r << 16) + (g << 8) + b;
			img->matriz[i][j].distancia = 0;
			img->matriz[i][j].pai = NULL;
			img->matriz[i][j].marca = false;
			img->matriz[i][j].i = i;
			img->matriz[i][j].j = j;
        }
    }

    return img;
}

void liberaImagem(Img *img) {
    int i;
    for (i = 0; i < img->height; i++)
        free(img->matriz[i]);
    free(img->matriz);
    free(img);
}