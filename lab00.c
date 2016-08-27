#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(int linhas,int colunas){
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
	int i, j, k = 0;

	matrizA = fopen("matrizA.txt", "r");
	matrizB = fopen("matrizB.txt", "r");

	if ((matrizA != NULL) && (matrizB != NULL)) {

		fscanf(matrizA, "%d %d", &linhasA, &colunasA);
		fscanf(matrizB, "%d %d", &linhasB, &colunasB);

		if (colunasA != linhasB) {
			printf("As matrizes nao seguem as propriedades necessarias para realizar a multiplicacao.");
		}
		else {
			matA = alocarMatriz(linhasA, colunasA);
			matB = alocarMatriz(linhasB, colunasB);

			for (i = 0; i < linhasA; i++) {
				for (j = 0; j < colunasA; j++) {
					if (j == colunasA-1)
						fscanf(matrizA, "%d\n", &matA[i][j]);
					else
						fscanf(matrizA, "%d ", &matA[i][j]);
				}
			}

			for (i = 0; i < linhasB; i++) {
				for (j = 0; j < colunasB; j++) {
					if (j == colunasB-1)
						fscanf(matrizB, "%d\n", &matB[i][j]);
					else
						fscanf(matrizB, "%d ", &matB[i][j]);
				}
			}

			resultado = alocarMatriz(linhasA, colunasB);


			// for (i = 0; i < linhasA; i++) {
			// 	for (j = 0; j < colunasB; j++) {
			// 		if (j == colunasB-1)
			// 			printf("%d\n", resultado[i][j]);
			// 		else
			// 			printf("%d ", resultado[i][j]);
			// 	}
			// }


			for (i = 0; i < linhasA; i++) {
				for (j = 0; j < colunasB; j++) {
					k = 0;
					while (k < colunasA) {
						resultado[i][j] += matA[i][k]*matB[k][j];
						k++;
					}
					//printf("posicao %dx%d %d\n", i, j, resultado[i][j]);
				}
			}


			printf("%d %d\n", linhasA, colunasB);
			for (i = 0; i < linhasA; i++) {
				for (j = 0; j < colunasB; j++) {
					if (j == colunasB-1)
						printf("%d\n", resultado[i][j]);
					else
						printf("%d ", resultado[i][j]);
				}
			}




			// for (i = 0; i < linhasA; i++) {
			// 	for (j = 0; j < colunasA; j++) {
			// 		if (j == colunasA-1)
			// 			printf("%d\n", matA[i][j]);
			// 		else
			// 			printf("%d ", matA[i][j]);
			// 	}
			// }

			// for (i = 0; i < linhasB; i++) {
			// 	for (j = 0; j < colunasB; j++) {
			// 		if (j == colunasB-1)
			// 			printf("%d\n", matB[i][j]);
			// 		else
			// 			printf("%d ", matB[i][j]);
			// 	}
			// }

			// printf("%d %d %d %d\n", linhasA, colunasA, linhasB, colunasB);
		}
	}

	fclose(matrizA);
	fclose(matrizB);


	return 0;
}