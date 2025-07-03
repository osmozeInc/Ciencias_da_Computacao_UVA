#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/bs_tree.h"

int cmp(void *a, void *b);


int main(){
    BST *bst = BST_init(cmp);

    BST_free(bst);
    return 0;
}


int cmp(void *a, void *b) {
    return *(int *)a - *(int *)b;
}