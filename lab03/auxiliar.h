#ifndef LAB03_AUXILIAR_H
#define LAB03_AUXILIAR_H

#include "pilha.h"

#define SIMBVERMELHO 'v'
#define SIMBAZUL 'a'
#define AZUL "azul"
#define VERMELHO "vermelho"
#define SAIDA "sequencia invalida ou nao pode colorir\n"

/*
 * Função que verifica se brinquedos com o mesmo número possuem mesma cor
 */
int verificarCor(NoPilha **lista, char cor, int elemento);

/*
 * Função que tira módulo de um número
 */
int absoluto(int numero);

/*
 * Função que prepara uma variavel informação para ser empilhada
 */
void empilhaInformacao(int elemento, NoPilha **pilhaBrinquedo);

/*
 * Função que incrementa a quantidade de brinquedos azuis elemento no topo da lista
 */
void incrementaQtdAzulTopo(NoPilha **pilha);

/*
 * Função que verifica se a lista já possui um determinado brinquedo com o mesmo número
 */
int temBrinquedo(NoPilha **pilha, int elemento);

/*
 * Função que imprime a sequancia de cores de cada brinquedo para o usuario
 */
void escreveResultado(NoPilha **pilha);

/*
 * Função que lê e coloca a cor em um determinado brinquedo
 */
int leEColacaCor(NoPilha **pilhaBrinquedo, NoPilha **cores, int tamanho);


#endif //LAB03_AUXILIAR_H
