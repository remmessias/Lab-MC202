#include "gerenciaArquivos.h"
#include <stdio.h>
#include <string.h>

#define REMOVER "rm"
#define LISTAR "ls"
#define CRIAR "touch"
#define ERRO "nao existem arquivos com essa expressao\n"

void leAcao(Arvore *arvore) {
	String comando = "", arquivo = "";

	while (scanf("%s %s", comando, arquivo) != EOF) {
		if (strcmp(comando, REMOVER) == 0) {
			char* posicao = strchr(arquivo, '*');

			if (posicao != NULL) {
				char *token = strtok(arquivo, "*");

				if (token == NULL) {
					printf(ERRO);
					continue;
				}

				remover(arvore, token);
			}
			else {
				remover(arvore, arquivo);
			}
		}
		else if (strcmp(comando, LISTAR) == 0) {
			printf("Lista\n");
		}
		else if (strcmp(comando, CRIAR) == 0) {
			inserir(arvore, arquivo);
		}
	}
}

int comecaCom(String a, String b) {
	if(strncmp(a, b, strlen(b)) == 0)
		return 1;
	return 0;
}