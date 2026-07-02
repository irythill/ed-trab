============================================================
TRABALHO PRÁTICO — Estrutura de Dados
Grupo: G09 | Contexto: Farmácia
============================================================

Compilação:
    make
    ou: gcc -Wall -std=c99 -o main main.c sistema.c

Arquivos do projeto:
    main.c      — menu e função main
    sistema.c   — implementações (fila, pilha, lista, busca, ordenação, relatório)
    sistema.h   — structs e protótipos

============================================================

1. Quem implementou cada função?

Gabriel Borba dos Santos:
    - filaInicializar
    - filaVazia
    - filaCheia
    - filaInserir
    - filaRemover
    - filaExibir
    - gerarRelatorio

Henrique De Souza Pereira:
    - listaInserir
    - listaRemover
    - listaExibir
    - listaParaVetor
    - listaApagar

Luiz Henrique de Moraes Chagas:
    - buscaSequencial
    - buscaBinaria
    - ordenar

Vinicius Dos Santos Cardoso:
    - pilhaInicializar
    - pilhaVazia
    - pilhaCheia
    - pilhaEmpilhar
    - pilhaDesempilhar
    - pilhaExibir

2. Qual foi a maior dificuldade? Como resolveram?

    A maior dificuldade foi pensar em como fazer a listaParaVetor, principalmente
    pra entender que a gente tava copiando todos os dados da struct pra um vetor.
    Depois que isso ficou claro, foi bem mais tranquilo montar a lógica e fazer
    a conversão funcionar no sistema.

3. Por que o algoritmo de busca sequencial e o algoritmo Bubble Sort
   para ordenação é adequado (ou não) para o contexto escolhido?

   São considerados adequados porque o sistema lida com volumes pequenos:
   a fila comporta no máximo 11 clientes e o histórico guarda apenas 3
   atendimentos, o que é compatível com o fluxo de uma farmácia.

4. Qual é o valor de inicio e final da fila após inserir 10 elementos
   e remover 5? Mostre o estado do vetor.

   Cenário: inserções sequenciais (senhas 001 a 010) e remoções FIFO
   simples, sem clientes prioritários na fila.

   Início da fila = Senha 006
   Fim da fila    = Senha 010

   Estado do vetor após a remoção:
   Senha: 006  007  008  009  010

5. O algoritmo de ordenação do grupo é estável? Isso importa no contexto
   escolhido? Justifique.

   O algoritmo é estável, mas não influencia o funcionamento do sistema,
   porque cada cliente possui uma senha única. Como não há senhas repetidas,
   não é necessário manter a ordem entre elementos iguais.

6. Demonstre o estado da lista encadeada após as três primeiras inserções
   com dados reais do contexto:

   Cada cadastro (opção 1) insere o cliente na cabeça da lista com
   listaInserir().

   Cadastro 1:
       Cliente: Maria | Senha: 001 | Prioritario: Nao | CPF: 689.804.440-01
       Estado da lista: lista → [001 Maria] → NULL

   Cadastro 2:
       Cliente: Joao  | Senha: 002 | Prioritario: Sim (gestante) | CPF: 495.575.710-39
       Estado da lista: lista → [002 Joao] → [001 Maria] → NULL

   Cadastro 3:
       Cliente: Ana   | Senha: 003 | Prioritario: Nao | CPF: 581.754.040-19
       Estado da lista: lista → [003 Ana] → [002 Joao] → [001 Maria] → NULL

   A lista exibe os cadastros do mais recente para o mais antigo
   (inserção na cabeça).
