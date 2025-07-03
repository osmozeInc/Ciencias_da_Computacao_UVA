#include <stdio.h>
#include <stdlib.h>
#include "bs_tree.h"

BST *BST_init(int (*cmp)(void *, void *)) {
    BST *bst = NULL;

    if (cmp)
    {
        bst = malloc(sizeof(BST));
        
        bst->size = 0;
        bst->cmp = cmp;
        bst->root = NULL;
    }
    
    return bst;
}

void BST_nodeFree(BST_node *node) {
    if (node) {               
        BST_nodeFree(node->left);
        BST_nodeFree(node->right);
        free(node);
    }
}

void BST_free(BST *bst) {
    if (bst) {
        BST_nodeFree(bst->root);
        free(bst);
    }
}

void BST_insert(BST *bst, void *value) {
    BST_node *node = NULL;
    BST_node *new = NULL;

    if (bst && value) {
        new = malloc(sizeof(BST_node));
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        
        if (bst->size == 0) {
            bst->root = new;
            bst->size++;
        }
        else{
            node = bst->root;

            while(node) {
                if (bst->cmp(value, node->value) < 0) {
                    if (node->left == NULL) {
                        node->left = new;
                        bst->size++;
                        break;
                    }
                    node = node->left;
                }

                else if (bst->cmp(value, node->value) > 0) {
                    if (node->right == NULL) {
                        node->right = new;
                        bst->size++;
                        break;
                    }
                    node = node->right;
                }
                else {
                    break;
                }
            }
        }
    }
}

void *BST_search(BST *bst, void *value) {
    if (!bst && !value) return NULL;

    BST_node *node = bst->root;

    while(node) {
        int cmp_result = bst->cmp(value, node->value);

        if (cmp_result < 0) 
            node = node->left;
        
        else if (cmp_result > 0) 
            node = node->right;
        
        else
            return node->value;
    }

    return NULL;
}

void *BST_remove(BST *bst, void *value) {
    if (!bst && !value) return NULL;

    BST_node *parent = NULL;
    BST_node *node = bst->root;

    while(node) {
        int cmp_result = bst->cmp(value, node->value);

        if (cmp_result < 0){
            parent = node;
            node = node->left;
        }
        
        else if (cmp_result > 0) {
            parent = node;
            node = node->right;
        }
        
        else{
            void *removed_value = node->value;

            if (!node->left && !node->right) // nao tem filhos
            {
                if (!parent)
                    bst->root = NULL;
                else if (parent->left == node)
                    parent->left = NULL;
                else
                    parent->right = NULL;

                free(node);
            }

            if (node->left && !node->right) // um filho (esquerda)
            {
                if (!parent)
                    bst->root = node->left;
                else if (parent->left == node)
                    parent->left = node->left;
                else 
                    parent->right = node->left;

                free(node);    
            }
            
            if (node->left && !node->right) // um filho (direita)
            {
                if (!parent)
                    bst->root = node->right;
                else if (parent->left == node)
                    parent->left = node->right;
                else 
                    parent->right = node->right;
                
                free(node);
            }
            
            else // dois filhos
            {
                // encontra o sucessor (minimo da subarvore direita)
                BST_node *successor_parent = node;
                BST_node *successor = node->right;

                while(successor->left){
                    successor_parent = successor;
                    successor = successor->left;
                }

                node->value = successor->value;

                if (successor_parent->left == successor)
                    successor_parent->left = successor->right;
                else
                    successor_parent->right = successor->right;

                free(successor);
            }

            bst->size--;
            return removed_value;
        }       
    }
}

void BST_nodePrint(BST_node *node) {
    printf("<");
    if (node) {
        printf("%d", *(int *)node->value);
        BST_nodePrint(node->left);
        BST_nodePrint(node->right);
    }
    printf(">");
}

void BST_print(BST *bst) {
    if (bst) {
        BST_nodePrint(bst->root);
    }
}




/*

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

*/