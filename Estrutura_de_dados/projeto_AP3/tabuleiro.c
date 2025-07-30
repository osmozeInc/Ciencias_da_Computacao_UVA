#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabuleiro.h"

void inicializarTabuleiro(Grafo *grafo, int num_minas) {
    // Inicializar gerador de números aleatórios
    srand(time(NULL));
    
    // Distribuir minas aleatoriamente
    int minas_colocadas = 0;
    while (minas_colocadas < num_minas) {
        int id_aleatorio = rand() % grafo->num_vertices;
        
        // Verificar se a célula já tem uma mina
        if (grafo->vertices[id_aleatorio].minado == 0) {
            grafo->vertices[id_aleatorio].minado = 1;
            minas_colocadas++;
        }
    }
    
    // Calcular o número de minas adjacentes para cada célula
    calcularMinasAdjacentes(grafo);
}

void calcularMinasAdjacentes(Grafo *grafo) {
    for (int i = 0; i < grafo->num_vertices; i++) {
        if (grafo->vertices[i].minado == 0) { // Só calcular para células sem mina
            int num_vizinhos;
            int *vizinhos = obterVizinhos(grafo, i, &num_vizinhos);
            
            int minas_adjacentes = 0;
            for (int j = 0; j < num_vizinhos; j++) {
                if (grafo->vertices[vizinhos[j]].minado == 1) {
                    minas_adjacentes++;
                }
            }
            
            grafo->vertices[i].num_minas_adjacentes = minas_adjacentes;
            liberarVizinhos(vizinhos);
        }
    }
}

void exibirTabuleiro(Grafo *grafo) {
    printf("\n   ");
    
    // Exibir números das colunas
    for (int col = 0; col < grafo->num_colunas; col++) {
        printf("%2d ", col);
    }
    printf("\n");
    
    // Exibir linha separadora
    printf("   ");
    for (int col = 0; col < grafo->num_colunas; col++) {
        printf("---");
    }
    printf("\n");
    
    // Exibir o tabuleiro
    for (int linha = 0; linha < grafo->num_linhas; linha++) {
        printf("%2d|", linha); // Número da linha
        
        for (int coluna = 0; coluna < grafo->num_colunas; coluna++) {
            int id = mapearCoordenadasParaId(linha, coluna, grafo->num_colunas);
            Vertice *v = &grafo->vertices[id];
            
            if (v->marcado) {
                printf(" F "); // F para Flag (marcado)
            } else if (!v->revelado) {
                printf(" ? "); // ? para células ocultas
            } else if (v->minado) {
                printf(" * "); // * para minas (só aparece quando revelada)
            } else {
                printf(" %d ", v->num_minas_adjacentes); // Número de minas adjacentes
            }
        }
        printf("\n");
    }
    printf("\n");
}

int mapearCoordenadasParaId(int linha, int coluna, int num_colunas) {
    return linha * num_colunas + coluna;
}

void mapearIdParaCoordenadas(int id, int num_colunas, int *linha, int *coluna) {
    *linha = id / num_colunas;
    *coluna = id % num_colunas;
}

