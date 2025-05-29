#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/list.h"

int main() {
    List *list = List_init();

    while (1)
    {
        int resposta;

        printf("\n\n1 - adicionar elemento\n"
                "2 - remover elemento\n"
                "3 - obter tamanho da lista\n"
                "4 - exibir lista\n"
                "5 - sair\n");
        scanf("%d", &resposta);

        if (resposta == 5) break;

        switch (resposta){
        case 1:
            int valor;
            
            puts("qual valor? ");
            scanf("%d", &valor);

            List_insert(list, valor);
            break;
        
        case 2:
            int elemento;

            puts("Qual elemento? ");
            scanf("%d", &elemento);

            List_remove(list, elemento);
            break;

        case 3:
            int tamanho = List_getLength(list);
            printf("%d", tamanho);
            break;
        
        case 4:
            List_print(list);
            break;
        
        default:
            break;
        }
    }
    

    List_free(list);
    return 0;
}