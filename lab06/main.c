#include "fila.h"
#include "gerenciaPizzaria.h"

int main () {
	Cliente *fila;

	criar(&fila);
	lePedidos(&fila);
	exibe(&fila);
	destroi(&fila);

	return 0;
}