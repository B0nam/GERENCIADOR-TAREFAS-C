#ifndef pilha
#define pilha
#include "includes.h"

typedef struct Pilha Pilha;

typedef struct Pilha {
  Tarefa *topo;
  int tamanho;
};

Pilha *criarPilha();
int inserirPilha(Pilha *piPilha, Tarefa *ptNovaTarefa);
int removerPilha(Pilha *piPilha);

#endif