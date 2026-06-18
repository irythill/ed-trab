/*
 * Trabalho Prático — Estrutura de Dados
 * Grupo G09 | Farmácia
 */

#include "sistema.h"

#include <stdio.h>

static void exibirBanner(void) {
    printf("\n");
    printf("        +-------------------------------------+\n");
    printf("        |      Rx  FARMACIA G09  Rx           |\n");
    printf("        |   Sistema de Atendimento ao         |\n");
    printf("        |            Cliente                  |\n");
    printf("        +-------------------------------------+\n");
    printf("\n");
}

static void exibirMenu(void) {
    printf("\n");
    printf("+======================================+\n");
    printf("|            MENU PRINCIPAL            |\n");
    printf("+======================================+\n");
    printf("|  1. Cadastrar novo cliente           |\n");
    printf("|  2. Chamar proximo cliente           |\n");
    printf("|  3. Buscar cliente                   |\n");
    printf("|  4. Exibir fila atual                |\n");
    printf("|  5. Exibir historico (pilha)         |\n");
    printf("|  6. Exibir lista de clientes         |\n");
    printf("|  7. Gerar relatorio ordenado         |\n");
    printf("|  0. Sair                             |\n");
    printf("+======================================+\n");
    printf("Opcao: ");
}

int main(void) {
    Fila fila;
    Pilha historico;
    No *lista = NULL;
    int opcao = 0;
    int proxSenha = 1;

    filaInicializar(&fila);
    pilhaInicializar(&historico);
    exibirBanner();

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Cliente c = {0};
                c.senha = proxSenha++;
                printf("Nome: ");
                scanf(" %49s", c.nome);
                printf("Prioritario? (1=sim, 0=nao) [Gestante]: ");
                scanf("%d", &c.prioritario);
                printf("CPF: ");
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
                int indice = buscaSequencial(vetor, n, senha);

                if (indice != -1) {
                    printf("--- Cliente encontrado ---\n");
                    printf("Senha: %03d | Nome: %s | CPF: %s | Prioritario: %s\n",
                           vetor[indice].senha,
                           vetor[indice].nome,
                           vetor[indice].cpf,
                           vetor[indice].prioritario ? "Sim" : "Nao");
                } else {
                    printf("Cliente nao encontrado.\n");
                }
                break;
            }
            case 4:
                filaExibir(&fila);
                break;
            case 5:
                pilhaExibir(&historico);
                break;
            case 6:
                listaExibir(lista);
                break;
            case 7:
                gerarRelatorio(historico.itens, historico.topo + 1);
                break;
            case 0:
                printf("Obrigado! Volte sempre.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    lista = listaApagar(lista);
    return 0;
}
