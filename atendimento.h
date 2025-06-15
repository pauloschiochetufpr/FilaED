#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include <stdbool.h>

#define MAX_FILA 100

typedef struct {
    int numero;
    char nome[50];
    int tempo_atendimento; // em minutos
} Cliente;

typedef struct {
    Cliente dados[MAX_FILA];
    int inicio;
    int fim;
    int tamanho;
} FilaClientes;

void fila_init_clientes(FilaClientes* fila);
bool fila_vazia_clientes(FilaClientes* fila);
bool fila_cheia_clientes(FilaClientes* fila);
bool adicionar_cliente(FilaClientes* fila, Cliente cliente);
Cliente atender_proximo_cliente(FilaClientes* fila);
float calcular_tempo_medio_espera(FilaClientes* fila);
void exibir_fila_clientes(FilaClientes* fila);

#endif