#include <stdio.h>
#include <stdlib.h>
#include "bs_tree.h"

int cmp(void *a, void *b) {
    return *(int *)a - *(int *)b;
}

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

void *BST_min(BST *bst) {
    if (!bst->root) return NULL;

    BST_node *node = bst->root;

    while (node->left) {
        node = node->left;
    }

    return node->value;
}

BST *vecToBSTLogic(int vec[], int length) {
    if (length == 0) return NULL;

    BST *bst = BST_init(cmp);

    for (int i = length / 2; i >= 1; i = i / 2) {
        BST_insert(bst, &vec[i]);
    }

    for (int i = 0; i < length; i++) {
        void *existe = BST_search(bst, &vec[i]);

        if (!existe) BST_insert(bst, &vec[i]);
    }

    return bst;
}

BST *vecToBST_aux(BST *bst, int vec[], int start, int end) {
    if (start > end) return bst;

    int mid = (start + end) / 2;
    BST_insert(bst, &vec[mid]);

    vecToBST_aux(bst, vec, start, mid - 1);
    vecToBST_aux(bst, vec, mid + 1, end);

    return bst; 
}

BST *vecToBST(int vec[], int length) {
    if (length == 0) return NULL;

    BST *bst = BST_init(cmp);

    return vecToBST_aux(bst, vec, 0, length - 1);
}