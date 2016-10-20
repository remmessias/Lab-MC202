#include "gerenciaPizzaria.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxiliar.h"
#include "fila.h"

void lePedidos(Cliente **fila) {
	String ingredientes = "";
	int tempo, senha = 1;

	while(scanf("%d %[^\n]s", &tempo, ingredientes) != EOF) {
		Informacoes info;
		char** tokens;
		int i;

		info.senha = senha;
		info.quandoChegou = tempo*10;
		info.pizza.assando = false;

		tokens = str_split(ingredientes, ' ');

		for (i = 0; *(tokens + i); i++);

		int qtdIngredientes = i;
		info.pizza.qtdIngrediente = qtdIngredientes;
		info.pizza.ingredientes = malloc(sizeof(Ingrediente)*qtdIngredientes);

		for (i = 0; *(tokens + i); i++) {
			strcpy(info.pizza.ingredientes[i].nome, *(tokens + i));
			info.pizza.ingredientes[i].tempo = 20;
			free(*(tokens + i));
		}
		free(tokens);
		insere(fila, info);
		senha++;
	}
}
