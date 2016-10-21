#include "gerenciaPizzaria.h"
#include "listaClientes.h"

int main () {
	Cliente *listaClientes;

	criaListaClientes(&listaClientes);
	lePedidos(&listaClientes);

	escreveListaClientes(&listaClientes);
	//TODO: LIBERAR MEMÓRIA DAS DUAS LISTAS
	//printar lista
	//destruir lista

	return 0;
}