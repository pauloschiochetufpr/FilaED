#ifndef PALINDROMO_H
#define PALINDROMO_H

#include <stdbool.h>

#define MAX_FILA 100

typedef struct {
    char dados[MAX_FILA];
    int inicio;
    int fim;
    int tamanho;
} FilaChar;

typedef struct {
    char dados[MAX_FILA];
    int topo;
} PilhaChar;

// das funções para fila de caracteres
void fila_init_char(FilaChar* fila);
bool fila_enqueue_char(FilaChar* fila, char c);
char fila_dequeue_char(FilaChar* fila);
void pilha_init_char(PilhaChar* pilha);
bool pilha_push_char(PilhaChar* pilha, char c);
char pilha_pop_char(PilhaChar* pilha);
bool eh_palindromo(char* palavra);

#endif