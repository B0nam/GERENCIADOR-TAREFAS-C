#include "../headers/includes.h"

// REALIZA A CRIACAO DE UMA NOVA TAREFA
Tarefa *criarTarefa(char cDescricao[100], bool bPrioridade, Tarefa *ptProximo) {
  Tarefa *tTarefa = malloc(sizeof(Tarefa));
  tTarefa->cDescricao = strdup(cDescricao);
  tTarefa->bPrioridade = bPrioridade;
  tTarefa->ptProximo = ptProximo;

  return tTarefa;
}

// REALIZA A EXIBICAO DA TAREFA
int exibirTarefa(Tarefa *ptTarefa) {
  printf("--- Tarefa Atual ---\n");
  printf("Descrição:\t%s\n", ptTarefa->cDescricao);
  if (ptTarefa->bPrioridade) {
    printf("Prioritaria:\tSIM\n");
  } else {
    printf("Prioritaria:\tNÃO\n");
  }
  printf("Endereço:\t%p\n", ptTarefa);

  return EXIT_SUCCESS;
}