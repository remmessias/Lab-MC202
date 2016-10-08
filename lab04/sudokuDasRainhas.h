#ifndef LAB4_SUDOKUDASRAINHAS_H
#define LAB4_SUDOKUDASRAINHAS_H

#include "pilha.h"

/*
 * Função que lê uma inteiro
 */
void lerInt(int *valor);

/*
 * Função que aloca uma matriz
 */
char** alocarMatriz(int ordem);

/*
 * Função que lê e colca os valores na matriz
 */
void lerMatriz(char **matriz, int ordem);

/*
 * Função que libera a matriz
 */
void liberaMatriz(char **matriz, int ordem);

/*
 * Função que verifica se existe uma solução para o problema
 */
int existeSolucao(char **matriz, int ordem);

/*
 * Função que escreve a resposta para o usuário
 */
void escreveResposta(int existe);

/*
 * Função que percorre a diagonal que estaria no "primeiro quadrante" para verificar se tem célula
 */
int verificaPrimeiroQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem);

/*
 * Função que percorre a diagonal que estaria no "quarto quadrante" para verificar se tem célula
 */
int verificaQuartoQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem);

/*
 * Função que percorre a diagonal que estaria no "terceiro quadrante" para verificar se tem célula
 */
int verificaTerceiroQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem);

/*
 * Função que percorre a diagonal que estaria no "segundo quadrante" para verificar se tem célula
 */
int verificaSegundoQuadrante(int linha, int coluna, char **matriz, Pilha **pilha);

/*
 * Função que verifica tem uma posição já tem uma dama
 */
int temDama(int linha, int coluna, Pilha **pilha);

/*
 * Função que verifica se a linha já possui uma célula
 */
int temDamaNaLinha(Pilha **pilha, int linha);

/*
 * Função que verifica se uma célula já se repetiu
 */
int temCelula(Pilha **pilha, char celula);

#endif //LAB4_SUDOKUDASRAINHAS_H
