#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 100 // tamanho máximo do tabuleiro

typedef struct Vertice {
    int id;
    int minado; // 1 se tem mina, 0 caso contrário
    int revelado; // 1 se revelado, 0 caso contrário
    int marcado; // 1 se marcado, 0 caso contrário
    int num_minas_adjacentes;
} Vertice;

typedef struct Grafo {
    Vertice vertices[MAX_VERTICES];
    int adjacencia[MAX_VERTICES][MAX_VERTICES]; // Matriz de adjacência
    int num_vertices;
    int num_linhas;
    int num_colunas;
} Grafo;

// Protótipos das funções do grafo
void inicializarGrafo(Grafo *grafo, int num_linhas, int num_colunas);
void adicionarAresta(Grafo *grafo, int id_origem, int id_destino);
int *obterVizinhos(Grafo *grafo, int id_vertice, int *num_vizinhos);
void liberarVizinhos(int *vizinhos);

#endif // GRAFO_H


