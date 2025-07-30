#ifndef LOGICA_JOGO_H
#define LOGICA_JOGO_H

#include "grafo.h"

// Protótipos das funções da lógica do jogo
int revelarCelula(Grafo *grafo, int id_vertice);
void marcarCelula(Grafo *grafo, int id_vertice);
int verificarVitoria(Grafo *grafo);
int verificarDerrota(Grafo *grafo, int id_vertice_revelado);
void revelarCelulasVazias(Grafo *grafo, int id_vertice);

#endif // LOGICA_JOGO_H

