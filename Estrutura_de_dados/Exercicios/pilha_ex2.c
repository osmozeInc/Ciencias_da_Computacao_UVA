#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/stack_dinamic.h"

int main(){
    int valor;
    Stack *pilha = Stack_init(30);

    puts("digite uma sequencia\n");
    scanf("%d", &valor);

    Stack_push(pilha, valor);

    int outro_valor;
    outro_valor = Stack_pop(pilha);
    printf("valor digitado: %d\n", outro_valor);

    Stack_free(pilha);
    return 0;
}