#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/grafo.h"

int main(){
    Grafo *grafo = Grafo_init(1, "caio");
    Grafo *grafo_popular = Grafo_init(0, "");
   Grafo_insert_vertice(grafo, 2, "joao");
   Grafo_insert_vertice(grafo, 3, "pedro");
   Grafo_insert_vertice(grafo, 4, "ana");
   Grafo_insert_vertice(grafo, 5, "jane");
   Grafo_insert_vertice(grafo, 6, "marcos");

    Grafo_insert_vizinho(grafo, 2, 1, "caio");
    Grafo_insert_vizinho(grafo, 2, 4, "ana");
    Grafo_insert_vizinho(grafo, 2, 3, "pedro");
    Grafo_insert_vizinho(grafo, 3, 1, "caio");
    Grafo_insert_vizinho(grafo, 3, 5, "jane");
    Grafo_insert_vizinho(grafo, 3, 6, "marcos");
    Grafo_insert_vizinho(grafo, 3, 7, "bruna");
    Grafo_insert_vizinho(grafo, 4, 2, "joao");
    Grafo_insert_vizinho(grafo, 4, 5, "jane");
    Grafo_insert_vizinho(grafo, 5, 6, "macos");
    Grafo_insert_vizinho(grafo, 5, 7, "bruna");
    Grafo_insert_vizinho(grafo, 6, 8, "felipe");
    Grafo_insert_vizinho(grafo, 6, 9, "renata");
    Grafo_insert_vizinho(grafo, 7, 9, "renata");
    Grafo_insert_vizinho(grafo, 8, 6, "maros");
    Grafo_insert_vizinho(grafo, 8, 9, "renata");


    grafo_popular = get_mais_popular(grafo);
    Grafo_printNome(grafo_popular);

    Grafo_free(grafo);
}