#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

struct Vizinho {
    int id_vizinho;         // valor dentro do grafo
    struct Vizinho *prox;   // ponteiro para o proximo vizinho do grafo
};

struct Grafo {
    int id_vertice;         // valor dentro do grafo
    Vizinho *prim_vizinho;  // ponteiro para o primeiro vizinho
    struct Grafo *prox;     // ponteiro para o proximo vertice
};

Grafo *Grafo_init() {
    Grafo *g = malloc(sizeof(Grafo));
    if (g) {
        g->id_vertice = 0;
        g->prim_vizinho = NULL;
        g->prox = NULL;
    }
    return g;
}

// void Grafo_insert(Grafo *g, int id_vizinho) {
//     Vizinho *v = malloc(sizeof(Vizinho));
//     if (v) {
//         v->id_vizinho = id_vizinho;
//         v->prox = g->prim_vizinho;
//         g->prim_vizinho = v;
//     }
// }

void libertar_vizinhhos(Vizinho *v) {
    while (v != NULL)
    {
        Vizinho *temp = v;
        v = v->prox;
        free(temp);
    }
}

void Grafo_free(Grafo *g) {
    Grafo *temp = NULL;
    while (g != NULL) {
        libertar_vizinhhos(g->prim_vizinho);

        temp = g;
        g = g->prox;
        free(temp);
    }
}

void Grafo_print(Grafo *g) {
    while (g != NULL)
    {
        printf("Vertice: %d\n", g->id_vertice);
        printf("Vizinhos: ");

        Vizinho *v = g->prim_vizinho;
        while (v != NULL)
        {
            printf("%d ", v->id_vizinho);
            v = v->prox;
        }
        
        printf("\n\n");
        g = g->prox;
    }
}