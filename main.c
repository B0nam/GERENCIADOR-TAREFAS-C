#include "includes.h"

bool executarPrograma = true;
int iOpcao = 0;
Pilha *pilhaPrioritaria = NULL;
Fila *filaGeral = NULL;

void limparTela();
int menuInserirTarefa();
int menuFinalizarTarefa();
int menuVisualizarTarefa();

int main(void)
{
    pilhaPrioritaria = criarPilha();
    filaGeral = criarFila();

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
            menuFinalizarTarefa();
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
    fgets(descricaoTarefa, sizeof(descricaoTarefa), stdin);

    // Removendo a quebra de linha (se existir) no final da descrição
    size_t len = strlen(descricaoTarefa);
    if (len > 0 && descricaoTarefa[len - 1] == '\n')
    {
        descricaoTarefa[len - 1] = '\0';
    }

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
    }
    else
    {
        // Criar tarefa sem prioridade - fila
        if (filaGeral->inicio == NULL)
        {
            novaTarefa = criarTarefa(descricaoTarefa, false, NULL);
            printf("[+] Criada a primeira tarefa.\n");
        }
        else
        {

            printf("[+] Criada tarefa.\n");
        }
    }

    return EXIT_SUCCESS;
}

int menuFinalizarTarefa()
{
    if (pilhaPrioritaria)
    return EXIT_SUCCESS;
}

Tarefa *buscarTarefaAtual()
{
    Tarefa *ptTarefa = NULL;
    if (pilhaPrioritaria->topo)
    {
        ptTarefa = pilhaPrioritaria->topo;
    }
    else if (filaGeral->inicio)
    {
        ptTarefa = filaGeral->inicio;
    }
    else
    {
        printf("[-] Não há tarefas pendentes\n");
    }

    return ptTarefa;
}

int menuVisualizarTarefa()
{
    printf("--- Tarefa Atual ---\n");
    exibirTarefa(buscarTarefaAtual);

    return EXIT_SUCCESS;
}