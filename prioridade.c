#include <stdio.h>
#include <stdlib.h>
#include "prioridade.h"

void fila_init_prioridade(FilaPrioridade* fila) {
    fila->tamanho = 0;
}

bool fila_vazia_prioridade(FilaPrioridade* fila) {
    return fila->tamanho == 0;
}

bool fila_cheia_prioridade(FilaPrioridade* fila) {
    return fila->tamanho == MAX_FILA;
}


bool fila_enqueue_prioridade(FilaPrioridade* fila, ItemPrioridade item) {
    if (fila_cheia_prioridade(fila)) {
        printf("Fila de prioridade lotada!\n");
        return false; //ordem por prioridade
    }
    
    //encontra a posição correta para inserir
    int posicao = 0;
    while (posicao < fila->tamanho && 
           fila->dados[posicao].prioridade <= item.prioridade) {
        posicao++;
    }
    
    //deslocamento
    for (int i = fila->tamanho; i > posicao; i--) {
        fila->dados[i] = fila->dados[i - 1];
    }
    
    //insere o novo item
    fila->dados[posicao] = item;
    fila->tamanho++;
    
    char* nivel_prioridade[] = {"", "ALTA", "MÉDIA", "BAIXA"};
    printf("cliente %s adicionado com prioridade %s\n", 
           item.dado.nome, nivel_prioridade[item.prioridade]);
    
    return true;
}

// Remove item da fila de prioridade
ItemPrioridade fila_dequeue_prioridade(FilaPrioridade* fila) {
    ItemPrioridade item_vazio = {{0, "", 0}, 0};
    
    if (fila_vazia_prioridade(fila)) {
        printf("fila de prioridade vazia.\n");
        return item_vazio;
    }
    
    ItemPrioridade item = fila->dados[0];

    for (int i = 0; i < fila->tamanho - 1; i++) {
        fila->dados[i] = fila->dados[i + 1]; //desloca
    }
    
    fila->tamanho--;
    return item;
}

void exibir_fila_prioridade(FilaPrioridade* fila) {
    if (fila_vazia_prioridade(fila)) {
        printf("Fila de prioridade vazia.\n");
        return;
    }
    
    printf("\n=== FILA DE PRIORIDADE ===\n");
    char* prioridades[] = {"", "ALTA", "MÉDIA", "BAIXA"};
    
    for (int i = 0; i < fila->tamanho; i++) {
        printf("%d. %s (Nº %d) - Prioridade: %s - %d min\n",
               i + 1,
               fila->dados[i].dado.nome,
               fila->dados[i].dado.numero,
               prioridades[fila->dados[i].prioridade],
               fila->dados[i].dado.tempo_atendimento);
    }
    printf("---------------------\n\n");
}