#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/bs_tree.h"

int cmp(void *a, void *b);


int main(){
    BST *bst = BST_init(cmp);

    for (int i = 0; i < 5; i++) {
        puts("\ndigite um valor: ");
        int *value = malloc(sizeof(int));
        scanf("%d", value);
        BST_insert(bst, value);
    }

    BST_print(bst);

    void *min = BST_min(bst);
    if (min) printf("\n\nO menor valor da arvore eh: %d\n", *(int *)min);

    puts("procure um valor: ");
    int search_value = 0;
    scanf("%d", &search_value);
    void *result = BST_search(bst, &search_value);

    if (result) printf("\n\nO valor %d foi encontrado na arvore\n", search_value);
    else printf("\n\nO valor %d nao foi encontrado na arvore\n", search_value);

    BST_free(bst);
    return 0;
}


int cmp(void *a, void *b) {
    return *(int *)a - *(int *)b;
}