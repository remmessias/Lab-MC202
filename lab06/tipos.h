#ifndef LAB06_TIPOS_H
#define LAB06_TIPOS_H

#include <stdbool.h>

typedef char String[1000];

typedef struct {
	String nome;
	int tempo;
} Ingrediente;

typedef struct {
	Ingrediente *ingredientes;
	int qtdIngrediente;
	bool assando;
} Pizza;

typedef struct {
	int quandoChegou, senha;
	Pizza pizza;
} Informacoes;

typedef struct Cliente {
	Informacoes info;
	struct Cliente *prox;
} Cliente;

#endif //LAB06_TIPOS_H
