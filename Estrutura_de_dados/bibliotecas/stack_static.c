#include <stdio.h>
#include "stack_static.h"

void Stack_init(Stack *stk) {               // função para inicializar a pilha
    stk->top = -1;                          // o topo da pilha comeca com -1 para o primeiro elemento da pilha ser o 0
    stk->size = 50;                         // o tamanho da pilha comeca com 50
}

void Stack_clear(Stack *stk) {
    stk->top = -1;
}

int Stack_isEmpty(Stack *stk) {             // funcao para verificar se a pilha esta vazia
    return stk->top == -1;                  // se o valor de top for igual a -1, quer dizer que a pilha está vazia, se sim, retorna 1, se nao, retorna 0
}

int Stack_isFull(Stack *stk) {              // funcao para verificar se a pilha esta cheia
    return stk->top == stk->size;           // se o valor de top for igual ao tamanho da pilha, quer dizer que a pilha esta cheia, se sim, retorna 1, se nao, retorna 0
}

void Stack_push(Stack *stk, int value) {    // funcao para empilhar um elemento na pilha
    if (!Stack_isFull(stk)) {               // se a pilha nao estiver cheia
        stk->top++;                         // incrementa o topo da pilha
        stk->itens[stk->top] = value;       // armazena o valor no topo da pilha
    }
    else puts("Pilha cheia\n");              // se a pilha estiver cheia, mostra uma mensagem
}

int Stack_pop(Stack *stk) {                 // funcao para desempilhar um elemento da pilha
    if (!Stack_isEmpty(stk)) {              // se a pilha nao estiver vazia
        int value = stk->itens[stk->top];   // pega o valor do topo da pilha
        stk->top--;                         // decrementa o topo da pilha
        return value;                       // retorna o valor
    }
    else puts("Pilha vazia\n");              // se a pilha estiver vazia, mostra uma mensagem
}

int Stack_top(Stack *stk) {                 // funcao para ver o topo da pilha
    if (!Stack_isEmpty(stk)) {              // se a pilha nao estiver vazia
        int value = stk->itens[stk->top];   // pega o valor do topo da pilha
        return value;                       // retorna o valor
    }
    else puts("Pilha vazia\n");              // se a pilha estiver vazia, mostra uma mensagem
}

