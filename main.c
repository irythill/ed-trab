/*
 * ============================================================
 * TRABALHO PRÁTICO — Estrutura de Dados
 * Grupo: G09 | Contexto: Farmácia
 * ============================================================
 * Parâmetros do grupo:
 *   Capacidade máxima da fila  : 11
 *   Capacidade do histórico    : 3
 *   Algoritmo de ordenação     : Bubble Sort
 *   Algoritmo de busca         : Sequencial
 *   Tipo de prioridade         : Gestante (prioritario=1)
 *   Campo extra no cadastro    : char cpf[15]
 *   Questão 4 do Diário        : inserir 10, remover 5
 *
 * Requisito único: Relatório com contagem de trocas: ao ordenar, exibir quantas trocas o algoritmo realizou.
 * ============================================================
 *
 * TRACE MANUAL — (preencher aqui antes da entrega)
 * Algoritmo: Bubble Sort
 * Dados iniciais: [ preencher com senhas reais do contexto ]
 *
 * Passagem 1: ...
 * Passagem 2: ...
 * Resultado final: ...
 * ============================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_FILA 11
#define TAM_PILHA 3

/* ============================================================
 * DEFINIÇÃO DAS STRUCTS
 * ============================================================ */

/* Struct do cliente — adaptar conforme parâmetros do grupo */
typedef struct cliente {
    int senha;
    char nome[50];
    int prioritario;   /* 0 = normal, 1 = prioritário (Gestante (prioritario=1)) */
    char cpf[15];        /* campo extra do grupo */
} Cliente;

/* Nó da lista encadeada — mantém nomes 'dado' e 'prox' das aulas */
typedef struct no {
    Cliente dado;
    struct no *prox;
} No;

/* Fila implementada com vetor */
typedef struct {
    Cliente itens[TAM_FILA];
    int inicio;
    int quantidade;
} Fila;

/* Pilha implementada com vetor */
typedef struct {
    Cliente itens[TAM_PILHA];
    int topo;
} Pilha;


/* ============================================================
 * FUNÇÕES DA FILA
 * ============================================================ */

/* Inicializa a fila */
void filaInicializar(Fila *f) {
    f->inicio = 0;
    f->quantidade  = 0;
}

/* Retorna 1 se a fila estiver vazia, 0 caso contrário */
int filaVazia(Fila *f) {
    if (f->quantidade == 0)
        return 1;
    return 0;
}

/* Retorna 1 se a fila estiver cheia, 0 caso contrário */
int filaCheia(Fila *f) {
    if (f->quantidade == TAM_FILA)
        return 1;
    return 0;
}

/* Insere cliente na fila */
void filaInserir(Fila *f, Cliente c) {
    if (filaCheia(f))
            return;
    int fim = (f->inicio + f->quantidade) % TAM_FILA;
    f->itens[fim] = c;
    f->quantidade++;
}

/* Remove e retorna o primeiro cliente da fila */
Cliente filaRemover(Fila *f) {
    Cliente vazio = {0};

    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return vazio;
    }

    /* Encontra a posicao do primeiro prioritario */
    int posicaoRemover = 0;
    for (int i = 0; i < f->quantidade; i++) {
        int indice = (f->inicio + i) % TAM_FILA;
        if (f->itens[indice].prioritario == 1) {
            posicaoRemover = i;
            break;
        }
    }

    int indiceRemover = (f->inicio + posicaoRemover) % TAM_FILA;
    Cliente removido = f->itens[indiceRemover];

    /* Remove o primeiro */
    if (posicaoRemover == 0) {
        f->inicio = (f->inicio + 1) % TAM_FILA;
        f->quantidade--;
        return removido;
    }

    /* Remove do meio da fila */
    for (int i = posicaoRemover; i < f->quantidade - 1; i++) {
        int destino = (f->inicio + i) % TAM_FILA;
        int origem = (f->inicio + i + 1) % TAM_FILA;
        f->itens[destino] = f->itens[origem];
    }
    f->quantidade--;

    return removido;
}

/* Exibe o estado atual da fila */
void filaExibir(Fila *f) {
    if (filaVazia(f)){
        printf("A fila esta vazia.");
        return;
    }

    for (int i = 0; i < f -> quantidade; i++) {

        int posicao = (f->inicio + i) % TAM_FILA;

        printf("senha: %03d, nome: %s\n",
            f->itens[posicao].senha,
            f->itens[posicao].nome);
    }
}

/* ============================================================
 * FUNÇÕES DA PILHA (HISTÓRICO)
 * ============================================================ */

/* Inicializa a pilha */
void pilhaInicializar(Pilha *p) {
    p->topo = -1; //Inicializa pilha no vetor -1
}

/* Retorna 1 se a pilha estiver vazia, 0 caso contrário */
int pilhaVazia(Pilha *p) {

    if(p->topo == -1) //Se topo for -1 = pilha vazia
        return 1;
    else
        return 0;
}

