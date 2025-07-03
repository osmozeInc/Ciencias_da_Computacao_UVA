#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/bs_tree.h"

int cmp(void *a, void *b);


int main(){
    BST *bst = BST_init(cmp);

    for (int i = 0; i < 4; i++) {
        puts("digite um valor: ");
        int *value = malloc(sizeof(int));
        scanf("%d", value);
        BST_insert(bst, value);
    }

    puts("busque um valor: ");
    int search_value = 0;
    scanf("%d", &search_value);
    void *result = BST_search(bst, &search_value);

    if (result) printf("Encontrado: %d\n", *(int *)result);
    else printf("Nao encontrado\n");

    BST_free(bst);
    return 0;
}


int cmp(void *a, void *b) {
    return *(int *)a - *(int *)b;
}