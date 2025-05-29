#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/stack_dinamic_char.h"

void VerificarExpressao(Stack *stk);

int main(){
    char sequencia[21];
    Stack *pilha = Stack_init(20);

    puts("digite a sequencia de parenteses, chaves, e/ou colchetes");
    scanf("%20s", sequencia);

    int i = 0;
    while (sequencia[i] != '\0')
    {
        Stack_push(pilha, sequencia[i]);
        i++;
    }

    VerificarExpressao(pilha);
    
    Stack_free(pilha);
}


void VerificarExpressao(Stack *stk) {
    int parentese = 0;
    int colchete = 0;
    int chave = 0;

    while (!Stack_isEmpty(stk)){
        char value = Stack_pop(stk);

        if (value == '(')
            parentese++;
        else if (value == ')')
            parentese--;
        else if (value == '[')
            colchete++;
        else if (value == ']')
            colchete--;
        else if (value == '{')
            chave++;
        else if (value == '}')
            chave--;
    }

    if (chave == 0 && colchete == 0 && parentese == 0)
        puts("expressao balanceada");
    else
        puts("expressao nao balanceada");
}