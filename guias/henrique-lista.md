# Guia de Apresentação — Lista Encadeada (G09)

**Responsável:** Henrique De Souza Pereira  
**Grupo:** G09 · **Contexto:** Farmácia  
**Arquivo relacionado:** `sistema.c` (funções da lista, linhas ~184–270)

---

## Antes de começar

Este guia cobre **só a sua parte**: lista encadeada. Outros colegas cuidam de fila, pilha, busca e relatório.

| Estrutura | Papel no sistema |
|-----------|------------------|
| **Fila** | Quem será atendido agora (ordem de chegada + prioridade gestante) |
| **Lista** | Cadastro permanente — não some quando o cliente sai da fila |
| **Pilha (histórico)** | Quem já foi atendido — usada na opção 7 (Bubble Sort) |

A **lista não é ordenada por senha**. Inserimos na cabeça. Ordenação por senha acontece só no **relatório (opção 7)** — veja `TRACE-MANUAL.pdf` (Luiz).

---

## Abertura sugerida

> "Fui responsável pela **lista encadeada** — o cadastro permanente dos clientes da farmácia. A **fila** controla quem será atendido agora; a **lista** guarda todos os cadastros na ordem em que foram inseridos."

---

## Ordem sugerida na apresentação

1. Contexto — lista vs fila
2. `listaInserir` — inserção na cabeça com `malloc`
3. `listaParaVetor` — lista → vetor (opção 3)
4. `listaExibir` — opção 6
5. `listaApagar` — liberação ao sair (opção 0)
6. Leitura do CPF no case 1 (`main.c`)

**Não precisa apresentar `listaRemover` no menu** — a função existe no código (crédito no README), mas **não há opção** que a chame. Remover só da lista deixaria o cliente na fila (estado inconsistente).

---

## Funções — o que explicar

### `listaInserir`

**Quando roda:** opção 1 (cadastrar).

**Passo a passo:**

1. Aloca nó com `malloc` (se falhar, retorna a lista intacta)
2. Copia o cliente para `noh->dado`
3. `noh->prox = inicio` — novo nó vira a cabeça
4. Retorna o novo início

**Frase de apoio:** "Inserção na cabeça, constante. Ordenar por senha é trabalho do relatório, opção 7."

**Exemplo — três cadastros (questão 6 do README):**

| Passo | Lista após inserir |
|-------|-------------------|
| Maria (001) | `[001 Maria] → NULL` |
| Joao (002) | `[002 Joao] → [001 Maria] → NULL` |
| Ana (003) | `[003 Ana] → [002 Joao] → [001 Maria] → NULL` |

---

### `listaParaVetor`

**Quando roda:** opção 3 (busca) — sua contribuição direta na integração com Luiz.

**Passo a passo:**

1. Zera `*n`
2. Percorre a lista com `atual`
3. Copia cada `dado` para `vet[0]`, `vet[1]`, ...
4. `*n` = total de clientes

**Frase de apoio:** "A busca sequencial trabalha em vetor; eu copio a lista antes."

**Exemplo:** com 3 cadastros, o vetor fica `[003 Ana, 002 Joao, 001 Maria]` (mesma ordem da lista).

---

### `listaExibir`

**Quando roda:** opção 6.

**Passo a passo:**

1. Se `inicio == NULL`, lista vazia
2. Percorre do início ao fim
3. Exibe senha, nome, CPF e prioritário

**Frase de apoio:** "Do mais recente para o mais antigo — porque inserimos na cabeça."

---

### `listaApagar`

**Quando roda:** opção 0 (sair).

**Passo a passo:**

1. Percorre liberando cada nó com `free`
2. Retorna `NULL`

**Frase de apoio:** "Evita vazamento de memória ao encerrar o programa."

---

## Demonstração no terminal

```
make && ./main

Opção 1 — Maria, 0, CPF 689.804.440-01
Opção 1 — Joao,  1, CPF 495.575.710-39
Opção 1 — Ana,   0, CPF 581.754.040-19
Opção 6 — exibir lista (ordem 003, 002, 001)
Opção 3 — buscar senha 002 (Luiz explica comparações; você menciona listaParaVetor)
Opção 0 — sair (listaApagar)
```

---

## Perguntas do README / diário

### Questão 6 — Três primeiras inserções

| Cadastro | Cliente | Estado da lista |
|----------|---------|-----------------|
| 1 | Maria (001, normal) | `[001 Maria] → NULL` |
| 2 | Joao (002, gestante) | `[002 Joao] → [001 Maria] → NULL` |
| 3 | Ana (003, normal) | `[003 Ana] → [002 Joao] → [001 Maria] → NULL` |

A lista exibe do **mais recente** para o **mais antigo**.

---

## FAQ / armadilhas

| Pergunta | Resposta |
|----------|----------|
| Lista é ordenada por senha? | Não — inserção na cabeça |
| Por que `listaParaVetor`? | Busca sequencial precisa de vetor |
| Apresento `listaRemover`? | Não — não está no menu |
| `malloc` falhou? | Erro no terminal; lista não muda |

---

## Checklist antes da apresentação

- [ ] Compilar: `make`
- [ ] Testar opções 1, 3, 6 e 0
- [ ] Saber explicar lista vs fila em uma frase
- [ ] Ter o exemplo da questão 6 do README na ponta da língua
- [ ] Combinar com Luiz na opção 3 (você: vetor; ele: comparações)
