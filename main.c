#include <stdio.h>
#include <stdlib.h>
#include "atendimento.h"
#include "palindromo.h"
#include "prioridade.h"

void testar_atendimento() {
    printf("1. SIMULADOR DE ATENDIMENTO\n");
    printf("---------------------------\n");
    
    FilaClientes fila_banco;
    fila_init_clientes(&fila_banco);

    Cliente c1 = {1, "Joao Silva", 5};
    Cliente c2 = {2, "Maria Santos", 3};
    Cliente c3 = {3, "Pedro Oliveira", 8};
    Cliente c4 = {4, "Ana Costa", 2};
    
    adicionar_cliente(&fila_banco, c1);
    adicionar_cliente(&fila_banco, c2);
    adicionar_cliente(&fila_banco, c3);
    adicionar_cliente(&fila_banco, c4);
    
    exibir_fila_clientes(&fila_banco);

    atender_proximo_cliente(&fila_banco);
    atender_proximo_cliente(&fila_banco);
    
    exibir_fila_clientes(&fila_banco);
}

void testar_palindromo() {
    printf("\n2. VERIFICADOR DE PALINDROMOS\n");
    printf("-----------------------------\n");
    
    char* palavras[] = {
        "arara", 
        "ovo", 
        "casa", 
        "radar", 
        "A man a plan a canal Panama", 
        "hello",
        "level",
    };
    int num_palavras = sizeof(palavras) / sizeof(palavras[0]);
    
    for (int i = 0; i < num_palavras; i++) {
        bool resultado = eh_palindromo(palavras[i]);
        printf("'%s' %s palindrome\n", palavras[i], resultado ? "eh" : "nao eh");
    }
}

void testar_prioridade() {
    printf("\n3. FILA DE PRIORIDADE SIMPLES\n");
    printf("-----------------------------\n");
    
    FilaPrioridade fila_prioridade;
    fila_init_prioridade(&fila_prioridade);
    
    ItemPrioridade item1 = {{1, "Cliente Normal", 5}, 3};
    ItemPrioridade item2 = {{2, "Cliente VIP", 3}, 1};
    ItemPrioridade item3 = {{3, "Cliente Premium", 4}, 2};
    ItemPrioridade item4 = {{4, "Cliente Urgente", 2}, 1};
    ItemPrioridade item5 = {{5, "Cliente Comum", 6}, 3};
    
    printf("\nAdicionando clientes na fila de prioridade:\n");
    fila_enqueue_prioridade(&fila_prioridade, item1);
    fila_enqueue_prioridade(&fila_prioridade, item2);
    fila_enqueue_prioridade(&fila_prioridade, item3);
    fila_enqueue_prioridade(&fila_prioridade, item4);
    fila_enqueue_prioridade(&fila_prioridade, item5);
    
    exibir_fila_prioridade(&fila_prioridade);
    
    printf("Atendendo por prioridade:\n");
    while (!fila_vazia_prioridade(&fila_prioridade)) {
        ItemPrioridade item = fila_dequeue_prioridade(&fila_prioridade);
        char* nivel[] = {"", "ALTA", "MEDIA", "BAIXA"};
        printf("-> Atendendo: %s (Prioridade: %s)\n", 
               item.dado.nome, nivel[item.prioridade]);
    }
}

int main() {
    printf("--- EXERCICIOS DE IMPLEMENTACAO DE FILAS ---\n\n");
    testar_atendimento();
    testar_palindromo();
    testar_prioridade();
    printf("\nExecucao finalizada.\n");
    return 0;
}
