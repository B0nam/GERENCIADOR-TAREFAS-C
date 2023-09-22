#include "includes.h"

Fila *criarFila()
{
    Fila *fiFila = malloc(sizeof(Fila));
    if (fiFila == NULL)
    {
        printf("[-] Erro na alocação de memória da fila.\n");
        exit(EXIT_FAILURE);
    }
    fiFila->inicio = NULL;
    fiFila->tamanho = 0;
    return fiFila;
}

int inserirFila(Fila *fiFila, Tarefa *ptNovaTarefa)
{
    if (fiFila->inicio == NULL)
    {
        fiFila->inicio = ptNovaTarefa;
    }
    else
    {
        Tarefa *ptTarefa = malloc(sizeof(Tarefa));
        
        ptTarefa = fiFila->inicio;

        while (ptTarefa->ptProximo != NULL)
        {
            ptTarefa = ptTarefa->ptProximo;
        }

        ptTarefa->ptProximo = ptNovaTarefa;
    }
    fiFila->tamanho++;

    return EXIT_SUCCESS;
}

int removerFila(Fila *fiFila) 
{
    Tarefa *ptUltimaTarefa, *ptPenultimaTarefa = malloc(sizeof(Tarefa));

    ptUltimaTarefa = fiFila->inicio;

    while (ptUltimaTarefa->ptProximo != NULL) 
    {
        ptPenultimaTarefa = &(*ptUltimaTarefa);
        ptUltimaTarefa = ptUltimaTarefa->ptProximo;
    }

    ptPenultimaTarefa->ptProximo = NULL;
    free(&(*ptUltimaTarefa));
    free(ptUltimaTarefa);
    free(ptPenultimaTarefa);
}