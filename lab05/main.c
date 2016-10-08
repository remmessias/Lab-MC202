#include <stdio.h>
#include "arvore.h"
#include "gerenciaArquivos.h"

int main() {
	Arvore *arvore = NULL;

	arvore = criarArvore();

	leAcao(arvore);

//	inserir(arvore, "Arroz");
//	inserir(arvore, "Batata");
//	inserir(arvore, "Cenoura");
//	inserir(arvore, "Damasco");
//	inserir(arvore, "Empada");
//	inserir(arvore, "Feijão");
//	inserir(arvore, "Goiaba");
//	inserir(arvore, "Hot dog");
//	inserir(arvore, "Iogurte");
//	inserir(arvore, "Jabuticaba");
//
//	remover(arvore, "Damasco");
//
//	buscaProfundidade(arvore->raiz, 0);

	destroi(arvore);

	return 0;
}
