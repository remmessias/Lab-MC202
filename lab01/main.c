#include <stdio.h>
#include "lista.h"

int main () {
	No *lista;
	int elemento, m, n, p;

	criar(&lista);

	while (scanf("%d", &elemento) == 1) {
		insere(&lista, elemento);
		if (getchar() == '\n')
			break;
	}

	scanf(" %d %d %d", &m, &n, &p);

	destruir(&lista);

	return 0;
}