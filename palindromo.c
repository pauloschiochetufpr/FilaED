#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "palindromo.h"

void fila_init_char(FilaChar* fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}

bool fila_enqueue_char(FilaChar* fila, char c) {
    if (fila->tamanho == MAX_FILA) {
        return false;
    } //enfileirar
    
    fila->fim = (fila->fim + 1) % MAX_FILA;
    fila->dados[fila->fim] = c;
    fila->tamanho++;
    return true;
}

char fila_dequeue_char(FilaChar* fila) {
    if (fila->tamanho == 0) {
        return '\0';
    }
    
    char c = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX_FILA;
    fila->tamanho--;
    return c;
}

void pilha_init_char(PilhaChar* pilha) {
    pilha->topo = -1;
}

bool pilha_push_char(PilhaChar* pilha, char c) {
    if (pilha->topo == MAX_FILA - 1) {
        return false;
    }
    
    pilha->dados[++pilha->topo] = c;
    return true;
}

char pilha_pop_char(PilhaChar* pilha) {
    if (pilha->topo == -1) {
        return '\0';
    }
    
    return pilha->dados[pilha->topo--];
}

bool eh_palindromo(char* palavra) { //ver se e palindromo
    if (palavra == NULL || strlen(palavra) == 0) {
        return false;
    }
    
    FilaChar fila;
    PilhaChar pilha;
    
    fila_init_char(&fila);
    pilha_init_char(&pilha);
    
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (isalpha(palavra[i])) { //so aceita letras(evite espaços ou simbolos)
            char c = tolower(palavra[i]);
            fila_enqueue_char(&fila, c);
            pilha_push_char(&pilha, c);
        }
    }

    while (fila.tamanho > 0) {
        char c_fila = fila_dequeue_char(&fila);
        char c_pilha = pilha_pop_char(&pilha);
        
        if (c_fila != c_pilha) {
            return false;
        }
    }
    
    return true;
}