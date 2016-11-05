#ifndef LAB07_GERENCIACACHE_H
#define LAB07_GERENCIACACHE_H

#include "fila.h"
#include "filaPrioridade.h"

/*
 * Lê as especificações do cache
 */
void leEspecificacoes(int *c, int *n, int *a);

/*
 * Printa a resposta para o usuário
 */
void escreveAcessos(int qtdAcessos);

/*
 * Função que calcula a quantidade de acessos
 */
int calculaAcessos(NoFila **fila, FilaPrioridade *filaPrioridade);

/*
 * Lê todos os acessos que serão realizados
 */
void leAcessos(NoFila **fila, int qtdSolicitacao);

#endif //LAB07_GERENCIACACHE_H
