#include "gerenciaArquivos.h"
#include <stdio.h>
#include <string.h>

#define REMOVER "rm"
#define LISTAR "ls"
#define CRIAR "touch"
#define INEXISTENTE "nao existem arquivos com essa expressao\n"

void leAcao(Arvore *arvore) {
	String comando = "", arquivo = "";

	while (scanf("%s %s", comando, arquivo) != EOF) {
		if (strcmp(comando, REMOVER) == 0) {
			char* posicao = strchr(arquivo, '*');
			if (posicao != NULL) {
				char *prefixo = strtok(arquivo, "*");

				if (prefixo == NULL) {
					printf(INEXISTENTE);
					continue;
				}

				int achou = 0;

				remover(arvore, prefixo, &achou);

				if (!achou)
					printf(INEXISTENTE);
			}
			else {
				int achou = 0;

				remover(arvore, arquivo, &achou);

				if (!achou)
					printf(INEXISTENTE);

			}
		}
		else if (strcmp(comando, LISTAR) == 0) {
			if (strcmp(arquivo, "*") == 0)
				listarTudo(arvore->raiz);
			else {
				char* posicao = strchr(arquivo, '*');

				if (posicao != NULL) {
					char *prefixo = strtok(arquivo, "*");

					if (prefixo == NULL) {
						printf(INEXISTENTE);
						continue;
					}

					int achou = 0;

					NoArvore *primeiraOcorrencia = procurarNo(arvore, prefixo);

					listarPorPrefixo(primeiraOcorrencia, prefixo, &achou);

					if (!achou)
						printf(INEXISTENTE);
				}
				else {
					int achou = 0;

					NoArvore *primeiraOcorrencia = procurarNo(arvore, arquivo);

					listarPorPrefixo(primeiraOcorrencia, arquivo, &achou);

					if (!achou)
						printf(INEXISTENTE);
				}
			}
		}
		else if (strcmp(comando, CRIAR) == 0) {
			inserirNo(arvore, arquivo);
		}
	}
}