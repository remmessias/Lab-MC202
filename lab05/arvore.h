#ifndef LAB05_ARVORE_H
#define LAB05_ARVORE_H

typedef char String[20];

typedef struct NoArvore {
	struct NoArvore *esquerda;
	struct NoArvore *direita;
	String arquivo;
} NoArvore;

typedef struct Arvore {
	NoArvore *raiz;
} Arvore;

Arvore *criarArvore();

NoArvore *criarNo();

int alturaNo(NoArvore *no);

int arv_vazia(NoArvore* a);

int fatorBalanceamento(NoArvore *no);

NoArvore *girarEsquerdaEsquerda(NoArvore *no);

NoArvore *girarEsquerdaDireita(NoArvore *no);

NoArvore *girarDireitaEsquerda(NoArvore *no);

NoArvore *girarDireitaDireita(NoArvore *no);

NoArvore *balancearNo(NoArvore *no);

void balancear(Arvore *arvore);

void inserir(Arvore *arvore, String arquivo);

void remover(Arvore *arvore, String chave);

void remover_caso1(NoArvore **no);

void remover_caso2(NoArvore *no);

NoArvore *procurar(Arvore *arvore, String arquivo);

void buscaProfundidade(NoArvore *no, int profundidade);

void destroi(Arvore *arvore);

void destroiNo (NoArvore* no);

#endif
