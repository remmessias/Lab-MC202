#ifndef LAB4_SUDOKUDASRAINHAS_H
#define LAB4_SUDOKUDASRAINHAS_H

#include "pilha.h"

void lerInt(int *valor);

char** alocarMatriz(int ordem);

void lerMatriz(char **matriz, int ordem);

void liberaMatriz(char **matriz, int ordem);

int existeSolucao(char **matriz, int ordem);

void escreveResposta(int existe);

int verificaPrimeiroQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem);

int verificaQuartoQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem);

int verificaTerceiroQuadrante(int linha, int coluna, char **matriz, Pilha **pilha, int ordem);

int verificaSegundoQuadrante(int linha, int coluna, char **matriz, Pilha **pilha);

int temDama(int linha, int coluna, Pilha **pilha);

int temDamaNasDiagonais(Pilha **pilha, int linha, int coluna, char **matriz, int ordem);

int temDamaNaLinha(Pilha **pilha, int linha);

int temDamaNasDiagonais(Pilha **pilha, int linha, int coluna, char **matriz, int ordem);

int temCelula(Pilha **pilha, char celula);

#endif //LAB4_SUDOKUDASRAINHAS_H
