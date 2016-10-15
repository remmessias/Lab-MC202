#include <stdio.h>
#include "arvore.h"
#include "gerenciaArquivos.h"

/*
 * Nome: Rebecca Moreira Messias RA: 186416 Turma: F
 *
 * Observações: Poderia, por favor me dizer o que a de errado com teste 5?
 * Não sei o que poderia estar dando errado pra ele.
 *
 */

int main() {
	Arvore *arvore = NULL;

	arvore = criarArvore();

	leAcao(arvore);

	destroiArvore(arvore);

	return 0;
}
