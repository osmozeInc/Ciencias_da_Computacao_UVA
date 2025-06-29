#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Tree *Tree_init(void *value, ValueType type, Tree *left, Tree *right) {
    Tree *t = (Tree *) malloc(sizeof(Tree));
    
    if (!t) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }
    
    t->value = value;
    t->type = type;
    t->left = left;
    t->right = right;

    return t;
}

void Tree_free(Tree *t) {
    if (t) {
        Tree_free(t->left);
        Tree_free(t->right);
        free(t);
    }
}

void Tree_print(Tree *t) {  // PRINT USANDO O PERCURSO IN-ORDER
    if (t) {
        Tree_print(t->left);

        if (t->type == INT_TYPE)
            printf("%d ", *(int *)t->value);
        else if (t->type == INT_TYPE)
            printf("%c ", *(char *)t->value);
        else 
            puts("Valor desconhecido");
        
        Tree_print(t->right);
    }
}

int Tree_returnResult(Tree *t) {  // SOMA USANDO O PERCURSO POST-ORDER
    if (t) {
        if (t->type == INT_TYPE)
            return *(int *)t->value;

        char op = *(char *)t->value;

        int left = Tree_returnResult(t->left);
        int right = Tree_returnResult(t->right);

        if (op == '+')
            return left + right;
        else if (op == '*')
            return left * right;
        else if (op == '-')
            return left - right;
        else if (op == '/')
            return left / right;
    }
}

Tree *Tree_initSetTree() {
    static int numero[11] = {3, 6, 4, 1, 5, 2, 9, 8, 7, 5, 3};

    Tree *t = Tree_init(&numero[0], INT_TYPE,
        Tree_init(&numero[1], INT_TYPE,                      
            Tree_init(&numero[2], INT_TYPE,                   
                Tree_init(&numero[3], INT_TYPE, NULL, NULL),  
                Tree_init(&numero[4], INT_TYPE, NULL, NULL)     
            ),
            Tree_init(&numero[5], INT_TYPE,                   
                Tree_init(&numero[6], INT_TYPE, NULL, NULL),    
                Tree_init(&numero[7], INT_TYPE, NULL, NULL)      
            )
        ),
        Tree_init(&numero[8], INT_TYPE, 
            NULL, 
            Tree_init(&numero[9], INT_TYPE, 
                Tree_init(&numero[10], INT_TYPE,
                    NULL, 
                    NULL),
                NULL
            )
        )
    );

    return t;

    //                   ___3__
    //                  /      \
    //                _6__      7
    //               /    \      \
    //              4      2      5
    //             / \    / \    /
    //            1   5  9   8  3
}

// função para buscar um item e retornar seu pai
int Tree_searchItemAndReturnParent(Tree *t, int item) {
    if (t){
        
        if (t->left && *(int *)t->left->value == item)
            return *(int *)t->value;
        
        if (t->right && *(int *)t->right->value == item)
            return *(int *)t->value;
        
        int result = Tree_searchItemAndReturnParent(t->left, item);
        if (result)
            return result;

        return Tree_searchItemAndReturnParent(t->right, item);
    }

    return 0;
}