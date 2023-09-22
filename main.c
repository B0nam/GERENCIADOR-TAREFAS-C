#include "includes.h"

bool executarPrograma = true;
int iOpcao = 0;
Pilha *pilhaPrioritaria = NULL;
Fila *filaGeral = NULL;

void limparTela();
int menuInserirTarefa();
int menuFinalizarTarefa();
int menuVisualizarTarefa();

int main(void) // FUNCAO PRINCIPAL
{
    pilhaPrioritaria = criarPilha(); // CRIA PILHA PARA PRIORITARIOS
    filaGeral = criarFila();         // CRIA FILA PARA GERAL

    while (executarPrograma)
    {
        printf("--- Programa de gerenciamento de Tarefas ---\n");
        printf("0 - Sair\n");
        printf("1 - Inserir Tarefa\n");
        printf("2 - Finalizar Tarefa Atual\n");
        printf("3 - Visualizar Tarefa Atual\n");
        printf("Opção: ");
        scanf(" %d", &iOpcao);
        limparTela();

        switch (iOpcao)
        {
        case 0: // SAI DO PROGRAMA
            printf("Você escolheu sair do programa.\n");
            executarPrograma = false;
            break;
        case 1: // ADICIONA NOVA TAREFA
            menuInserirTarefa();
            break;
        case 2: // FINALIZA TAREFA
            if (menuFinalizarTarefa() == EXIT_FAILURE)
            {
                printf("[-] Não há tarefas pendentes");
            }
            break;
        case 3: // VISUALIZA TAREFA
            if (menuVisualizarTarefa() == EXIT_FAILURE)
            {
                printf("[-] Não há tarefas pendentes\n");
            }
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

int menuInserirTarefa() // ADICIONA TAREFA
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
    if (len > 0 && descricaoTarefa[len - 1] == '\n')
    {
        descricaoTarefa[len - 1] = '\0'; // REMOVE O \0 EXCEDENTE
    }

    while (prioridadeTarefa <= 0 || prioridadeTarefa > 2)
    {
        printf("\nPrioritária [1] SIM [2] NAO: ");
        scanf(" %d", &prioridadeTarefa); // RECEBE PRIORIDADE
    }

    if (prioridadeTarefa == 1) // ADICIONA À PILHA OU FILA DEPENDENDO DA PRIORIDADE
    {
        novaTarefa = criarTarefa(descricaoTarefa, true, NULL);
        return inserirPilha(pilhaPrioritaria, novaTarefa);
    }
    else
    {
        novaTarefa = criarTarefa(descricaoTarefa, false, NULL);
        return inserirFila(filaGeral, novaTarefa);
    }
}

int menuFinalizarTarefa() // ENCERRA A TAREFA ATUAL
{
    if (pilhaPrioritaria->topo) // ENCERRA PRIMEIRAMENTE O TOPO DA PILHA
    {
        return removerPilha(pilhaPrioritaria);
    }
    else
    {
        return removerFila(filaGeral); // ENCERRA TAREFA DA FILA GERAL
    }
}

Tarefa *buscarTarefaAtual() // REALIZA A BUSCA DA TAREFA
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

    return ptTarefa;
}

int menuVisualizarTarefa()
{
    Tarefa *tarefaAtual = buscarTarefaAtual();
    if (tarefaAtual)
    {
        exibirTarefa(tarefaAtual);
        printf("\nPressione enter para continuar...\n");
        getchar();
        getchar();
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}