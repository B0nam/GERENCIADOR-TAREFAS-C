#ifndef fila
#define fila
#include "includes.h"

typedef struct Fila Fila;

typedef struct Fila {
  Tarefa *inicio;
  int tamanho;
};

Fila *criarFila();
int inserirFila(Fila *fiFila, Tarefa *ptNovaTarefa);
int removerFila(Fila *fiFila);

#endif