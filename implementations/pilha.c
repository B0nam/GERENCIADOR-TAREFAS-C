#include "../headers/includes.h"

//  REALIZA A CRIACAO DA PILHA
Pilha *criarPilha() {
  Pilha *piPilha = malloc(sizeof(Pilha));
  if (piPilha == NULL) {
    printf("[-] Erro na alocação de memória da pilha.\n");
    exit(EXIT_FAILURE);
  }
  piPilha->topo = NULL;
  piPilha->tamanho = 0;
  return piPilha;
}

// REALIZA A INSERCAO DE UMA TAREFA A PILHA
int inserirPilha(Pilha *piPilha, Tarefa *ptNovaTarefa) {
  if (piPilha->topo ==
      NULL) //  SE NAO EXISTIR UMA TAREFA NO TOPO, A TAREFA VIRA O TOPO
  {
    piPilha->topo = ptNovaTarefa;
  } else //  SE EXISTE UMA TAREFA NO TOPO, MOVE TOPO PARA PROXIMA, E ADICIONA
         //  NOVA AO TOPO
  {
    ptNovaTarefa->ptProximo = piPilha->topo;
    piPilha->topo = ptNovaTarefa;
  }
  piPilha->tamanho++;
  printf("[+] Foi adicionado uma tarefa a pilha.\n");

  return EXIT_SUCCESS;
}

int removerPilha(Pilha *piPilha) // REMOVE A TAREFA DA PILHA
{
  if (piPilha->topo != NULL) //  SE O TOPO ESTIVER VAZIO REMOVE TOPO
  {
    // Tem uma tarefa no topo
    Tarefa *ptTarefaTopo = piPilha->topo;
    piPilha->topo = ptTarefaTopo->ptProximo;
    free(ptTarefaTopo);
    piPilha->tamanho--;
    return EXIT_SUCCESS;
  } else // SE NAO HÁ TOPO, PILHA VAZIA
  {
    return EXIT_FAILURE;
  }
}