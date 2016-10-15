#ifndef LAB05_GERENCIAARQUIVOS_H
#define LAB05_GERENCIAARQUIVOS_H

#include "arvore.h"

#define REMOVER "rm"
#define LISTAR "ls"
#define CRIAR "touch"
#define INEXISTENTE "nao existem arquivos com essa expressao\n"

/*
 * Função que lê a operação e a executa
 */
void leAcao(Arvore *arvore);

#endif //LAB05_GERENCIAARQUIVOS_H
