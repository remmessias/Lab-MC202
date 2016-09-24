/*
 * Nome: Rebecca Moreira Messias RA:186416 Turma: F
 */

#include <stdio.h>
#include "pilha.h"
#include "auxiliar.h"

int main() {
	NoPilha *pilhaBrinquedo;
	NoPilha *cores;
	int tamanho;

	criar(&pilhaBrinquedo);
	criar(&cores);

	scanf("%d", &tamanho);
	if (tamanho % 2 == 0) {
		if (leEColacaCor(&pilhaBrinquedo, &cores, tamanho)) {
			cores = ordena(cores);
			escreveResultado(&cores);
		}
	}
	else {
		printf(SAIDA);
	}
	destroi(&pilhaBrinquedo);
	destroi(&cores);

	return 0;
}