#include "stack.h"

void Stack_init(Stack *stk) {               // função para inicializar a pilha
    stk->top = -1;                          // o topo da pilha comeca com -1 para o primeiro elemento da pilha ser o 0
    stk->size = 50;                         // o tamanho da pilha comeca com 50
}

int Stack_isEmpty(Stack *stk) {             // funcao para verificar se a pilha esta vazia
    return stk->top == -1;                  // se o valor de top for igual a -1, quer dizer que a pilha está vazia, se sim, retorna 1, se nao, retorna 0
}

int Stack_isFull(Stack *stk) {              // funcao para verificar se a pilha esta cheia
    return stk->top == stk->size;           // se o valor de top for igual ao tamanho da pilha, quer dizer que a pilha esta cheia, se sim, retorna 1, se nao, retorna 0
}

void Stack_push(Stack *stk, int value) {
    if (!Stack_isFull(stk)) {
        stk->top++;
        stk->itens[stk->top] = value;
    }
}

int Stack_pop(Stack *stk) {
    if (!Stack_isEmpty(stk)) {
        int value = stk->itens[stk->top];
        stk->top--;
        return value;
    }
}

int Stack_top(Stack *stk) {
    int value = stk->itens[stk->top];
    return value;
}