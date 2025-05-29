#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/list.h"
#include "../bibliotecas/stack_dinamic.h"

List *InverterLista(List *l);

int main(){
    List *list = List_init();
    List *list_invert = List_init();
    int valor;
    
    for (int i = 0; i < 10; i++)
    {
        puts("digite um valor pra lista");
        scanf("%d", &valor);

        List_insert(list, valor);
    }

    list_invert = InverterLista(list);

    List_print(list_invert);
}


List *InverterLista(List *l) {
    Stack *stk = Stack_init(10);
    List *new_list = List_init();

    for (int i = 0; i < 10; i++)
    {
        int valor = List_returnAndRemoveFirstElement(l);
        Stack_push(stk, valor);
    }

    while (!Stack_isEmpty(stk))
    {
        List_insert(new_list, Stack_pop(stk));
    }
    
    return new_list;
}