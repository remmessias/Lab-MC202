#include <stdlib.h>
#include "gerenciaPizzaria.h"
#include "listaClientes.h"
#include "ArvoreAfunilamento.h"

int main () {
	Cliente *listaClientes;
	Cliente *listaEspera;
	SplayTreeNode *arvoreIngredientes = NULL;

	criaListaClientes(&listaEspera);
	criaListaClientes(&listaClientes);

	abrePizzaria(&listaClientes, &listaEspera, arvoreIngredientes);

	escreveListaClientes(&listaClientes);


	//TODO: LIBERAR MEMÓRIA DAS DUAS LISTAS
	//destruir lista
	destroiArvore(&arvoreIngredientes);

	return 0;
}