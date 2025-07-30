#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

void inicializarGrafo(Grafo *grafo, int num_linhas, int num_colunas) {
    grafo->num_linhas = num_linhas;
    grafo->num_colunas = num_colunas;
    grafo->num_vertices = num_linhas * num_colunas;
    
    // Inicializar todos os vértices
    for (int i = 0; i < grafo->num_vertices; i++) {
        grafo->vertices[i].id = i;
        grafo->vertices[i].minado = 0;
        grafo->vertices[i].revelado = 0;
        grafo->vertices[i].marcado = 0;
        grafo->vertices[i].num_minas_adjacentes = 0;
    }
    
    // Inicializar matriz de adjacência
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            grafo->adjacencia[i][j] = 0;
        }
    }
    
    // Criar arestas entre células adjacentes
    for (int linha = 0; linha < num_linhas; linha++) {
        for (int coluna = 0; coluna < num_colunas; coluna++) {
            int id_atual = linha * num_colunas + coluna;
            
            // Verificar os 8 vizinhos possíveis
            for (int dl = -1; dl <= 1; dl++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dl == 0 && dc == 0) continue; // Pular a própria célula
                    
                    int nova_linha = linha + dl;
                    int nova_coluna = coluna + dc;
                    
                    // Verificar se o vizinho está dentro dos limites
                    if (nova_linha >= 0 && nova_linha < num_linhas &&
                        nova_coluna >= 0 && nova_coluna < num_colunas) {
                        int id_vizinho = nova_linha * num_colunas + nova_coluna;
                        adicionarAresta(grafo, id_atual, id_vizinho);
                    }
                }
            }
        }
    }
}

void adicionarAresta(Grafo *grafo, int id_origem, int id_destino) {
    if (id_origem >= 0 && id_origem < grafo->num_vertices &&
        id_destino >= 0 && id_destino < grafo->num_vertices) {
        grafo->adjacencia[id_origem][id_destino] = 1;
        grafo->adjacencia[id_destino][id_origem] = 1; // Grafo não direcionado
    }
}

int *obterVizinhos(Grafo *grafo, int id_vertice, int *num_vizinhos) {
    *num_vizinhos = 0;
    
    // Primeiro, contar quantos vizinhos existem
    for (int i = 0; i < grafo->num_vertices; i++) {
        if (grafo->adjacencia[id_vertice][i] == 1) {
            (*num_vizinhos)++;
        }
    }
    
    // Alocar memória para o array de vizinhos
    int *vizinhos = (int *)malloc(*num_vizinhos * sizeof(int));
    if (vizinhos == NULL) {
        *num_vizinhos = 0;
        return NULL;
    }
    
    // Preencher o array com os IDs dos vizinhos
    int indice = 0;
    for (int i = 0; i < grafo->num_vertices; i++) {
        if (grafo->adjacencia[id_vertice][i] == 1) {
            vizinhos[indice++] = i;
        }
    }
    
    return vizinhos;
}

void liberarVizinhos(int *vizinhos) {
    if (vizinhos != NULL) {
        free(vizinhos);
    }
}

