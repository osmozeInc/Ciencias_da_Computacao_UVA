#include <stdio.h>
#include <stdlib.h>
#include "logica_jogo.h"

int revelarCelula(Grafo *grafo, int id_vertice) {
    // Verificar se o ID é válido
    if (id_vertice < 0 || id_vertice >= grafo->num_vertices) {
        return 0; // ID inválido
    }
    
    Vertice *v = &grafo->vertices[id_vertice];
    
    // Não revelar se já está revelada ou marcada
    if (v->revelado || v->marcado) {
        return 0;
    }
    
    // Revelar a célula
    v->revelado = 1;
    
    // Se for uma mina, retornar derrota
    if (v->minado) {
        return -1; // Derrota
    }
    
    // Se não tem minas adjacentes, revelar células vizinhas automaticamente
    if (v->num_minas_adjacentes == 0) {
        revelarCelulasVazias(grafo, id_vertice);
    }
    
    return 1; // Sucesso
}

void revelarCelulasVazias(Grafo *grafo, int id_vertice) {
    // Implementação usando BFS (Busca em Largura)
    int fila[MAX_VERTICES];
    int inicio = 0, fim = 0;
    int visitado[MAX_VERTICES] = {0};
    
    // Adicionar o vértice inicial à fila
    fila[fim++] = id_vertice;
    visitado[id_vertice] = 1;
    
    while (inicio < fim) {
        int atual = fila[inicio++];
        
        int num_vizinhos;
        int *vizinhos = obterVizinhos(grafo, atual, &num_vizinhos);
        
        for (int i = 0; i < num_vizinhos; i++) {
            int id_vizinho = vizinhos[i];
            Vertice *v_vizinho = &grafo->vertices[id_vizinho];
            
            // Se o vizinho não está revelado, não está marcado e não foi visitado
            if (!v_vizinho->revelado && !v_vizinho->marcado && !visitado[id_vizinho]) {
                v_vizinho->revelado = 1;
                visitado[id_vizinho] = 1;
                
                // Se o vizinho também não tem minas adjacentes, adicionar à fila
                if (v_vizinho->num_minas_adjacentes == 0 && !v_vizinho->minado) {
                    fila[fim++] = id_vizinho;
                }
            }
        }
        
        liberarVizinhos(vizinhos);
    }
}

void marcarCelula(Grafo *grafo, int id_vertice) {
    // Verificar se o ID é válido
    if (id_vertice < 0 || id_vertice >= grafo->num_vertices) {
        return;
    }
    
    Vertice *v = &grafo->vertices[id_vertice];
    
    // Só marcar/desmarcar se não estiver revelada
    if (!v->revelado) {
        v->marcado = !v->marcado; // Alternar entre marcado e não marcado
    }
}

int verificarVitoria(Grafo *grafo) {
    for (int i = 0; i < grafo->num_vertices; i++) {
        Vertice *v = &grafo->vertices[i];
        
        // Se há uma célula sem mina que não foi revelada, o jogo não terminou
        if (!v->minado && !v->revelado) {
            return 0; // Jogo não terminou
        }
    }
    
    return 1; // Vitória!
}

int verificarDerrota(Grafo *grafo, int id_vertice_revelado) {
    if (id_vertice_revelado < 0 || id_vertice_revelado >= grafo->num_vertices) {
        return 0;
    }
    
    return grafo->vertices[id_vertice_revelado].minado;
}

