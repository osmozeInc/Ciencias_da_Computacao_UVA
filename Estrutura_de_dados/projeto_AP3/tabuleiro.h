#ifndef TABULEIRO_H
#define TABULEIRO_H

#include "grafo.h"

// Protótipos das funções do tabuleiro
void inicializarTabuleiro(Grafo *grafo, int num_minas);
void exibirTabuleiro(Grafo *grafo);
int mapearCoordenadasParaId(int linha, int coluna, int num_colunas);
void mapearIdParaCoordenadas(int id, int num_colunas, int *linha, int *coluna);
void calcularMinasAdjacentes(Grafo *grafo);

#endif // TABULEIRO_H

