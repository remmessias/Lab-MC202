#include "gerenciaArquivos.h"
#include <stdio.h>
#include <string.h>

void leAcao(Arvore *arvore) {
	String comando = "", arquivo = "";
	int achou = 0;

	while (scanf("%s %s", comando, arquivo) != EOF) {
		if (strcmp(comando, REMOVER) == 0) {
			char* posicao = strchr(arquivo, '*');
			if (posicao != NULL) {
				char *prefixo = strtok(arquivo, "*");
				if (prefixo == NULL) {
					printf(INEXISTENTE);
					continue;
				}
				remover(arvore, prefixo, &achou);
				if (!achou)
					printf(INEXISTENTE);
			}
			else {
				remover(arvore, arquivo, &achou);
				if (!achou)
					printf(INEXISTENTE);
			}
		}
		else if (strcmp(comando, LISTAR) == 0) {
			if (strcmp(arquivo, "*") == 0)
				if (arvore->raiz)
					listarTudo(arvore->raiz);
				else
					printf(INEXISTENTE);
			else {
				char* posicao = strchr(arquivo, '*');
				if (posicao != NULL) {
					char *prefixo = strtok(arquivo, "*");
					if (prefixo == NULL) {
						printf(INEXISTENTE);
						continue;
					}
					NoArvore *primeiraOcorrencia = procurarNo(arvore, prefixo);
					listarPorPrefixo(primeiraOcorrencia, prefixo, &achou);
					if (!achou)
						printf(INEXISTENTE);
				}
				else {
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
		achou = 0;
	}
}