#include "listaClientes.h"
#include "listaIngredientes.h"
#include <stdlib.h>
#include <stdio.h>

void criaListaClientes(Cliente **no) {
	*no = NULL;
}

int listaClientesVazia(Cliente **no) {
	if ((*no) != NULL ) {
		return 0;
	}

	return 1;
}

void insereListaClientes(Cliente **no, Informacoes informacoes) {
	Cliente *novoElemento;
	Cliente *auxiliar;
	novoElemento =  malloc(sizeof(Cliente));
	novoElemento->info = informacoes;
	novoElemento->proximo = NULL;

	if (listaClientesVazia(no)) {
		*no = novoElemento;
	}
	else {
		auxiliar = *no;
		while (auxiliar->proximo != NULL) {
			auxiliar = auxiliar->proximo;
		}
		auxiliar->proximo = novoElemento;
	}
}

Informacoes removeListaClientes(Cliente **no) {
	Cliente *auxiliar;
	Informacoes retorno;

	if (!listaClientesVazia(no)) {
		retorno = (*no)->info;
		auxiliar =  *no;
		*no = (*no)->proximo;
		free(auxiliar);
	}

	return retorno;
}


void escreveListaClientes(Cliente **no) {
	for (Cliente *aux = *no; aux != NULL; aux = aux->proximo) {
		printf("%d\n", aux->info.senha);
		escreveListaIngredientes(&aux->info.pizza.ingredientes);
	}
}