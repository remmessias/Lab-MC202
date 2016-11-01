#include "filaPrioridade.h"

FilaPrioridade inicializaFila (int tamCache) {
	FilaPrioridade novaFila;

	novaFila.capacidade = tamCache;
	novaFila.estaCheio = 0;
	novaFila.quantidade = 0;

	novaFila.cache = malloc(tamCache * sizeof(Informacoes));

	return novaFila;
}

int temCache (Informacoes info, FilaPrioridade fila) {
	int i;

	for (i = 0; i < fila.capacidade; i++) {
		if (fila.cache[i].valor == info.valor)
			return 1;
	}

	return 0;
}

void removeMin (FilaPrioridade fila) {
	Informacoes min = fila.cache[0];
	fila.cache[0] = fila.cache[fila.quantidade-1];
	fila.quantidade--;
	sobe(fila, 0);


	//Adapt to extract min
//	take out A[1]
//	A[1] = A[A.length-1]
//	i = 1; A.length--
//	while (i < A.length)
//		if A[i] > (L = the larger of i's children)
//			swap(A[i], L)
}

void insere (Informacoes info, FilaPrioridade fila) {
	//check visualgo agortithm
}