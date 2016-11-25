#ifndef LAB9_CAMINHO_H
#define LAB9_CAMINHO_H

#include "fila.h"

#define BRANCO 16777215

/*
 * Função que conta a quantidade de regiões
 */
int buscaLargura(Img **imagem, Pixel *pixel);

/*
 * Função que procura o primiero pixel branco na matriz da imagem
 */
Pixel *procuraBranco(Img **img);

/*
 * Função que escreve a resposta pro usuário
 */
void printaResposta(int resposta);

#endif //LAB9_CAMINHO_H
