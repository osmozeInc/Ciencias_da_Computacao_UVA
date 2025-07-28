typedef struct Vizinho Vizinho;    
typedef struct Grafo Grafo;

Grafo *Grafo_init();
void Grafo_free(Grafo *g);
void Grafo_print(Grafo *g);