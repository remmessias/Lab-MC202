/*
 * Nome: Rebecca Moreira Messias RA: 186416 Turma: F
 *
 * Olá,
 *
 *	Tentei fazer o melhor que pude, mas não passou em 3 testes devido ao tempo.
 *	Acho que já sei como concerta, mas acabei não tendo tempo para consertar até
 *	o horário final de submissão.
 *	Comentei (Documentei) o que achei necessário, pois tentei utilizar nomes que
 *	fossem claros e facilita-se o entendimento.
 *	Aceito crítica construtivas e cometários sbre o que posso melhorar.
 *
 *	Agradecida.
 */

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