/* Retorna 1 se a pilha estiver cheia, 0 caso contrário */
int pilhaCheia(Pilha *p) {

    if(p->topo == TAM_PILHA -1) // Se o topo for o mesmo valor do tamanho da pilha = cheia
        return 1;
    else
        return 0;
}

/* Empilha cliente no histórico */
void pilhaEmpilhar(Pilha *p, Cliente c) {
    /* G08: se cheia, descartar o mais antigo antes de empilhar */
    if (pilhaCheia(p)){
        printf("Pilha cheia, removendo o mais antigo e inserindo");
        for (int i = 0; i < TAM_PILHA - 1; i++) {
            p->itens[i] = p->itens[i+1]; //Move os elementos para esquerda
        }
        p->topo--; //Ajusta topo
    };

    p->topo++; //Reserva para o proximo cliente
    p->itens[p->topo] = c; // Insere novo cliente
}

/* Desempilha e retorna o topo */
Cliente pilhaDesempilhar(Pilha *p) {
    Cliente vazio = {0}; // Cria cliente vazio
    if(pilhaVazia(p)){
    return vazio;
    }

    Cliente removido = p->itens[p->topo]; //Zera as informações do indice(Itens)
    p->topo--; // Ajeita topo, elimina Cliente
    return removido;
}

/* Exibe o histórico de atendimentos */
void pilhaExibir(Pilha *p) {

    // Verifica se a pilha não está vazia
    if (pilhaVazia(p)) {
        printf("Historico vazio.\n");
        return;
    }

    for(int i = p->topo; i >= 0; i--) { //Percorre clientes
        printf("Senha: %03d , Nome: %s\n", p->itens[i].senha, p->itens[i].nome); //Exibe itens de clientes (senha e nome)
    }
}


/* ============================================================
 * FUNÇÕES DA LISTA ENCADEADA
 * ============================================================ */

/* Insere cliente na lista */
No* listaInserir(No *inicio, Cliente c) {
    No *noh = (No*)malloc(sizeof(No));
    if(noh == NULL) {
        printf("Erro ao alocar memoria. \n");
        return inicio;
    }
    noh->dado = c;
    noh->prox = NULL;

    /* Lista vazia */
    if (inicio == NULL) {
        return noh;
    }

    /* Insere no início */
    if (c.senha < inicio->dado.senha) {
        noh->prox = inicio;
        return noh;
    }

    /* Insere no meio ou no fim */
    No *anterior = inicio;
    No *atual = inicio->prox;

    while (atual != NULL && atual->dado.senha < c.senha) {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = noh;
    noh->prox = atual;
    return inicio;
}

/* Função auxiliar para copiar a lista para um vetor */
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
No* listaRemover(No *inicio, int senha) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return NULL;
    }

    Cliente vetor[TAM_FILA];
    int n = 0;
    listaParaVetor(inicio, vetor, &n);


    /* G10: usar busca binária antes de remover */
    int indice = buscaBinaria(vetor, n, senha); // chamar buscaBinaria, ainda nao implementada

    if (indice == -1) {
        printf("Senha %03d nao encontrada.\n", senha);
        return inicio;
    }

    /* Remove o nó na posição indice */
    if (indice == 0) {
        No *remover = inicio;
        inicio = inicio->prox;
        free(remover);
        return inicio;
    }

    No *anterior = inicio;
    for (int i = 0; i < indice - 1; i++) {
        anterior = anterior->prox;
    }

    No *remover = anterior->prox;
    anterior->prox = remover->prox;
    free(remover);
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
No* listaApagar(No *inicio) {
    No *atual = inicio;
    while (atual != NULL) {
        No *t = atual->prox;
        free(atual);
        atual = t;
    }
    return NULL;
}


/* ============================================================
 * ALGORITMO DE BUSCA — Sequencial
 * ============================================================ */

/*
 * IMPORTANTE: a busca binária exige que o vetor esteja ordenado.
 * Antes de chamar buscaBinaria(), ordenar o vetor com Bubble Sort.
 */

/* Busca sequencial por senha — percorre elemento a elemento */
int buscaSequencial(Cliente vet[], int n, int senha) {
    int comparacoes=0;
    for(int i=0; i < n; i++){
    comparacoes++;
    if (vet[i].senha== senha){
    printf("%d comparacoes feitas\n", comparacoes);
    return i;
    }
    }
    printf("%d comparacoes feitas\n", comparacoes);
    /* G02/G09: contar e exibir o número de comparações */
    return -1; /* retorna índice ou -1 se não encontrado */
}

/* Busca binária por senha — exige vetor ordenado */
int buscaBinaria(Cliente vet[], int n, int senha) {
    int low = 0, high = n - 1;
    /* TODO: implementar */
    while(low <=high){
    int mid = low+ (high - low)/2;
    if (vet[mid].senha == senha){
        return mid; //Encontrado
        }
        if(senha < vet[mid].senha){
        high = mid-1; //procura na esquerda
        }else{
        low= mid+1; //procura na direita
        }
    }
    return -1; //Não encontrado
}


