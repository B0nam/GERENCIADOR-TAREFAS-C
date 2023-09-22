#ifndef tarefa
#define tarefa

typedef struct Tarefa Tarefa;

struct Tarefa
{
    char *cDescricao;
    bool bPrioridade;
    Tarefa *ptProximo;
};

Tarefa *criarTarefa(char cDescricao[100], bool bPrioridade, Tarefa *ptProximo);
int exibirTarefa(Tarefa *ptTarefa);

#endif