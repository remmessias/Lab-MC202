#ifndef LAB08_HASHTABLE_H
#define LAB08_HASHTABLE_H

// DEFINIÇÕES DE ESTRUTURAS

typedef char String[50];

typedef struct {
	int chave, posicao;
	String palavra;
} Informacao;

typedef struct No {
	Informacao info;
	struct No *proximo;
} No;

typedef struct Hash {
	No *inicio;
	int qtdElemen;
} Hash;

typedef struct {
	Hash *tabela;
	int quantidade;
} TabelaEspalhamento;

/*
 * Função que insere uma Informacao na TabelaEspalhamento
 */
void inserirHash(Informacao info, TabelaEspalhamento *tabela);

/*
 * Função que calcula o hash dado uma String e o tamanho da hashtable
 */
int codifica(String palavra, int tam);

/*
 * Função que cria um no de um item que será inserido na tabela de espalhamento dado a Informacao
 */
No *criarNo(Informacao info);

/*
 * Função que destroi a lista de cada No
 */
void destroiListas(TabelaEspalhamento *tabela);

/*
 * Função que destroi a tabela de espalhamento
 */
void destroiTabela(TabelaEspalhamento *tabela);

#endif //LAB08_HASHTABLE_H
