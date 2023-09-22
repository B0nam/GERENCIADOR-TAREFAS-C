#include "includes.h"

Tarefa *criarTarefa(char cDescricao[100], bool bPrioridade, Tarefa *ptProximo)
{
    Tarefa *tTarefa = malloc(sizeof(Tarefa));
    tTarefa->cDescricao = strdup(cDescricao);
    tTarefa->bPrioridade = bPrioridade;
    tTarefa->ptProximo = ptProximo;
}

int exibirTarefa(Tarefa *ptTarefa)
{
    printf("--- Tarefa Atual ---\n");
    printf("Descrição:\t%s\n", ptTarefa->cDescricao);
    if (ptTarefa->bPrioridade)
    {
        printf("Prioritaria:\tSIM\n");
    } else
    {
        printf("Prioritaria:\tNÃO\n");
    }
    printf("Endereço:\t%p\n", ptTarefa);
    
    return EXIT_SUCCESS;
}