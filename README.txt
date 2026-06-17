============================================================
TRABALHO PRÁTICO — Estrutura de Dados
Grupo: G09 | Contexto: Farmácia
============================================================

1. Quem implementou cada função?

Gabriel Borba dos Santos:
- filaCheia
- filaVazia
- filaInserir
- filaRemover
- filaExibir

Henrique De Souza Pereira:
- listaInserir
- listaRemover
- listaExibir
- listaParaVetor

Luiz Henrique de Moraes Chagas:
- buscaSequencial
- buscaBinaria
- ordenação(Bubble Sort)
- Buscar Cliente

Vinicius Dos Santos Cardoso:
- pilhaInicializar
- pilhaVazia
- pilhaCheia
- pilhaEmpilhar
- pilhaDesempilhar
- pilhaExibir

2. Qual foi a maior dificuldade? Como resolveram?

3. Por que o algoritmo de busca sequencial e o algoritmo Bubble Sort para ordenação é adequado (ou não) para o contexto
escolhido?
São considerados adequados por causa do sistema ter uma quantidade pequena de clientes e registros no histórico.

4. Qual é o valor de inicio e final da fila após inserir 10 elementos e remover 5? Mostre o estado do vetor.

4)  Início da fila = Senha 006
    Fim da fila    = Senha 010

4)  Estado do vetor após a remoção:
    Senha : 006  007  008  009  010

5. O algoritmo de ordenação do grupo é estável? Isso importa no contexto escolhido? Justifique.
O algoritmo é estável mas não influencia o funcionamento do sistema, porque cada cliente vai ter uma senha única. Como não vai ter senha repetida, não é necessário manter a ordem entre elementos iguais.

6. Demonstre o estado da lista encadeada após as três primeiras inserções com dados reais do contexto:
Cada cadastro (opção 1) insere o cliente na cabeça da lista com listaInserir().

Cadastro 1:
    Cliente: Maria | Senha: 001 | Prioritario: Nao | CPF: 689.804.440-01
    Estado da lista: lista → [001 Maria] → NULL

Cadastro 2:
    Cliente: Joao  | Senha: 002 | Prioritario: Sim (gestante) | CPF: 495.575.710-39
    Estado da lista: lista → [002 Joao] → [001 Maria] → NULL

Cadastro 3:
    Cliente: Ana   | Senha: 003 | Prioritario: Nao | CPF: 581.754.040-19
    Estado da lista: lista → [003 Ana] → [002 Joao] → [001 Maria] → NULL

A lista exibe os cadastros do mais recente para o mais antigo (inserção na cabeça).
