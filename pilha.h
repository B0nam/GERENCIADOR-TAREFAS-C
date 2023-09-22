#ifndef pilha
#define pilha
#include "includes.h"

typedef struct sPilha
{
    Tarefa *topo;
    int tamanho;
} Pilha;

Pilha *criarPilha();
int inserirPilha(Pilha *piPilha, Tarefa *ptNovaTarefa);
int removerPilha(Pilha *piPilha);
int mostrarTarefaAtualPilha(Pilha *piPilha);

#endif