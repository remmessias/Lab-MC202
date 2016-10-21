#include "listaIngredientes.h"
#include "tipos.h"
#include <stdlib.h>
#include <stdio.h>

void criaListaIngredientes(ListaNo **no) {
	*no = NULL;
}

int listaIngredientesVazia(ListaNo **no) {
	if ((*no) != NULL ) {
		return 0;
	}

	return 1;
}

void insereListaIngredientes(ListaNo **no, Ingrediente ingrediente) {
	ListaNo *novoElemento;
	ListaNo *auxiliar;
	novoElemento =  malloc(sizeof(ListaNo));
	novoElemento->ingrediente = ingrediente;
	novoElemento->proximo = NULL;

	if (listaIngredientesVazia(no)) {
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

Ingrediente removeListaIngredientes(ListaNo **no) {
	ListaNo *auxiliar;
	Ingrediente retorno;

	if (!listaIngredientesVazia(no)) {
		retorno = (*no)->ingrediente;
		auxiliar =  *no;
		*no = (*no)->proximo;
		free(auxiliar);
	}

	return retorno;
}

void escreveListaIngredientes(ListaNo **no) {
	for (ListaNo *aux = *no; aux != NULL; aux = aux->proximo) {
		printf("%s\n", aux->ingrediente.nome);
	}
}