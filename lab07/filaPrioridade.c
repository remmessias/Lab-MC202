#include "filaPrioridade.h"

FilaPrioridade inicializaFila(int tamCache) {
	FilaPrioridade novaFila;
	int i;

	novaFila.capacidade = tamCache;
	novaFila.estaCheio = 0;
	novaFila.estaVazio = 1;
	novaFila.quantidade = 0;

	novaFila.cache = malloc(tamCache * sizeof(int));

	for (i = 0; i < novaFila.capacidade; i++) {
		novaFila.cache[i] = -1;
	}

	return novaFila;
}

int temCache(int info, FilaPrioridade *fila) {
	int i;

	for (i = 0; i < fila->capacidade; i++) {
		if (fila->cache[i] == info)
			return 1;
	}

	return 0;
}

void troca(FilaPrioridade *fila, int pai, int filho) {
	int aux;
	aux = fila->cache[pai];

	fila->cache[pai] = fila->cache[filho];
	fila->cache[filho] = aux;
}

int menorFilho(int pai, FilaPrioridade *fila) {
	int esquerdo = 2 * pai + 1;

	int direito = 2 * pai + 2;

	if (esquerdo <= fila->quantidade - 1 && direito <= fila->quantidade - 1) {
		if (fila->cache[esquerdo] < fila->cache[direito]) {
			return fila->cache[pai] < fila->cache[esquerdo] ? pai : esquerdo;
		}
		else {
			return fila->cache[pai] < fila->cache[direito] ? pai : direito;
		}
	}
	else if (esquerdo <= fila->quantidade - 1) {
		return fila->cache[pai] < fila->cache[esquerdo] ? pai : esquerdo;
	}
	else if (direito <= fila->quantidade - 1) {
		return fila->cache[pai] < fila->cache[direito] ? pai : direito;
	}

	return -1;
}

void insere(int info, FilaPrioridade *fila) {
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

		while (i >= 0 && fila->cache[pai] > fila->cache[i]) {
			troca(fila, pai, i);
			i--;
			pai = (i - 1) / 2;
		}
	}

	if (fila->quantidade == fila->capacidade)
		fila->estaCheio = 1;
}

void removeUltimoASerAcessado(NoFila **fila, FilaPrioridade *filaPrioridade) {
	int removeu = 0, i;

	for (i = 0; i < filaPrioridade->quantidade; i++) {
		if (!temElemento(fila, filaPrioridade->cache[i])) {
			removeu = 1;
			remover(filaPrioridade, i);
			break;
		}
	}

	if (!removeu) {
		int pos = -1, nos = 0;
		for (i = 0; i < filaPrioridade->quantidade; i++) {
			int qtdNos = distancia(fila, filaPrioridade->cache[i]);

			if (qtdNos > nos) {
				nos = qtdNos;
				pos = i;
			}
		}

		remover(filaPrioridade, pos);
	}
}

void remover(FilaPrioridade *filaPrioridade, int pos) {
	int i = pos;
	filaPrioridade->cache[pos] = filaPrioridade->cache[filaPrioridade->quantidade-1];
	filaPrioridade->cache[filaPrioridade->quantidade-1] = -1;

	filaPrioridade->quantidade--;

	while (i < filaPrioridade->quantidade) {
		int filhoMenor = menorFilho(i, filaPrioridade);
		if (filhoMenor != -1) {
			if (filaPrioridade->cache[i] > filhoMenor) {
				troca(filaPrioridade, i, filhoMenor);
			}
		}
		i++;
	}

	if (filaPrioridade->quantidade == 0) {
		filaPrioridade->estaVazio = 1;
	}
}