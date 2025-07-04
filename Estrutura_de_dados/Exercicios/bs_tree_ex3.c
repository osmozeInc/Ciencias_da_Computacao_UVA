#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/bs_tree.h"

int cmp(void *a, void *b);


int main(){
    int vetor[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    BST *bst = BST_init(cmp);
    BST *bst_logic = BST_init(cmp);

    bst = vecToBST(vetor, sizeof(vetor) / sizeof(int));
    bst_logic = vecToBSTLogic(vetor, sizeof(vetor) / sizeof(int));

    BST_print(bst);
    puts("\n\n");
    BST_print(bst_logic);

    BST_free(bst);
    return 0;
}