# Guia de Apresentação — Fila e Relatório (G09)

**Responsável:** Gabriel Borba dos Santos  
**Grupo:** G09 · **Contexto:** Farmácia  
**Arquivo relacionado:** `sistema.c` (funções da fila, linhas ~38–122; relatório, linhas ~336–363)

---

## Antes de começar

Este guia cobre **só a sua parte**: fila circular e relatório ordenado. Outros colegas cuidam de pilha, lista e busca/ordenação.

| Estrutura | Papel no sistema |
|-----------|------------------|
| **Fila** | Quem será atendido agora (ordem de chegada + prioridade gestante) |
| **Lista** | Cadastro permanente — não some quando o cliente sai da fila |
| **Pilha (histórico)** | Quem já foi atendido — alimenta o relatório (opção 7) |

A fila usa **vetor circular** com `inicio` e `quantidade` (capacidade 11). A ordenação por senha no relatório chama `ordenar` (Luiz) — você mostra o **fluxo** da opção 7.

---

## Abertura sugerida

> "Fui responsável pela **fila de espera** e pelo **relatório ordenado**. A fila controla quem será atendido agora, com prioridade para gestantes. Quando o cliente é atendido, sai da fila e vai para o histórico do Vinicius."

---

## Ordem sugerida na apresentação

1. Contexto — fila vs lista vs pilha
2. `filaInicializar` / `filaVazia` / `filaCheia` — estrutura circular
3. `filaInserir` — opção 1 (cadastro)
4. `filaExibir` — opção 4
5. `filaRemover` — opção 2 (prioridade gestante)
6. `gerarRelatorio` — opção 7 (mencionar que Luiz explica o Bubble Sort)

---

## Funções — o que explicar

### `filaInicializar`

**Passo a passo:**

1. `inicio = 0`
2. `quantidade = 0`

**Frase de apoio:** "Fila vazia: nenhum cliente esperando."

---

### `filaVazia` / `filaCheia`

**Passo a passo:**

1. Vazia se `quantidade == 0`
2. Cheia se `quantidade == TAM_FILA` (11)

**Frase de apoio:** "Antes de inserir verificamos se cabe; antes de remover, se há alguém."

---

### `filaInserir`

**Quando roda:** opção 1 (cadastro), junto com `listaInserir` (Henrique).

**Passo a passo:**

1. Se cheia, retorna sem inserir
2. Calcula posição do fim: `(inicio + quantidade) % TAM_FILA`
3. Copia o cliente e incrementa `quantidade`

**Frase de apoio:** "Inserção no fim da fila circular — O(1) com vetor."

**Exemplo:** após cadastrar Maria (001), Joao (002), Ana (003), a fila exibe na ordem de chegada.

---

### `filaRemover`

**Quando roda:** opção 2 (chamar próximo cliente).

**Passo a passo:**

1. Se vazia, avisa e retorna cliente zerado
2. Percorre a fila procurando o **primeiro gestante** (`prioritario == 1`)
3. Se encontrou gestante no meio, remove deslocando elementos
4. Se não há gestante, remove o primeiro (FIFO normal)
5. Cliente removido vai para `pilhaEmpilhar` (Vinicius)

**Frase de apoio:** "Gestante na fila é atendida antes, mesmo que não seja a primeira da fila."

**Exemplo com gestantes:**

| Ordem na fila | Quem é atendido primeiro |
|---------------|--------------------------|
| Maria (normal), Joao (gestante), Ana (normal) | Joao |
| Maria, Ana, Carla (gestante) | Carla |

---

### `filaExibir`

**Quando roda:** opção 4.

**Passo a passo:**

1. Se vazia, mensagem
2. Percorre de `inicio` até `quantidade`, usando módulo `% TAM_FILA`
3. Exibe senha e nome

**Frase de apoio:** "Mostra quem está esperando, do primeiro ao último."

---

### `gerarRelatorio`

**Quando roda:** opção 7.

**Passo a passo:**

1. Se `n == 0`, avisa que não há histórico
2. Copia clientes do histórico para vetor auxiliar
3. Chama `ordenar` (Luiz) — imprime `"X trocas realizadas"`
4. Exibe clientes ordenados por senha

**Frase de apoio:** "O relatório ordena o histórico por senha. A contagem de trocas é o requisito único do G09 — Luiz detalha o trace."

**Integração:** peça ao Luiz para explicar as passagens do Bubble Sort enquanto você roda a opção 7.

---

## Demonstração no terminal

```
make && ./main

Opção 1 — cadastrar Maria (normal), Joao (gestante), Ana (normal)
Opção 4 — exibir fila (ordem de chegada)
Opção 2 — atender (Joao sai primeiro por ser gestante)
Opção 4 — fila atualizada
Opção 7 — relatório (após mais atendimentos, com Luiz)
Opção 0 — sair
```

---

## Perguntas do README / diário

### Questão 4 — Fila após 10 inserções e 5 remoções

**Cenário:** senhas 001 a 010 inseridas em ordem; 5 remoções **FIFO simples**, sem gestantes.

| Campo | Valor |
|-------|-------|
| Início da fila | Senha 006 |
| Fim da fila | Senha 010 |
| Vetor restante | 006, 007, 008, 009, 010 |

**Frase de apoio:** "`inicio` aponta para a senha 006; restam 5 clientes de 006 a 010."

**Atenção:** se houver gestantes, `filaRemover` muda a ordem — a questão 4 assume fila FIFO pura.

---

## FAQ / armadilhas

| Pergunta | Resposta |
|----------|----------|
| Fila é lista? | Não. Fila = espera; lista = cadastro permanente |
| O que é fila circular? | Vetor que reaproveita posições com `% TAM_FILA` |
| `gerarRelatorio` ordena a pilha? | Não altera a pilha; copia para vetor auxiliar e ordena a cópia |
| Quem explica Bubble Sort? | Luiz (`ordenar` + `TRACE-MANUAL.pdf`) |

---

## Checklist antes da apresentação

- [ ] Compilar: `make`
- [ ] Testar opções 1, 2, 4 e 7
- [ ] Saber explicar prioridade gestante com exemplo concreto
- [ ] Ter a resposta da questão 4 na ponta da língua
- [ ] Combinar com Luiz a divisão na opção 7 (você roda, ele explica trocas)
