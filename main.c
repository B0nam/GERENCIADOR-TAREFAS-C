#include "includes.h"

bool executarPrograma = true;
int iOpcao = 0;
Pilha *pilhaPrioritaria = NULL;
Tarefa *tarefaAtual = NULL;

void limparTela();
int menuInserirTarefa();
int menuFinalizarTarefa();
int menuVisualizarTarefa();

int main(void)
{
    pilhaPrioritaria = criarPilha();

    while (executarPrograma)
    {
        printf("--- Programa de gerenciamento de Tarefas ---\n");
        printf("0 - Sair\n");
        printf("1 - Inserir Tarefa\n");
        printf("2 - Finalizar Tarefa Atual\n");
        printf("3 - Visualizar Tarefa Atual\n");
        printf("Opção: ");
        scanf("%d", &iOpcao);
        limparTela();

        switch (iOpcao)
        {
        case 0:
            printf("Você escolheu sair do programa.\n");
            executarPrograma = false;
            break;
        case 1:
            menuInserirTarefa();
            break;
        case 2:
            printf("--- Finalizando a Tarefa Atual ---");
            break;
        case 3:
            menuVisualizarTarefa();
            break;
        default:
            printf("Opção inválida.");
            break;
        }
    }
    return EXIT_SUCCESS;
}

void limparTela()
{
    for (int x = 0; x <= 2; x++)
    {
        printf("\n");
    }
}

int menuInserirTarefa()
{
    int prioridadeTarefa = 0;
    char descricaoTarefa[100];
    Tarefa *novaTarefa;

    printf("\n--- Inserir Nova Tarefa ---\n");
    printf("Descrição da tarefa: ");
    scanf("%s", &descricaoTarefa);

    while (prioridadeTarefa <= 0 || prioridadeTarefa > 2)
    {
        printf("\nPrioritária [1] SIM [2] NAO: ");
        scanf("%d", &prioridadeTarefa);
    }
    if (prioridadeTarefa == 1)
    {
        // Criar tarefa com prioridade - pilha
        if (pilhaPrioritaria->topo == NULL)
        {
            novaTarefa = criarTarefa(descricaoTarefa, true, NULL);
            printf("[+] Criada a primeira tarefa.\n");
        }
        else
        {
            novaTarefa = criarTarefa(descricaoTarefa, true, pilhaPrioritaria->topo);
            printf("[+] Criada tarefa.\n");
        }

        int iInserirPilhaStatus = inserirPilha(pilhaPrioritaria, novaTarefa);
        if(iInserirPilhaStatus != 0)
        {
            printf("\n[-] A tarefa não foi adicionada na pilha\n");
            exit(EXIT_FAILURE);
        }
        tarefaAtual = pilhaPrioritaria->topo;
    }
    else
    {
        // Criar tarefa sem prioridade - fila
    }

    return EXIT_SUCCESS;
}

int menuFinalizarTarefa()
{
    return EXIT_SUCCESS;
}

int menuVisualizarTarefa()
{
    printf("--- Tarefa Atual ---\n");
    exibirTarefa(tarefaAtual);

    return EXIT_SUCCESS;
}