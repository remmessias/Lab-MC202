#ifndef LAB07_FILAPRIORIDADE_H
#define LAB07_FILAPRIORIDADE_H

typedef struct {
	int *v;
	int tam;
} FilaPrioridade;

int esq(int i) {
	return 2*i + 1;
}

int dir(int i) {
	return 2*i + 2;
}

int pai(int i) {
	return (i - 1)/2;
}

void desce(FilaPrioridade *fila, int i) {
// se não for folha
	int maior = i;
	if (esq(i) < fila->tam && fila->v[esq(i)] > fila->v[maior])
		maior = esq(i);
	if (dir(i) < fila->tam && fila->v[dir(i)] > fila->v[maior])
		maior = dir(i);
	if (i != maior) {
		troca(&fila->v[i], &fila->v[maior]);
		desce(fila, maior);
	}
}

void criar_fila(FilaPrioridade *fila, int *dados, int tam);
void inserir(FilaPrioridade *fila, int x);
int remover_max(FilaPrioridade *fila);
void aumenta_prioridade(FilaPrioridade *fila, int i, int x);
void diminui_prioridade(FilaPrioridade *fila, int i, int x);

#endif //LAB07_FILAPRIORIDADE_H
