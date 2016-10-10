#include <stdio.h>
#include "arvore.h"
#include "gerenciaArquivos.h"

int main() {
	Arvore *arvore = NULL;

	arvore = criarArvore();

	leAcao(arvore);

	destroi(arvore);

	return 0;
}
