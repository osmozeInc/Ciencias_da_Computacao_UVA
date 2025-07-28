#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/grafo.h"

int main(){
    Grafo *grafo = Grafo_init();

    Grafo_print(grafo);

    Grafo_free(grafo);
}