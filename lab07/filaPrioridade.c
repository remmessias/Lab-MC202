#include "filaPrioridade.h"

FilaPrioridade inicializaFila(int tamCache) {
	FilaPrioridade novaFila;
	int i;

	novaFila.capacidade = tamCache;
	novaFila.estaCheio = 0;
	novaFila.estaVazio = 1;
	novaFila.quantidade = 0;

	novaFila.cache = malloc(tamCache * sizeof(Informacoes));

	for (i = 0; i < novaFila.capacidade; i++) {
		novaFila.cache[i].frequencia = -1;
		novaFila.cache[i].valor = -1;
	}

	return novaFila;
}

int temCache(Informacoes info, FilaPrioridade *fila) {
	int i;

	for (i = 0; i < fila->capacidade; i++) {
		if (fila->cache[i].valor == info.valor)
			return 1;
	}

	return 0;
}

void removeMin(FilaPrioridade *fila) {
	int i = 0;
	fila->cache[0] = fila->cache[fila->quantidade - 1];

	fila->cache[fila->quantidade - 1].frequencia = -1;
	fila->cache[fila->quantidade - 1].valor = -1;

	fila->quantidade--;
	while (i < fila->quantidade) {
		int filhoMenor = menorFilho(i, fila);
		if (filhoMenor != -1) {
			if (fila->cache[i].frequencia > filhoMenor) {
				troca(fila, i, filhoMenor);
			}
		}
		i++;
	}

	if (fila->quantidade == 0) {
		fila->estaVazio = 1;
	}
}

void troca(FilaPrioridade *fila, int pai, int filho) {
	Informacoes aux;
	aux = fila->cache[pai];

	fila->cache[pai] = fila->cache[filho];
	fila->cache[filho] = aux;
}

int menorFilho(int pai, FilaPrioridade *fila) {
	int esquerdo = 2 * pai + 1;

	int direito = 2 * pai + 2;

	if (esquerdo <= fila->quantidade - 1 && direito <= fila->quantidade - 1) {
		if (fila->cache[esquerdo].frequencia < fila->cache[direito].frequencia) {
			return fila->cache[pai].frequencia< fila->cache[esquerdo].frequencia ? pai : esquerdo;
		}
		else {
			return fila->cache[pai].frequencia < fila->cache[direito].frequencia ? pai : direito;
		}
	}
	else if (esquerdo <= fila->quantidade - 1) {
		return fila->cache[pai].frequencia < fila->cache[esquerdo].frequencia ? pai : esquerdo;
	}
	else if (direito <= fila->quantidade - 1) {
		return fila->cache[pai].frequencia < fila->cache[direito].frequencia ? pai : direito;
	}

	return -1;
}

void insere(Informacoes info, FilaPrioridade *fila) {
	if (fila->estaVazio) {
		fila->cache[0] = info;
		fila->quantidade++;
		fila->estaVazio = 0;
	}
	else {
		fila->cache[fila->quantidade] = info;
		fila->quantidade++;
		int i = fila->quantidade - 1;
		int pai = (i - 1) / 2;

		while (i >= 0 && fila->cache[pai].frequencia > fila->cache[i].frequencia) {
			troca(fila, pai, i);
			i--;
			pai = (i - 1) / 2;
		}
	}

	if (fila->quantidade == fila->capacidade)
		fila->estaCheio = 1;
}