#include "gerenciaCache.h"

int main () {
	int tamCache, qtdElementos, qtdSolicitacao, acessos = 0;
	NoFila *fila;
	FilaPrioridade filaPrioridade;

	leEspecificacoes(&tamCache, &qtdElementos, &qtdSolicitacao);

	filaPrioridade = inicializaFila(tamCache);

	criaFila(&fila);

	leAcessos(&fila, qtdSolicitacao);

	acessos = calculaAcessos(&fila, &filaPrioridade);

	escreveAcessos(acessos);

	destroiFila(&fila);

	return 0;
}


