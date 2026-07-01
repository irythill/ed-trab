/*
 * Trabalho Prático — Estrutura de Dados
 * Grupo G09 | Farmácia
 *
 * TRACE MANUAL — Bubble Sort (ordenar por senha crescente)
 * Contexto: histórico de atendimentos da farmácia (opção 7)
 *
 * Cadastros realizados:
 *   001 Maria  (normal)   | CPF 689.804.440-01
 *   002 Joao   (gestante) | CPF 495.575.710-39
 *   003 Ana    (normal)   | CPF 581.754.040-19
 *   004 Carla  (gestante) | CPF 658.347.180-94
 *   005 Pedro  (normal)   | CPF 107.045.120-76
 *
 * Atendimentos (opção 2) — prioridade de gestante altera a ordem:
 *   1º Joao (002) → 2º Carla (004) → 3º Maria (001)
 *
 * Dados iniciais: [002 Joao, 004 Carla, 001 Maria]
 *
 * Passagem 1 (i=0):
 *   j=0: 002 > 004? Nao  → [002, 004, 001]
 *   j=1: 004 > 001? Sim  → [002, 001, 004]
 *
 * Passagem 2 (i=1):
 *   j=0: 002 > 001? Sim  → [001, 002, 004]
 *   j=1: 002 > 004? Nao  → [001, 002, 004]
 *
 * Resultado final: [001 Maria, 002 Joao, 004 Carla]
 * Total de trocas: 2
 */

#include "sistema.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ============================================================
 * FUNÇÕES DA FILA
 * ============================================================ */

/* Inicializa a fila */
void filaInicializar(Fila *f) {
    f->inicio = 0;
    f->quantidade = 0;
}

/* Retorna 1 se a fila estiver vazia, 0 caso contrário */
int filaVazia(Fila *f) {
    return f->quantidade == 0;
}

/* Retorna 1 se a fila estiver cheia, 0 caso contrário */
int filaCheia(Fila *f) {
    return f->quantidade == TAM_FILA;
}

/* Insere cliente na fila */
void filaInserir(Fila *f, Cliente c) {
    // Verifica se a fila está cheia.
    if (filaCheia(f)) {
        return;
    }

    // Calcula a próxima posição livre da fila.
    int fim = (f->inicio + f->quantidade) % TAM_FILA;
    // Vetor itens recebe cliente na posição fim.
    f->itens[fim] = c;
    // Incremente a quantidade de elementos na fila.
    f->quantidade++;
}

/* Remove e retorna o primeiro cliente da fila (prioridade gestante) */
Cliente filaRemover(Fila *f) {
    // Cria variável vazia.
    Cliente vazio = {0};

    // Verifica se a fila está vazia.
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return vazio;
    }

    /* Encontra a posição do primeiro prioritário */
    int posicaoRemover = 0;
    for (int i = 0; i < f->quantidade; i++) {
        // Captura posição do vetor que corresponde o loop
        int indice = (f->inicio + i) % TAM_FILA;
        // Se for priorioritário salva a posição na fila
        if (f->itens[indice].prioritario == 1) {
            posicaoRemover = i;
            break;
        }
    }

    // Captura a posição no vetor do elemento a ser removido.
    int indiceRemover = (f->inicio + posicaoRemover) % TAM_FILA;
    // Pega o cliente que será removido.
    Cliente removido = f->itens[indiceRemover];

    // Excessão caso seja o primeiro da fila.
    if (posicaoRemover == 0) {
        // Avança o início da fila.
        f->inicio = (f->inicio + 1) % TAM_FILA;
        // Decrementa a quantidade de elementos na fila.
        f->quantidade--;
        // Retorna o cliente.
        return removido;
    }

    // Percorre a fila a partir do elemento que será removido
    // Até o penúltimo elemento.
    for (int i = posicaoRemover; i < f->quantidade - 1; i++) {
        int destino = (f->inicio + i) % TAM_FILA;
        int origem = (f->inicio + i + 1) % TAM_FILA;
        // Move o elemento de destino pra orgem.
        f->itens[destino] = f->itens[origem];
    }
    // Decrementa a quantidade de elementos na fila.
    f->quantidade--;

    // Retorna o cliente removido.
    return removido;
}

/* Exibe o estado atual da fila */
void filaExibir(Fila *f) {
    // Verifica se a fila está vazia.
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("--- Fila de espera ---\n");
    // Percorre a quantidade de elementos 
    for (int i = 0; i < f->quantidade; i++) {
        // Captura posição real do vetor
        int posicao = (f->inicio + i) % TAM_FILA
        printf("Senha: %03d | Nome: %s\n",
               f->itens[posicao].senha,
               f->itens[posicao].nome);
    }
}

/* ============================================================
 * FUNÇÕES DA PILHA (HISTÓRICO)
 * ============================================================ */

/* Inicializa a pilha */
void pilhaInicializar(Pilha *p) {
    p->topo = -1;
}

/* Retorna 1 se a pilha estiver vazia, 0 caso contrário */
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

/* Retorna 1 se a pilha estiver cheia, 0 caso contrário */
int pilhaCheia(Pilha *p) {
    return p->topo == TAM_PILHA - 1;
}

