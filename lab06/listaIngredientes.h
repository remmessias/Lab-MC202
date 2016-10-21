#ifndef LAB06_LISTA_H
#define LAB06_LISTA_H

#include "tipos.h"

void criaListaIngredientes(ListaNo **no);

int listaIngredientesVazia(ListaNo **no);

void insereListaIngredientes(ListaNo **no, Ingrediente ingrediente);

Ingrediente removeListaIngredientes(ListaNo **no);

void escreveListaIngredientes(ListaNo **no);

#endif //LAB06_LISTA_H
