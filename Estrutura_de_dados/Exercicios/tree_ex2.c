#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/tree.h"

int main(){
    Tree *tree = Tree_initSetTree();
    
    int result = 0;
    result = Tree_searchItemAndReturnParent(tree, 7);

    printf("\n\nO resultado eh: %d", result);

    return 0;
}