/* Empilha cliente no histórico */
void pilhaEmpilhar(Pilha *p, Cliente c) {
    /* Remove o mais antigo se a pilha estiver cheia */
    if (pilhaCheia(p)) {
        printf("Historico cheio. Removendo o atendimento mais antigo.\n");
        for (int i = 0; i < TAM_PILHA - 1; i++) {
            p->itens[i] = p->itens[i + 1];
        }
        p->topo--;
    }

    p->topo++;
    p->itens[p->topo] = c;
}

/* Desempilha e retorna o topo */
Cliente pilhaDesempilhar(Pilha *p) {
    Cliente vazio = {0};

    if (pilhaVazia(p)) {
        return vazio;
    }

    Cliente removido = p->itens[p->topo];
    p->topo--;
    return removido;
}

/* Exibe o histórico de atendimentos */
void pilhaExibir(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Historico vazio.\n");
        return;
    }

    printf("--- Historico ---\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("Senha: %03d | Nome: %s\n", p->itens[i].senha, p->itens[i].nome);
    }
}

/* ============================================================
 * FUNÇÕES DA LISTA ENCADEADA
 * ============================================================ */

/* Insere cliente na cabeça da lista */
No *listaInserir(No *inicio, Cliente c) {
    No *noh = (No *)malloc(sizeof(No));
    if (noh == NULL) {
        printf("Erro ao alocar memoria.\n");
        return inicio;
    }

    noh->dado = c;
    noh->prox = inicio;
    return noh;
}

/* Copia a lista encadeada para um vetor */
void listaParaVetor(No *inicio, Cliente vet[], int *n) {
    *n = 0;
    No *atual = inicio;

    while (atual != NULL) {
        vet[*n] = atual->dado;
        (*n)++;
        atual = atual->prox;
    }
}

/* Remove cliente da lista pelo número da senha */
No *listaRemover(No *inicio, int senha) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    if (inicio->dado.senha == senha) {
        No *remover = inicio;
        inicio = inicio->prox;
        free(remover);
        return inicio;
    }

    No *anterior = inicio;
    while (anterior->prox != NULL) {
        if (anterior->prox->dado.senha == senha) {
            No *remover = anterior->prox;
            anterior->prox = remover->prox;
            free(remover);
            return inicio;
        }
        anterior = anterior->prox;
    }

    printf("Senha %03d nao encontrada.\n", senha);
    return inicio;
}

/* Exibe todos os clientes da lista */
void listaExibir(No *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("--- Clientes cadastrados ---\n");
    No *atual = inicio;
    while (atual != NULL) {
        printf("Senha: %03d | Nome: %s | CPF: %s | Prioritario: %s\n",
               atual->dado.senha,
               atual->dado.nome,
               atual->dado.cpf,
               atual->dado.prioritario == 1 ? "Sim" : "Nao");
        atual = atual->prox;
    }
}

/* Libera toda a memória da lista */
No *listaApagar(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        No *t = atual->prox;
        free(atual);
        atual = t;
    }
    return NULL;
}

/* ============================================================
 * ALGORITMO DE BUSCA
 * ============================================================ */

/* Busca sequencial por senha — percorre elemento a elemento */
int buscaSequencial(Cliente vet[], int n, int senha) {
    int comparacoes = 0;

    for (int i = 0; i < n; i++) {
        comparacoes++;
        if (vet[i].senha == senha) {
            printf("%d comparacoes feitas\n", comparacoes);
            return i;
        }
    }

    printf("%d comparacoes feitas\n", comparacoes);
    return -1;
}

/* Busca binária por senha — exige vetor ordenado */
int buscaBinaria(Cliente vet[], int n, int senha) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vet[mid].senha == senha) {
            return mid;
        }
        if (senha < vet[mid].senha) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

/* ============================================================
 * ALGORITMO DE ORDENAÇÃO — Bubble Sort
 * ============================================================ */

/* Ordena vetor de clientes por número de senha (crescente) */
void ordenar(Cliente vet[], int n) {
    int trocas = 0;
    Cliente temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (vet[j].senha > vet[j + 1].senha) {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
                trocas++;
            }
        }
    }

    printf("%d trocas realizadas\n", trocas);
}

/* ============================================================
 * RELATÓRIO
 * ============================================================ */

/* Gera relatório de atendimentos ordenado por senha */
void gerarRelatorio(Cliente historico[], int n) {
    if (n == 0) {
        printf("Nao ha atendimentos no historico.\n");
        return;
    }

    // Cria um vetor auxiliar.
    Cliente aux[TAM_PILHA];

    // Copia o histórico para o vetor auxiliar.
    for (int i = 0; i < n; i++) {
        aux[i] = historico[i];
    }

    printf("--- Relatorio ordenado ---\n");
    // Ordena o vetor auxiliar por senha.
    ordenar(aux, n);

    // Percorre o vetor ordenado e mostra os dados do clientes.
    for (int i = 0; i < n; i++) {
        printf("Senha: %03d | Nome: %s | CPF: %s | Prioritario: %s\n",
               aux[i].senha,
               aux[i].nome,
               aux[i].cpf,
               aux[i].prioritario == 1 ? "Sim" : "Nao");
    }
}
