#include <stdio.h>
//#include <stdlib.h>
#include "lista.h"

int main () {
	No *lista;
	int m, n, p;

	criar(&lista);



	scanf(" %d %d %d", &m, &n, &p);


	criar(&lista);
	insere(&lista, 5);
	insere(&lista, 6);
	insere(&lista, 7);
	insere(&lista, 8);
	insere(&lista, 9);

	escreve(&lista);

	destruir(&lista);

	return 0;
}