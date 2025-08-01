#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "tabuleiro.h"
#include "logica_jogo.h"

void exibirInstrucoes() {
    printf("\n\n"
            "=== CAMPO MINADO ===\n"
            "Comandos disponíveis:\n"
            "  abrir <linha> <coluna>  - Revelar uma célula\n"
            "  marcar <linha> <coluna> - Marcar/desmarcar uma célula como mina\n"
            "  sair                    - Sair do jogo\n"
            "  ajuda                   - Exibir estas instruções\n"
            "\nLegenda:\n"
            "  ?  - Célula oculta\n"
            "  F  - Célula marcada (Flag)\n"
            "  0-8 - Número de minas adjacentes\n"
            "  *  - Mina (aparece apenas quando revelada)\n"
            "==================\n\n");
}


int main() {
    Grafo grafo;                                // cria um grafo
    int num_linhas, num_colunas, num_minas;     // variaveis do usuário para configurar o jogo
    char comando[20];                           // linhas de comando durante o jogo
    int linha, coluna;
    int jogo_ativo = 1;                         // flag que roda o jogo

    // windows
    system("chcp 65001");
    system("cls");

    // linux
    //system("clear");
    
    printf("=== CONFIGURAÇÃO DO JOGO ===\n");
    printf("Digite o número de linhas (máximo 10): ");
    scanf("%d", &num_linhas);
    printf("Digite o número de colunas (máximo 10): ");
    scanf("%d", &num_colunas);
    printf("Digite o número de minas: ");
    scanf("%d", &num_minas);
    
    // Validar entrada
    if (num_linhas <= 0 || num_colunas <= 0 || num_linhas > 10 || num_colunas > 10) {
        printf("Erro: Dimensões inválidas!\n\n");
        return 1;
    }
    
    if (num_minas <= 0 || num_minas >= num_linhas * num_colunas) {
        printf("Erro: Número de minas inválido!\n\n");
        return 1;
    }
    
    // Inicializar o jogo
    inicializarGrafo(&grafo, num_linhas, num_colunas);  // inicializa os vertices e as arestas do grafo
    inicializarTabuleiro(&grafo, num_minas);            // distribui as minas aleatoriamente
    
    exibirInstrucoes();     // comandos do jogo
    
    // Loop principal do jogo
    while (jogo_ativo) {
        linha, coluna = -1;
        exibirTabuleiro(&grafo);
        
        printf("Digite um comando: ");
        scanf("%s", comando);
        
        if (strcmp(comando, "abrir") == 0) {    // ler até o primeiro espaço
            printf("Digite a linha e coluna: ");    
            scanf("%d %d", &linha, &coluna);
            
            // Validar coordenadas
            if (linha < 0 || linha >= num_linhas || coluna < 0 || coluna >= num_colunas) {
                printf("Coordenadas inválidas!\n");
                continue;
            }
            
            int id = mapearCoordenadasParaId(linha, coluna, num_colunas);    // pega o id da celula
            int resultado = revelarCelula(&grafo, id);  // revela a celula e retorna um valor
            
            if (resultado == -1) {          // derrota
                revelarTodasAsMinas(&grafo);
                exibirTabuleiro(&grafo);
                printf("💥 BOOM! Você pisou em uma mina! Fim de jogo.\n");
                jogo_ativo = 0;
            } else if (resultado == 1) {    // vitória
                // Verificar vitória
                if (verificarVitoria(&grafo)) {
                    exibirTabuleiro(&grafo);
                    printf("🎉 Parabéns! Você venceu!\n");
                    jogo_ativo = 0;
                }
            } else if (resultado == 0) {    // celula aberta
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

