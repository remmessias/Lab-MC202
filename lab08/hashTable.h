#ifndef LAB08_HASHTABLE_H
#define LAB08_HASHTABLE_H

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

void inserirHash(Informacao info, TabelaEspalhamento *tabela);

int codifica(String palavra, int tam);

No *criarNo(Informacao info);

void destroiListas(TabelaEspalhamento *tabela);

void destroiTabela(TabelaEspalhamento *tabela);

#endif //LAB08_HASHTABLE_H
