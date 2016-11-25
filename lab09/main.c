#include <stdlib.h>
#include "caminho.h"

int main() {
	Pixel *pixel = NULL;
	int resposta = 0;

	Img *imagem = lerImagem();

	pixel = procuraBranco(&imagem);

	resposta = buscaLargura(&imagem, pixel);

	printaResposta(resposta);

	liberaImagem(imagem);

	return 0;
}