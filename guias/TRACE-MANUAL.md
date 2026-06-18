# Trace Manual — Bubble Sort (G09)

**Responsável:** Luiz Henrique de Moraes Chagas  
**Grupo:** G09 · **Contexto:** Farmácia  
**Onde está no código:** cabeçalho de `sistema.c` + funções `ordenar` e `gerarRelatorio`

---

## Resumo em uma frase

O trace documenta **à mão** como o Bubble Sort ordena o **histórico de atendimentos** quando você gera o **relatório (opção 7)**, contando **2 trocas** no cenário de teste.

---

## O que é o trace manual

Rastreamento passo a passo do Bubble Sort:

- vetor **antes** da ordenação;
- cada passagem do `for` externo (`i`);
- cada comparação/troca do `for` interno (`j`);
- vetor **depois** e **total de trocas**.

É requisito do G09 exibir quantas trocas o algoritmo fez ao ordenar o relatório.

---

## Onde demonstrar no programa

| Opção | O que faz | Relação com o trace |
|-------|-----------|---------------------|
| **1** | Cadastra clientes | Monta fila e lista |
| **2** | Chama/atende | Empilha no histórico (pilha) |
| **5** | Exibe histórico | Mostra pilha **sem ordenar** (ordem de atendimento, topo → base) |
| **7** | Gera relatório | **`ordenar` roda aqui** → imprime `"X trocas realizadas"` |

**Opção 7** é a demonstração do trace. Opção 5 serve para mostrar o histórico **antes** de ordenar.

---

## O que o Bubble Sort ordena (e o que não ordena)

| Estrutura | Ordenada pelo Bubble Sort? |
|-----------|----------------------------|
| Lista encadeada (op. 6) | **Não** — cadastros na ordem de inserção (cabeça) |
| Fila (op. 4) | **Não** — ordem de atendimento |
| Histórico / pilha (op. 7) | **Sim** — copiado para vetor auxiliar em `gerarRelatorio` |

O Bubble Sort **só compara `senha`**. Prioridade (gestante) **não entra** na comparação — só influencia **quem foi atendido antes** (via fila).

---

## Cenário de teste

**5 cadastros** (opção 1), **3 atendimentos** (opção 2). Pedro (005) e Ana (003) ficam na fila, não entram no histórico (pilha cap. 3).

| # | Nome  | Senha | Gestante | Entra no histórico? |
|---|-------|-------|----------|---------------------|
| 1 | Maria | 001   | Não      | Sim (3º atendido)   |
| 2 | Joao  | 002   | Sim      | Sim (1º atendido)   |
| 3 | Ana   | 003   | Não      | Não (fica na fila)  |
| 4 | Carla | 004   | Sim      | Sim (2º atendido)   |
| 5 | Pedro | 005   | Não      | Não (fica na fila)  |

### Ordem de atendimento (opção 2)

Fila após 4 cadastros: Maria → Joao → Ana → Carla.  
Com prioridade gestante, atendem-se: **Joao (002) → Carla (004) → Maria (001)**.

### Opção 5 — histórico na pilha (topo primeiro)

```
Senha: 001  Maria   ← último atendido (topo)
Senha: 004  Carla
Senha: 002  Joao    ← primeiro atendido (base)
```

### Opção 7 — vetor antes do `ordenar`

Ordem de inserção na pilha: `[002 Joao, 004 Carla, 001 Maria]`

---

## Passagens do trace (Bubble Sort)

**Dados iniciais:** `[002, 004, 001]`

### Passagem 1 (`i = 0`)

| `j` | Comparação | Troca? | Vetor após |
|-----|------------|--------|------------|
| 0   | 002 > 004? Não | — | `[002, 004, 001]` |
| 1   | 004 > 001? Sim | Sim | `[002, 001, 004]` |

### Passagem 2 (`i = 1`)

| `j` | Comparação | Troca? | Vetor após |
|-----|------------|--------|------------|
| 0   | 002 > 001? Sim | Sim | `[001, 002, 004]` |
| 1   | 002 > 004? Não | — | `[001, 002, 004]` |

### Resultado

- **Vetor final:** `[001 Maria, 002 Joao, 004 Carla]`
- **Total de trocas:** **2** (programa imprime `2 trocas realizadas`)

---

## Como explicar na apresentação

1. Mostre opção **5** — histórico na ordem de atendimento (não ordenado por senha)
2. Rode opção **7** — Gabriel chama `gerarRelatorio`, você narra o trace
3. Aponte a linha `2 trocas realizadas` no terminal
4. Compare com as tabelas deste documento

**Frase de apoio:**

> "A prioridade define quem entra no histórico e em que ordem. O Bubble Sort do relatório compara só senha e conta as trocas — requisito único do G09."

---

## Checklist

- [ ] Montar cenário (5 cadastros, 3 atendimentos) antes da apresentação
- [ ] Opção 5 vs opção 7 — saber a diferença
- [ ] Saber de cor: op. 7 = Bubble Sort + contagem de trocas = **2** no cenário padrão
- [ ] Ter este PDF junto com `luiz-busca-ordenacao.pdf`
