# Índice — Apresentação do Grupo G09

**Grupo:** G09 · **Contexto:** Farmácia  
**Compilação:** `make` ou `gcc -Wall -std=c99 -o main main.c sistema.c`

---

## Guias individuais (PDF)

| Colega | Guia | Foco |
|--------|------|------|
| Gabriel Borba dos Santos | `gabriel-fila-relatorio.pdf` | Fila circular + relatório (op. 7) |
| Henrique De Souza Pereira | `henrique-lista.pdf` | Lista encadeada (cadastro) |
| Vinicius Dos Santos Cardoso | `vinicius-pilha.pdf` | Pilha / histórico de atendimentos |
| Luiz Henrique de Moraes Chagas | `luiz-busca-ordenacao.pdf` | Busca sequencial + Bubble Sort |
| Luiz (trace) | `TRACE-MANUAL.pdf` | Passo a passo do Bubble Sort na op. 7 |

Gerar PDFs: `python scripts/md2pdf.py`

---

## Ordem sugerida da apresentação (~15–20 min)

| # | Quem | O quê | Opções do menu |
|---|------|-------|----------------|
| 1 | Gabriel | Contexto do sistema e fila de espera | 1, 4 |
| 2 | Henrique | Cadastro permanente (lista) + CPF | 1, 6 |
| 3 | Gabriel + Vinicius | Atendimento: fila remove, pilha empilha | 2, 5 |
| 4 | Luiz + Henrique | Busca sequencial (lista → vetor → busca) | 3 |
| 5 | Todos (rápido) | Exibir fila, histórico e lista | 4, 5, 6 |
| 6 | Luiz + Gabriel | Relatório ordenado + trace manual | 7 |

---

## Papéis das estruturas (visão geral)

| Estrutura | Papel | Capacidade |
|-----------|-------|------------|
| **Fila** | Quem espera atendimento agora | 11 clientes |
| **Lista** | Cadastro permanente de todos os clientes | ilimitada (memória) |
| **Pilha** | Histórico de quem já foi atendido | 3 atendimentos |

---

## Divisão de funções (`sistema.c`)

**Gabriel:** `filaInicializar`, `filaVazia`, `filaCheia`, `filaInserir`, `filaRemover`, `filaExibir`, `gerarRelatorio`

**Henrique:** `listaInserir`, `listaRemover`, `listaExibir`, `listaParaVetor`, `listaApagar`

**Luiz:** `buscaSequencial`, `buscaBinaria`, `ordenar`

**Vinicius:** `pilhaInicializar`, `pilhaVazia`, `pilhaCheia`, `pilhaEmpilhar`, `pilhaDesempilhar`, `pilhaExibir`

---

## Perguntas do README — quem responde

| Questão | Responsável |
|---------|-------------|
| 3 — Adequação da busca sequencial e Bubble Sort | Luiz |
| 4 — Fila após 10 inserções e 5 remoções | Gabriel |
| 5 — Estabilidade do algoritmo de ordenação | Luiz |
| 6 — Estado da lista após 3 inserções | Henrique |

---

## Checklist geral antes da apresentação

- [ ] Compilar: `make`
- [ ] Testar opções 1, 2, 3, 4, 5, 6, 7 e 0
- [ ] Cada colega leu seu guia PDF
- [ ] Luiz tem o trace manual (`TRACE-MANUAL.pdf`) na mão
- [ ] Saber explicar fila vs lista vs pilha em uma frase cada
