#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atendimento.h"

void fila_init_clientes(FilaClientes* fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}

bool fila_vazia_clientes(FilaClientes* fila) {
    return fila->tamanho == 0; //fila vazia
}

bool fila_cheia_clientes(FilaClientes* fila) {
    return fila->tamanho == MAX_FILA; //cheia
}

bool adicionar_cliente(FilaClientes* fila, Cliente cliente) {
    if (fila_cheia_clientes(fila)) {
        printf("Fila lotada! Não é possível adicionar mais clientes.\n");
        return false;
    }
    
    fila->fim = (fila->fim + 1) % MAX_FILA;
    fila->dados[fila->fim] = cliente;
    fila->tamanho++;
    
    printf("Cliente %s (Nº %d) adicionado à fila.\n", cliente.nome, cliente.numero);
    return true;
}

Cliente atender_proximo_cliente(FilaClientes* fila) {
    Cliente cliente_vazio = {0, "", 0};
    
    if (fila_vazia_clientes(fila)) {
        printf("Não há clientes na fila para atender.\n");
        return cliente_vazio;
    }
    
    Cliente cliente = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_FILA;
    fila->tamanho--;
    
    printf("Atendendo cliente %s (Nº %d) - Tempo: %d minutos\n", 
           cliente.nome, cliente.numero, cliente.tempo_atendimento);
    
    return cliente;
}

float calcular_tempo_medio_espera(FilaClientes* fila) {
    if (fila_vazia_clientes(fila)) {
        return 0.0;
    }
    
    int tempo_total = 0;
    int pos = fila->inicio;
    
    for (int i = 0; i < fila->tamanho; i++) {
        tempo_total += fila->dados[pos].tempo_atendimento;
        pos = (pos + 1) % MAX_FILA;
    }
    
    return (float)tempo_total / fila->tamanho;
}

void exibir_fila_clientes(FilaClientes* fila) {
    if (fila_vazia_clientes(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    
    printf("\n FILA DE ATENDIMENTO \n");
    int pos = fila->inicio;
    
    for (int i = 0; i < fila->tamanho; i++) {
        printf("%d. %s (Nº %d) - %d min\n", 
               i + 1, fila->dados[pos].nome, 
               fila->dados[pos].numero, 
               fila->dados[pos].tempo_atendimento);
        pos = (pos + 1) % MAX_FILA;
    }
    printf("Tempo médio de espera: %.2f minutos\n", calcular_tempo_medio_espera(fila));
    printf("------------------------\n\n");
}