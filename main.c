#include "headers/includes.h"

bool executarPrograma = true;
int iOpcao = 0;
Pilha *pilhaPrioritaria = NULL;
Fila *filaGeral = NULL;

void limparTela();
void menuInserirTarefa();
void menuFinalizarTarefa();
void menuVisualizarTarefa();
void exibirQuantidadeTarefas();
void aguardarPermissaoContinuar();

int main(void) // FUNCAO PRINCIPAL
{
  pilhaPrioritaria = criarPilha(); // CRIA PILHA PARA PRIORITARIOS
  filaGeral = criarFila();         // CRIA FILA PARA GERAL

  while (executarPrograma) {
    printf("--- Programa de gerenciamento de Tarefas ---\n");
    printf("0 - Sair\n");
    printf("1 - Inserir Tarefa\n");
    printf("2 - Finalizar Tarefa Atual\n");
    printf("3 - Visualizar Tarefa Atual\n");
    printf("Opção: ");
    scanf(" %d", &iOpcao);
    limparTela();

    switch (iOpcao) {
    case 0: // SAI DO PROGRAMA
      printf("Você escolheu sair do programa.\n");
      executarPrograma = false;
      break;
    case 1: // ADICIONA NOVA TAREFA
      menuInserirTarefa();
      break;
    case 2: // FINALIZA TAREFA
      menuFinalizarTarefa();
      break;
    case 3: // VISUALIZA TAREFA
      menuVisualizarTarefa();
      break;
    default:
      printf("Opção inválida.");
      break;
    }
    limparTela();
  }
  return EXIT_SUCCESS;
}

void limparTela() { system("clear"); }

void menuInserirTarefa() // ADICIONA TAREFA
{
  int prioridadeTarefa = 0;
  char descricaoTarefa[100];
  Tarefa *novaTarefa;

  // SOLICITA DESCRICAO E PEDE PRIORIDADE
  printf("\n--- Inserir Nova Tarefa ---\n");
  printf("Descrição da tarefa: ");
  getchar();
  fgets(descricaoTarefa, sizeof(descricaoTarefa), stdin);

  // FILTRO DO RECEBIMENTO DA STRING
  size_t len = strlen(descricaoTarefa);
  if (len > 0 && descricaoTarefa[len - 1] == '\n') {
    descricaoTarefa[len - 1] = '\0'; // REMOVE O \0 EXCEDENTE
  }

  while (prioridadeTarefa <= 0 || prioridadeTarefa > 2) {
    printf("\nPrioritária [1] SIM [2] NAO: ");
    scanf(" %d", &prioridadeTarefa); // RECEBE PRIORIDADE
  }

  int resultadoInsercao = EXIT_FAILURE;
  // ADICIONA À PILHA OU FILA DEPENDENDO DA PRIORIDADE
  if (prioridadeTarefa == 1) {
    novaTarefa = criarTarefa(descricaoTarefa, true, NULL);
    resultadoInsercao = inserirPilha(pilhaPrioritaria, novaTarefa);
  } else {
    novaTarefa = criarTarefa(descricaoTarefa, false, NULL);
    resultadoInsercao = inserirFila(filaGeral, novaTarefa);
  }

  if (resultadoInsercao == EXIT_FAILURE) {
    printf("[-] Erro ao inserir tarefa.");
  }
}

void menuFinalizarTarefa() // ENCERRA A TAREFA ATUAL
{
  int resultadoRemocao = EXIT_FAILURE;

  if (pilhaPrioritaria->topo) // ENCERRA PRIMEIRAMENTE O TOPO DA PILHA
  {
    resultadoRemocao = removerPilha(pilhaPrioritaria);
  } else {
    // ENCERRA TAREFA DA FILA GERAL
    resultadoRemocao = removerFila(filaGeral);
  }

  if (resultadoRemocao == EXIT_FAILURE) {
    printf("\n[-] Não há tarefas pendentes\n");
  } else {
    printf("\n[+] A tarefa foi finalizada.\n");
  }
  aguardarPermissaoContinuar();
}

Tarefa *buscarTarefaAtual() // REALIZA A BUSCA DA TAREFA
{
  Tarefa *ptTarefa = NULL;
  if (pilhaPrioritaria->topo) {
    ptTarefa = pilhaPrioritaria->topo;
  } else if (filaGeral->inicio) {
    ptTarefa = filaGeral->inicio;
  }

  return ptTarefa;
}

void menuVisualizarTarefa() { // CHAMA A VISUALIZACAO DAS TAREFAS
  Tarefa *tarefaAtual = buscarTarefaAtual();
  if (tarefaAtual) {
    exibirTarefa(tarefaAtual);
    exibirQuantidadeTarefas();
  } else {
    printf("\n[-] Não há tarefas pendentes\n");
  }
  aguardarPermissaoContinuar();
}

void aguardarPermissaoContinuar() {
  printf("\nPressione enter para continuar...\n");
  getchar();
  getchar();
}

void exibirQuantidadeTarefas() {
  int numPrioritarias = pilhaPrioritaria->tamanho;
  int numGerais = filaGeral->tamanho;
  int numTotal = numPrioritarias + numGerais;

  printf("\n\t\tTotal de tarefas:\t%d", numTotal);
  printf("\n\tTarefas prioritárias:\t%d", numPrioritarias);
  printf("\nTarefas não-prioritárias:\t%d\n", numGerais);
}