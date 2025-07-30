typedef struct Vizinho Vizinho;    
typedef struct Grafo Grafo;

Grafo *Grafo_init(int id_vertice, char nome[]);
void Grafo_free(Grafo *g);
void Grafo_insert_vertice(Grafo *g, int id_vertice, char nome[]);
void Grafo_insert_vizinho(Grafo *g, int id_vertice, int id_vizinho, char nome[]);
void Grafo_print(Grafo *g);
void Grafo_printNome(Grafo *g);
int contar_seguidos(Grafo *g, char *nome);
int contar_seguidores(Grafo *vertice, char *nome, int imprime);
Grafo *get_mais_popular(Grafo *g);


