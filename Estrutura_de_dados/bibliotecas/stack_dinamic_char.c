#include <stdio.h>
#include <stdlib.h>
#include "stack_dinamic.h"

struct Stack
{
    int size;
    int top;
    char *elements;
};


Stack *Stack_init(int size) {
    Stack *stk = (Stack *) malloc(sizeof(Stack));
    stk->elements = (char *) malloc(size * sizeof(char));
    stk->top = -1;
    stk->size = size;

    return stk;
}

void Stack_free(Stack *stk) {
    if (stk){
        free(stk->elements);
        free(stk);
    }
}

int Stack_isEmpty(Stack *stk) {
    return stk->top == -1;
}

int Stack_isFull(Stack *stk) {
    return stk->top == stk->size - 1;
}

void Stack_push(Stack *stk, char value) {
    if (!Stack_isFull(stk)) {
        stk->top++;
        stk->elements[stk->top] = value;
    }
    else 
        puts("pilha cheia\n");
}

char Stack_pop(Stack *stk) {
    if (!Stack_isEmpty(stk)) {
        char value = stk->elements[stk->top];
        stk->top--;
        return value;
    }
    else 
        puts("pilha vazia\n");
    
    return -1;
}

char Stack_top(Stack *stk) {
    if (!Stack_isEmpty(stk))
        return stk->elements[stk->top];
    else 
        puts("pilha vazia\n");
    
    return -1;
}