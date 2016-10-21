#ifndef LAB06_TIPOS_H
#define LAB06_TIPOS_H

#include <stdbool.h>

typedef char String[1000];

typedef struct {
	String nome;
	int tempo;
} Ingrediente;

typedef struct ListaNo{
	Ingrediente ingrediente;
	struct ListaNo *proximo;
} ListaNo;

typedef struct {
	ListaNo *ingredientes;
	bool assando;
} Pizza;

typedef struct {
	int quandoChegou, senha;
	Pizza pizza;
} Informacoes;

typedef struct Cliente {
	Informacoes info;
	struct Cliente *proximo;
} Cliente;

typedef struct SplayTreeNode {
	struct SplayTreeNode *l, *r, *p;
	Ingrediente ingrediente;
} SplayTreeNode;

#endif //LAB06_TIPOS_H
