#include "gerenciaPizzaria.h"
#include <stdio.h>
#include <string.h>
#include "listaIngredientes.h"
#include "listaClientes.h"

void abrePizzaria(Cliente **listaClientes, Cliente **listaEspera, SplayTreeNode *arvoreIngredientes) {
	String ingrediente = "";
	bool fornoEstaVazio = false;
	int tempoDecorrido = 20;
	int tempo, senha = 1;

	while (scanf("%d", &tempo) == 1) {
		Informacoes info;
		criaListaIngredientes(&info.pizza.ingredientes);
		while (scanf("%*[ ]%[^ \r\n]", ingrediente) == 1) {
			Ingrediente ing;
			strcpy(ing.nome, ingrediente);
			ing.tempo = 0;
			info.senha = senha;
			info.quandoChegou = tempo * 10;
 			info.pizza.assando = false;
			insereListaIngredientes(&info.pizza.ingredientes, ing);
		}
		insereListaClientes(listaClientes, info);

		if (!fornoEstaVazio) {
			fornoEstaVazio = true;

			if (estaVazia(listaEspera)) {

			}
			else {
				if (estaVazia(listaClientes)) {

				}
			}


		}

		senha++;
	}
}