#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "tabuleiro.h"
#include "logica_jogo.h"

void exibirInstrucoes() {
    printf("=== CAMPO MINADO ===\n");
    printf("Comandos disponíveis:\n");
    printf("  abrir <linha> <coluna>  - Revelar uma célula\n");
    printf("  marcar <linha> <coluna> - Marcar/desmarcar uma célula como mina\n");
    printf("  sair                    - Sair do jogo\n");
    printf("  ajuda                   - Exibir estas instruções\n");
    printf("\nLegenda:\n");
    printf("  ?  - Célula oculta\n");
    printf("  F  - Célula marcada (Flag)\n");
    printf("  0-8 - Número de minas adjacentes\n");
    printf("  *  - Mina (aparece apenas quando revelada)\n");
    printf("==================\n\n");
}

void revelarTodasAsMinas(Grafo *grafo) {
    for (int i = 0; i < grafo->num_vertices; i++) {
        if (grafo->vertices[i].minado) {
            grafo->vertices[i].revelado = 1;
        }
    }
}

int main() {
    Grafo grafo;
    int num_linhas, num_colunas, num_minas;
    char comando[20];
    int linha, coluna;
    int jogo_ativo = 1;

    system("cls");
    system("chcp 65001");
    
    printf("=== CONFIGURAÇÃO DO JOGO ===\n");
    printf("Digite o número de linhas (máximo 10): ");
    scanf("%d", &num_linhas);
    printf("Digite o número de colunas (máximo 10): ");
    scanf("%d", &num_colunas);
    printf("Digite o número de minas: ");
    scanf("%d", &num_minas);
    
    // Validar entrada
    if (num_linhas <= 0 || num_colunas <= 0 || num_linhas > 10 || num_colunas > 10) {
        printf("Erro: Dimensões inválidas!\n");
        return 1;
    }
    
    if (num_minas <= 0 || num_minas >= num_linhas * num_colunas) {
        printf("Erro: Número de minas inválido!\n");
        return 1;
    }
    
    // Inicializar o jogo
    inicializarGrafo(&grafo, num_linhas, num_colunas);
    inicializarTabuleiro(&grafo, num_minas);
    
    exibirInstrucoes();
    
    // Loop principal do jogo
    while (jogo_ativo) {
        exibirTabuleiro(&grafo);
        
        printf("Digite um comando: ");
        scanf("%s", comando);
        
        if (strcmp(comando, "abrir") == 0) {
            printf("Digite a linha e coluna: ");
            scanf("%d %d", &linha, &coluna);
            
            // Validar coordenadas
            if (linha < 0 || linha >= num_linhas || coluna < 0 || coluna >= num_colunas) {
                printf("Coordenadas inválidas!\n");
                continue;
            }
            
            int id = mapearCoordenadasParaId(linha, coluna, num_colunas);
            int resultado = revelarCelula(&grafo, id);
            
            if (resultado == -1) {
                // Derrota
                revelarTodasAsMinas(&grafo);
                exibirTabuleiro(&grafo);
                printf("💥 BOOM! Você pisou em uma mina! Fim de jogo.\n");
                jogo_ativo = 0;
            } else if (resultado == 1) {
                // Verificar vitória
                if (verificarVitoria(&grafo)) {
                    exibirTabuleiro(&grafo);
                    printf("🎉 Parabéns! Você venceu!\n");
                    jogo_ativo = 0;
                }
            } else if (resultado == 0) {
                printf("Não foi possível revelar esta célula.\n");
            }
            
        } else if (strcmp(comando, "marcar") == 0) {
            printf("Digite a linha e coluna: ");
            scanf("%d %d", &linha, &coluna);
            
            // Validar coordenadas
            if (linha < 0 || linha >= num_linhas || coluna < 0 || coluna >= num_colunas) {
                printf("Coordenadas inválidas!\n");
                continue;
            }
            
            int id = mapearCoordenadasParaId(linha, coluna, num_colunas);
            marcarCelula(&grafo, id);
            
        } else if (strcmp(comando, "sair") == 0) {
            printf("Saindo do jogo...\n");
            jogo_ativo = 0;
            
        } else if (strcmp(comando, "ajuda") == 0) {
            exibirInstrucoes();
            
        } else {
            printf("Comando inválido! Digite 'ajuda' para ver os comandos disponíveis.\n");
        }
    }
    
    return 0;
}

