#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tabuleiro.h"

void inicializarTabuleiro(Grafo *grafo, int num_minas) {
    // pega numeros aleatórios
    srand(time(NULL));
    
    int minas_colocadas = 0;
    // repetição para distribuir minas aleatoriamente
    while (minas_colocadas < num_minas) {
        int id_aleatorio = rand() % grafo->num_vertices;
        
        // Verificar se a célula já tem uma mina, se não, adciona
        if (grafo->vertices[id_aleatorio].minado == 0) {
            grafo->vertices[id_aleatorio].minado = 1;
            minas_colocadas++;
        }
    }
    
    // Calcular o número de minas adjacentes para cada célula
    calcularMinasAdjacentes(grafo);
}

void calcularMinasAdjacentes(Grafo *grafo) {
    // Para cada vertice do grafo não minado
    for (int i = 0; i < grafo->num_vertices; i++) {
        if (grafo->vertices[i].minado == 0) {
            int num_vizinhos;
            int *vizinhos = obterVizinhos(grafo, i, &num_vizinhos); // obtem o id dos vizinhos em um array
            
            // verifica os vizinhos e conta quantos estão minados
            int minas_adjacentes = 0;
            for (int j = 0; j < num_vizinhos; j++) {
                if (grafo->vertices[vizinhos[j]].minado == 1) {
                    minas_adjacentes++;
                }
            }
            
            // Atualizar o número de minas adjacentes ao vertice
            grafo->vertices[i].num_minas_adjacentes = minas_adjacentes;
            liberarVizinhos(vizinhos);  // libera o espaço ocupado pelo array
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
    for (int linha = 0; linha < grafo->num_linhas; linha++) {   // laço para cada linha
        printf("\033[37m%2d|", linha); // Número da linha
        
        for (int coluna = 0; coluna < grafo->num_colunas; coluna++) {   // laço para cada coluna
            int id = mapearCoordenadasParaId(linha, coluna, grafo->num_colunas);    // pega o id da celula
            Vertice *v = &grafo->vertices[id];     // pega o vertice da celula
            
            if (v->marcado) {
                printf("\033[1;41m B \033[0m"); // F para Flag (marcado)
            } else if (!v->revelado) {
                printf("\033[0;90m ? \033[0m"); // ? "); // ? para células ocultas
            } else if (v->minado) {
                printf("\033[0;43m \033[1;37m* \033[0m"); // * para minas (só aparece quando revelada)
            } else {
                if (v->num_minas_adjacentes == 0)
                    printf("\033[0;37m %d ", v->num_minas_adjacentes);  // branco

                if (v->num_minas_adjacentes == 1)
                    printf("\033[0;32m %d ", v->num_minas_adjacentes);  // verde

                if (v->num_minas_adjacentes == 2)
                    printf("\033[0;34m %d ", v->num_minas_adjacentes);  // azul

                if (v->num_minas_adjacentes == 3)
                    printf("\033[0;33m %d ", v->num_minas_adjacentes);  // amarelo

                if (v->num_minas_adjacentes == 4)
                    printf("\033[0;31m %d ", v->num_minas_adjacentes);  // vermelho

                if (v->num_minas_adjacentes >= 5)
                    printf("\033[0;35m %d ", v->num_minas_adjacentes);  // roxo
            }
        }
        printf("\n");
    }
    printf("\n");
}

int mapearCoordenadasParaId(int linha, int coluna, int num_colunas) {   // mapeia as coordenadas para o id
    return linha * num_colunas + coluna;
}

void mapearIdParaCoordenadas(int id, int num_colunas, int *linha, int *coluna) {
    *linha = id / num_colunas;
    *coluna = id % num_colunas;
}