/* ============================================================
 * ALGORITMO DE ORDENAÇÃO — Bubble Sort
 * ============================================================ */

/* Ordena vetor de clientes por número de senha (crescente) */
void ordenar(Cliente vet[], int n) {
    /*
     * TODO: implementar Bubble Sort
     *
     * G09: contar e retornar (ou exibir) o número de trocas
     * G10: implementar dois critérios (por senha e por nome)
     *      — use um parâmetro int criterio (0=senha, 1=nome)
     */
     int trocas= 0;
     Cliente temp;
     for( int i =0;i < n -1; i++){
         for(int j =0; j< n - 1; j++){

             if(vet[j].senha > vet[j + 1].senha){
                 temp = vet[j];
                 vet[j]= vet[j +1];
                 vet[j +1]= temp;

                 trocas++;
             }
         }
     }
     printf("%d trocas realizadas\n", trocas);
}


/* ============================================================
 * RELATÓRIO
 * ============================================================ */

/* Gera relatório de atendimentos ordenado */
void gerarRelatorio(Cliente historico[], int n) {
    // Valida se o topo do histórico é 0, se sim, significa estar vazio
    if (n == 0) {
        printf("Nao ha atendimentos no historico.\n");
        return;
    }
    // Copia os clientes da pilha para um vetor auxiliar
    Cliente aux[TAM_PILHA];

    for (int i = 0; i < n; i++) {
        aux[i] = historico[i];
    }

    // Ordena o vetor auxiliar
    ordenar(aux, n);

    // Exibir o vetor auxiliar ordenado
    for (int i = 0; i < n; i++) {
        printf("Senha: %03d | Nome: %s | CPF: %s | Prioritario: %s\n",
               aux[i].senha,
               aux[i].nome,
               aux[i].cpf,
               aux[i].prioritario == 1 ? "Sim" : "Nao");
    }
}


/* ============================================================
 * REQUISITO ÚNICO DO GRUPO G09
 * ============================================================ */

/*
 * Relatório com contagem de trocas: ao ordenar, exibir quantas trocas o algoritmo realizou.
 * TODO: implementar a função (ou funções) necessárias aqui.
 */


/* ============================================================
 * FUNÇÃO PRINCIPAL
 * ============================================================ */

int main() {
    Fila   fila;
    Pilha  historico;
    No    *lista   = NULL;
    int    opcao   = 0;
    int    proxSenha = 1;

    filaInicializar(&fila);
    pilhaInicializar(&historico);

    printf("=== Sistema de Atendimento — Farmácia ===\n\n");

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar novo cliente\n");
        printf("2. Chamar proximo cliente\n");
        printf("3. Buscar cliente\n");
        printf("4. Exibir fila atual\n");
        printf("5. Exibir historico (pilha)\n");
        printf("6. Exibir lista de clientes\n");
        printf("7. Gerar relatorio ordenado\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Cliente c = {0};
                c.senha = proxSenha++;
                printf("Nome: ");
                scanf(" %49s", c.nome);
                printf("Prioritario? (1=sim, 0=nao) [Gestante (prioritario=1)]: ");
                scanf("%d", &c.prioritario);
                printf("char cpf[15]: ");
                scanf(" %14s", c.cpf);

                filaInserir(&fila, c);
                lista = listaInserir(lista, c);
                printf("Cliente cadastrado. Senha: %03d\n", c.senha);
                break;
            }
            case 2: {
                if (filaVazia(&fila)) {
                    printf("Fila vazia.\n");
                } else {
                    Cliente atendido = filaRemover(&fila);
                    pilhaEmpilhar(&historico, atendido);
                    printf("Atendendo: %s (Senha %03d)\n",
                           atendido.nome, atendido.senha);
                }
                break;
            }
            case 3: {
                int senha;
                printf("Numero da senha: ");
                scanf("%d", &senha);

                Cliente vetor[TAM_FILA];
                int n;

                listaParaVetor(lista, vetor, &n);
                int indice = buscaSequencial(vetor,n,senha);

                if(indice !=-1){
                printf("Cliente encontrado:\n");
                printf("Senha:%d\n", vetor[indice].senha);
                printf("Nome:%s\n", vetor[indice].nome);
                printf("CPF:%s\n", vetor[indice].cpf);
                printf("Prioritario:%s\n", vetor[indice].prioritario ? "Sim":"Nao");
                }else{
                printf("Cliente nao encontrado");
                }
                break;
            }
            case 4: filaExibir(&fila);      break;
            case 5: pilhaExibir(&historico); break;
            case 6: listaExibir(lista);      break;
            case 7: gerarRelatorio(historico.itens, historico.topo + 1); break;
            case 0: printf("Encerrando...\n"); break;
            default: printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    lista = listaApagar(lista);
    return 0;
}
