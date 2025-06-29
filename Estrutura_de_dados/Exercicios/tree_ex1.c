#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/tree.h"

int main(){
    int operandos[5] = {3, 6, 4, 1, 5};
    char operadores[4] = {'+', '*', '+', '-'};

    // (3+6) * (4-1) + 5
    Tree *tree = Tree_init(&operadores[0], CHAR_TYPE,               // +
        Tree_init(&operadores[1], CHAR_TYPE,                        // *
            Tree_init(&operadores[2], CHAR_TYPE,                    // +
                Tree_init(&operandos[0], INT_TYPE, NULL, NULL),     // 3
                Tree_init(&operandos[1], INT_TYPE, NULL, NULL)      // 6
            ),
            Tree_init(&operadores[3], CHAR_TYPE,                    // -
                Tree_init(&operandos[2], INT_TYPE, NULL, NULL),     // 4
                Tree_init(&operandos[3], INT_TYPE, NULL, NULL)      // 1
            )
        ),
        Tree_init(&operandos[4], INT_TYPE, NULL, NULL)
    );

    printf("\nArvore inicial: ");
    Tree_print(tree);

    int result = Tree_returnResult(tree);
    printf("\n\nO resultado eh: %d", result);

    Tree_free(tree);
    return 0;
}
