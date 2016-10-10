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
				char *prefixo = strtok(arquivo, "*");

				if (prefixo == NULL) {
					printf(ERRO);
					continue;
				}
				int achou;
				remover(arvore, prefixo, &achou);

				if (!achou)
					printf(ERRO);
			}
			else {
				int achou = 0;

				remover(arvore, arquivo, &achou);

				if (!achou)
					printf(ERRO);

			}
		}
		else if (strcmp(comando, LISTAR) == 0) {
			if (strcmp(arquivo, "*") == 0)
				buscaProfundidade(arvore->raiz);
			else {
				char* posicao = strchr(arquivo, '*');

				if (posicao != NULL) {
					char *prefixo = strtok(arquivo, "*");

					if (prefixo == NULL) {
						printf(ERRO);
						continue;
					}
					int achou = 0;
					listarPorPrefixo(arvore->raiz, prefixo, &achou);

					if (!achou)
						printf(ERRO);
				}
				else {
					int achou = 0;
					listarPorPrefixo(arvore->raiz, arquivo, &achou);

					if (!achou)
						printf(ERRO);
				}
			}
		}
		else if (strcmp(comando, CRIAR) == 0) {
			inserir(arvore, arquivo);
		}
//		printf("i-------------------------------------------------------\n");
//		if (arvore->raiz != NULL)
//			buscaProfundidade(arvore->raiz, 0);
//		printf("F-------------------------------------------------------\n");
	}
}