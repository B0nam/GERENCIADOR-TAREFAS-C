#include "includes.h"

Pilha *criarPilha()
{
    Pilha *piPilha = malloc(sizeof(Pilha));
    if (piPilha == NULL)
    {
        printf("[-] Erro na alocação de memória da pilha.\n");
        exit(EXIT_FAILURE);
    }
    piPilha->topo = NULL;
    piPilha->tamanho = 0;
    return piPilha;
}

int inserirPilha(Pilha *piPilha, Tarefa *ptNovaTarefa)
{
    if (piPilha->topo == NULL)
    {
        piPilha->topo = ptNovaTarefa;
    } else
    {
        ptNovaTarefa->ptProximo = piPilha->topo;
        piPilha->topo = ptNovaTarefa;
    }
    piPilha->tamanho++;
    printf("[+] Foi adicionado uma tarefa a pilha.\n");

    return EXIT_SUCCESS;
}

int removerPilha(Pilha *piPilha)
{
    if (piPilha->topo != NULL)
    {
        // Tem uma tarefa no topo
        Tarefa *ptTarefaTopo = piPilha->topo;
        piPilha->topo = ptTarefaTopo->ptProximo;
        free(ptTarefaTopo);
        printf("[+] O topo foi removido.\n");
    } else
    {
        printf("[-] A pilha está vazia.\n");
    }
    return EXIT_SUCCESS;
}