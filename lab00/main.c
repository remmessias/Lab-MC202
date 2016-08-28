#include <stdlib.h>
#include <stdio.h>

/*
 * Função que libera o espaço alocado na memória pelas matrizes.
 */
void liberaMatrizes(int **matriz, int linhas) {
	int i;
	for (i = 0; i < linhas; i++) {
		free(matriz[i]);
	}
	free(matriz);
}

/*
 * Função que escreve na tela para o usuário o resultado do produto de matriz
 */
void escreveResultado(int linhasA, int colunasB, int **resultado) {
	int i, j;
	printf("%d %d\n", linhasA, colunasB);
	for (i = 0; i < linhasA; i++) {
		for (j = 0; j < colunasB; j++) {
			if (j == colunasB-1)
				printf("%d\n", resultado[i][j]);
			else
				printf("%d ", resultado[i][j]);
		}
	}
}

/*
 * Função que realiza o produto entre as matrizes
 */
void produtoMatriz(int **matA, int **matB, int **resultado, int linhasA,
				   int colunasA, int colunasB) {
	int i, j, k = 0;
	for (i = 0; i < linhasA; i++) {
		for (j = 0; j < colunasB; j++) {
			k = 0;
			while (k < colunasA) {
				resultado[i][j] += matA[i][k]*matB[k][j];
				k++;
			}
		}
	}
}

/*
 * Função que lê as matrizes do arquivo
 */
void lerMatriz(int **matriz, FILE *arquivo, int linhas, int colunas) {
	int i, j;

	for (i = 0; i < linhas; i++) {
		for (j = 0; j < colunas; j++) {
			if (j == colunas-1)
				fscanf(arquivo, "%d\n", &matriz[i][j]);
			else
				fscanf(arquivo, "%d ", &matriz[i][j]);
		}
	}
}

/*
 * Função que aloca o espaço na memória para as matrizes
 */
int** alocarMatriz(int linhas, int colunas){
	int i,j;

	int **m = malloc(linhas * sizeof(int*));

	for (i = 0; i < linhas; i++){
		m[i] = (int*) malloc(colunas * sizeof(int));
		for (j = 0; j < colunas; j++){
			m[i][j] = 0;
		}
	}
	return m;
}

int main () {
	FILE *matrizA;
	FILE *matrizB;
	int linhasA, colunasA, linhasB, colunasB;
	int **matA;
	int **matB;
	int **resultado;

	matrizA = fopen("/home/rebecca/Documentos/Unicamp/MC202/Laboratórios/lab00/matrizA.txt", "r");
	matrizB = fopen("/home/rebecca/Documentos/Unicamp/MC202/Laboratórios/lab00/matrizB.txt", "r");

	if ((matrizA != NULL) && (matrizB != NULL)) {

		fscanf(matrizA, "%d %d", &linhasA, &colunasA);
		fscanf(matrizB, "%d %d", &linhasB, &colunasB);

		if (colunasA != linhasB) {
			printf("As matrizes nao seguem as propriedades necessarias para realizar a multiplicacao.");
		}
		else {
			matA = alocarMatriz(linhasA, colunasA);
			matB = alocarMatriz(linhasB, colunasB);
			resultado = alocarMatriz(linhasA, colunasB);

			lerMatriz(matA, matrizA, linhasA, colunasA);

			lerMatriz(matB, matrizB, linhasB, colunasB);

			produtoMatriz(matA, matB, resultado, linhasA, colunasA, colunasB);

			escreveResultado(linhasA, colunasB, resultado);

			liberaMatrizes(matA, linhasA);
			liberaMatrizes(matB, linhasB);
			liberaMatrizes(resultado, linhasA);
		}

		fclose(matrizA);
		fclose(matrizB);
	}

	return 0;
}