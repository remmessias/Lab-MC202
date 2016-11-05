#ifndef LAB07_FILAPRIORIDADE_H
#define LAB07_FILAPRIORIDADE_H

#include "fila.h"

typedef struct {
	int capacidade, quantidade, estaCheio, estaVazio;
	int *cache;
} FilaPrioridade;


/*
 * Função que inicializa uma fila de prioridade
 */
FilaPrioridade inicializaFila (int tamCache);

/*
 * Função que insere em uma fila de prioridade
 */
void insere (int info, FilaPrioridade *fila);

/*
 * Função que verifica se tem um item em uma fila de prioridade
 */
int temCache (int info, FilaPrioridade *fila);

/*
 * Função que vê qual é o emnor filho de um nó caso ele tenha
 */
int menorFilho(int i, FilaPrioridade *fila);

/*
 * Função que troca elementos em uma fila de prioridade
 */
void troca(FilaPrioridade *fila, int pai, int menor);

/*
 * Função que remove o nó que irá demorar mais para ser acessado
 */
void removeUltimoASerAcessado(NoFila **fila, FilaPrioridade *filaPrioridade);

/*
 * Função que remove um nó
 */
void remover(FilaPrioridade *filaPrioridade, int pos);

#endif //LAB07_FILAPRIORIDADE_H
