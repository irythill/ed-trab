# Guia de Apresentação — Pilha / Histórico (G09)

**Responsável:** Vinicius Dos Santos Cardoso  
**Grupo:** G09 · **Contexto:** Farmácia  
**Arquivo relacionado:** `sistema.c` (funções da pilha, linhas ~124–182)

---

## Antes de começar

Este guia cobre **só a sua parte**: pilha (histórico de atendimentos). Outros colegas cuidam de fila, lista, busca e relatório.

| Estrutura | Papel no sistema |
|-----------|------------------|
| **Fila** | Quem espera atendimento agora |
| **Lista** | Cadastro permanente de todos os clientes |
| **Pilha (histórico)** | Quem **já foi atendido** — cap. 3, usada na opção 7 |

Quando Gabriel remove alguém da fila (opção 2), você **empilha** esse cliente no histórico.

---

## Abertura sugerida

> "Fui responsável pela **pilha** — o histórico de atendimentos da farmácia. Cada vez que um cliente é atendido, ele sai da fila e entra no topo do histórico. Guardamos só os últimos 3 atendimentos."

---

## Ordem sugerida na apresentação

1. Contexto — pilha vs fila vs lista
2. `pilhaInicializar` / `pilhaVazia` / `pilhaCheia`
3. `pilhaEmpilhar` — opção 2 (após `filaRemover`)
4. Comportamento quando cheia (descartar o mais antigo)
5. `pilhaExibir` — opção 5

**Não apresentar `pilhaDesempilhar`** — implementada, mas o menu não a utiliza.

---

## Funções — o que explicar

### `pilhaInicializar`

**Passo a passo:**

1. `topo = -1` (pilha vazia)

**Frase de apoio:** "Topo -1 significa que não há nenhum atendimento registrado."

---

### `pilhaVazia` / `pilhaCheia`

**Passo a passo:**

1. Vazia se `topo == -1`
2. Cheia se `topo == TAM_PILHA - 1` (índice 2, ou seja, 3 elementos)

**Frase de apoio:** "Histórico comporta no máximo 3 atendimentos — parâmetro do G09."

---

### `pilhaEmpilhar`

**Quando roda:** opção 2, logo após `filaRemover` (Gabriel).

**Passo a passo:**

1. Se cheia, remove o **mais antigo** (base): desloca elementos para a esquerda
2. Incrementa `topo`
3. Insere o novo cliente no topo

**Frase de apoio:** "Pilha cheia descarta o atendimento mais antigo — farmácia só precisa dos últimos 3."

**Exemplo — 4 atendimentos seguidos:**

| Atendimento | Topo (último) | Base (mais antigo) |
|-------------|---------------|---------------------|
| 1º Joao | Joao | Joao |
| 2º Carla | Carla | Joao |
| 3º Maria | Maria | Joao |
| 4º Pedro | Pedro | Carla (Joao descartado) |

---

### `pilhaExibir`

**Quando roda:** opção 5.

**Passo a passo:**

1. Se vazia, mensagem
2. Percorre de `topo` até `0` (do mais recente ao mais antigo)
3. Exibe senha e nome

**Frase de apoio:** "Opção 5 mostra o histórico **sem ordenar** — ordem de atendimento. Ordenação só na opção 7."

**Exemplo após 3 atendimentos (Joao, Carla, Maria):**

```
Senha: 001  Maria   ← último atendido (topo)
Senha: 004  Carla
Senha: 002  Joao    ← primeiro atendido (base)
```

---

## Demonstração no terminal

```
make && ./main

Opção 1 — cadastrar 3+ clientes (Gabriel/Henrique)
Opção 2 — atender 3 vezes (você: empilha; Gabriel: remove da fila)
Opção 5 — exibir histórico (topo → base)
Opção 2 — atender mais um (4º) — mostrar mensagem de histórico cheio
Opção 5 — confirmar que o mais antigo sumiu
```

---

## Integração com outros módulos

| Opção | Sua função | Colega |
|-------|------------|--------|
| 2 | `pilhaEmpilhar` | Gabriel (`filaRemover`) |
| 5 | `pilhaExibir` | — |
| 7 | histórico lido por `gerarRelatorio` | Gabriel + Luiz |

---

## FAQ / armadilhas

| Pergunta | Resposta |
|----------|----------|
| Pilha ordena por senha? | Não — ordem de atendimento |
| O que acontece na 4ª inserção? | Descarta o mais antigo da base |
| Apresento `pilhaDesempilhar`? | Não — não está no menu |
| Op. 5 vs op. 7? | 5 = pilha como está; 7 = cópia ordenada por senha |

---

## Checklist antes da apresentação

- [ ] Compilar: `make`
- [ ] Testar opções 2 e 5 (incluindo overflow com 4 atendimentos)
- [ ] Saber explicar pilha vs fila em uma frase
- [ ] Saber que op. 7 usa o histórico (Gabriel/Luiz apresentam)
