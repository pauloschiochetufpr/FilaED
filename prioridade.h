#ifndef PRIORIDADE_H
#define PRIORIDADE_H

#include <stdbool.h>
#include "atendimento.h" 

#define MAX_FILA 100

typedef struct {
    Cliente dado;
    int prioridade; // 1 = alta, 2 = média, 3 = baixa
} ItemPrioridade;

typedef struct {
    ItemPrioridade dados[MAX_FILA];
    int tamanho;
} FilaPrioridade;

//prototipos das funções
void fila_init_prioridade(FilaPrioridade* fila);
bool fila_vazia_prioridade(FilaPrioridade* fila);
bool fila_cheia_prioridade(FilaPrioridade* fila);
bool fila_enqueue_prioridade(FilaPrioridade* fila, ItemPrioridade item);
ItemPrioridade fila_dequeue_prioridade(FilaPrioridade* fila);
void exibir_fila_prioridade(FilaPrioridade* fila);

#endif 