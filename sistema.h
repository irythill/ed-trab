/*
 * Trabalho Prático — Estrutura de Dados
 * Grupo G09 | Farmácia
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#define TAM_FILA 11
#define TAM_PILHA 3

typedef struct cliente {
    int senha;
    char nome[50];
    int prioritario; /* 0 = normal, 1 = gestante */
    char cpf[15];
} Cliente;

typedef struct no {
    Cliente dado;
    struct no *prox;
} No;

typedef struct {
    Cliente itens[TAM_FILA];
    int inicio;
    int quantidade;
} Fila;

typedef struct {
    Cliente itens[TAM_PILHA];
    int topo;
} Pilha;

/* Fila */
void filaInicializar(Fila *f);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
void filaInserir(Fila *f, Cliente c);
Cliente filaRemover(Fila *f);
void filaExibir(Fila *f);

/* Pilha */
void pilhaInicializar(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
void pilhaEmpilhar(Pilha *p, Cliente c);
Cliente pilhaDesempilhar(Pilha *p);
void pilhaExibir(Pilha *p);

/* Lista encadeada */
No *listaInserir(No *inicio, Cliente c);
void listaParaVetor(No *inicio, Cliente vet[], int *n);
No *listaRemover(No *inicio, int senha);
void listaExibir(No *inicio);
No *listaApagar(No *inicio);

/* Busca e ordenação */
int buscaSequencial(Cliente vet[], int n, int senha);
int buscaBinaria(Cliente vet[], int n, int senha);
void ordenar(Cliente vet[], int n);

/* Relatório */
void gerarRelatorio(Cliente historico[], int n);

#endif
