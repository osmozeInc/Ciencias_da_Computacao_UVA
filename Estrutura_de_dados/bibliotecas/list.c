#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct List{
    int length;
    struct Node *first;
};

struct Node {
    int value;
    struct Node *next;
};

List *List_init() {
    List *l = (List *) malloc(sizeof(List));
    l->first = NULL;
    l->length = 0;

    return l;
}

void List_free(List *l) {
    if (l) {
        struct Node *node = l->first;

        if (l->length > 0) {
            while (node) {
                struct Node *next_node = node->next;
                free(node);
                node = next_node;
            }
        }

        free(l);
    }
}

void List_insert(List *l, int value) {
    if (l) {
        Node *n = (Node *) malloc(sizeof(Node));
        n->value = value;

        if (l->length == 0)
            n->next = NULL;
        else 
            n->next = l->first;

        l->first = n;
        l->length++;
    }
}

int List_remove(List *l, int value) {
    if (!l && !l->first) return 0; 

    struct Node *node = l->first;
    struct Node *last_node = NULL;
    
    while (node) {
        if (node->value == value) {
            if (last_node) {
                last_node->next = node->next;
            } else {
                l->first = node->next; // removendo o primeiro elemento
            }

            free(node);
            l->length--;
            return 1;
        }

        last_node = node;
        node = node->next;
    }
}

int List_getLength(List *l) {
    return l->length;
}

void List_print(List *l) {
    if (!l || !l->first) return;

    struct Node *node = l->first;
    puts("\nlista:");

    while (node)
    {    
        printf("%d\n", node->value);   
        node = node->next;
    }
}

int List_returnAndRemoveFirstElement(List *l){
    if (!l || !l->first) return -1;

    struct Node *node = l->first;
    int value = node->value;

    l->first = node->next;
    free(node);

    return value;
}