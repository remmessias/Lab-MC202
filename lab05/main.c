#include <stdio.h>
#include "arvore.h"
#include "gerenciaArquivos.h"

int main() {
	Arvore *arvore = NULL;

	arvore = criarArvore();

	leAcao(arvore);

	destroiArvore(arvore);

	return 0;
}
