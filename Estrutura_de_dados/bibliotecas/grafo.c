#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

struct Vizinho {
    int id_vizinho;         // valor dentro do grafo
    char nome[50];          // nome do vizinho
    struct Vizinho *prox;   // ponteiro para o proximo vizinho do grafo
};

struct Grafo {
    int id_vertice;         // valor dentro do grafo
    char nome[50];          // nome do vertice
    Vizinho *prim_vizinho;  // ponteiro para o primeiro vizinho
    struct Grafo *prox;     // ponteiro para o proximo vertice
};

Grafo *Grafo_init(int id_vertice, char nome[]) {
    Grafo *g = malloc(sizeof(Grafo));
    if (g) {
        g->id_vertice = id_vertice;
        strcpy(g->nome, nome);
        g->prim_vizinho = NULL;
        g->prox = NULL;
    }
    return g;
}

void Grafo_insert_vertice(Grafo *g, int id_vertice, char nome[]) {
    if (!g || g->id_vertice == id_vertice) return;

    while (g != NULL) {
    if (g->id_vertice == id_vertice)
        return;
    if (g->prox == NULL) break;
    g = g->prox;
}

    
    Grafo *new = malloc(sizeof(Grafo));

    new->id_vertice = id_vertice;
    strcpy(new->nome, nome);
    new->prim_vizinho = NULL;
    new->prox = NULL;

    g->prox = new;
}

void Grafo_insert_vizinho(Grafo *g, int id_vertice, int id_vizinho, char nome[]) {
    if (!g) return;

    Grafo *grafo_base = g;
    
    while (g && g->id_vertice != id_vertice)
        g = g->prox;
        
    if (!g) return;
    
    Vizinho *temp = g->prim_vizinho;
    while (temp) {
        if (temp->id_vizinho == id_vizinho)
        return;
        
        temp = temp->prox;
    }
    
    Vizinho *new = malloc(sizeof(Vizinho));
    
    new->id_vizinho = id_vizinho;
    strcpy(new->nome, nome);
    new->prox = g->prim_vizinho;
    g->prim_vizinho = new;

    Grafo_insert_vertice(grafo_base, id_vizinho, nome);
}

void libertar_vizinhos(Vizinho *v) {
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
        libertar_vizinhos(g->prim_vizinho);

        temp = g;
        g = g->prox;
        free(temp);
    }
}

void Grafo_print(Grafo *g) {
    while (g != NULL)
    {
        printf("( %d ) ", g->id_vertice);

        Vizinho *v = g->prim_vizinho;
        while (v != NULL)
        {
            printf("-> %d ", v->id_vizinho);
            v = v->prox;
        }
        
        printf("\n  |\n");
        g = g->prox;
    }
}

void Grafo_printNome(Grafo *g) {
    while (g != NULL)
    {
        printf("( %s ) ", g->nome);

        Vizinho *v = g->prim_vizinho;
        while (v != NULL)
        {
            printf("-> %s ", v->nome);
            v = v->prox;
        }
        
        printf("\n  |\n");
        g = g->prox;
    }
}

int contar_seguidos(Grafo *g, char *nome){
    int seguidos = 0;

    while (g != NULL)
    {
        if (strcmp(g->nome, nome) == 0) {
            Vizinho *v = g->prim_vizinho;
            while (v != NULL)
            {
                seguidos++;
                v = v->prox;
            }
        }
            
        g = g->prox;
    }
    return seguidos;
}

int contar_seguidores(Grafo *g, char *nome, int imprime){
    int seguidores = 0;

    while (g != NULL)
    {
        Vizinho *v = g->prim_vizinho;
        while (v != NULL)
        {
            if (strcmp(v->nome, nome) == 0) {
                seguidores++;
                if (imprime) {
                    printf("%s, ", g->nome);
                }
            }
            v = v->prox;
        }
        
        g = g->prox;
    }

    return seguidores;
}

Grafo *get_mais_popular(Grafo *g){
    int popularidade = 0;
    Grafo *grafo_base = g;
    Grafo *mais_popular = NULL;

    while (g)
    {
        int seguidores = contar_seguidores(grafo_base, g->nome, 0);

        if (seguidores > popularidade) {
            popularidade = seguidores;
            mais_popular = g;
        }

        g = g->prox;
    }

    return mais_popular;
}

