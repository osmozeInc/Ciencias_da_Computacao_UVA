#include <stdio.h>
#include <stdlib.h>


void Procurar8PelaMatriz(int matriz[4][4], int linha, int coluna);
void DesenharMatriz(int matriz[4][4], int linha, int coluna);

int main(){
    int matriz[4][4] = {{2, 2, 2, 3}, {3, 4, 4, 3}, {3, 8, 1, 3}, {2, 1, 1, 4}};
    int linha = 0;
    int coluna = 0;

    Procurar8PelaMatriz(matriz, linha, coluna);

    return 0;
}

void Procurar8PelaMatriz(int matriz[4][4], int linha, int coluna){
    system("cls ||clear");
    DesenharMatriz(matriz, linha, coluna);

    printf("\nPosicao do cursor e: [%d][%d]\n"
            "Numero nessa posicao eh: %d, ", linha + 1, coluna + 1, matriz[linha][coluna]);

    switch (matriz[linha][coluna]){
        case 1:
            printf("indo para cima\n");
            linha--;
            printf("pressione enter para continuar\n");
            getchar();
            Procurar8PelaMatriz(matriz, linha, coluna);
            break;
        case 2:
            printf("indo para direita\n");
            coluna++;
            printf("pressione enter para continuar\n");
            getchar();
            Procurar8PelaMatriz(matriz, linha, coluna);
            break;
        case 3:
            printf("indo para baixo\n");
            linha++;
            printf("pressione enter para continuar\n");
            getchar();
            Procurar8PelaMatriz(matriz, linha, coluna);
            break;
        case 4:
            printf("indo para esquerda\n");
            coluna--;
            printf("pressione enter para continuar\n");
            getchar();
            Procurar8PelaMatriz(matriz, linha, coluna);
            break;
        case 8:
            system("cls || clear");
            DesenharMatriz(matriz, linha, coluna);
            printf("\n\n----------------------------------------\n"
                    "numero 8 encontrado na posicao: [%d][%d]", linha + 1, coluna + 1);
            break;
    }
}

void DesenharMatriz(int matriz[4][4], int linha, int coluna){
    for (int l = 0; l < 4; l++){
        printf("\n-----------------\n|");
        for (int c = 0; c < 4; c++){
        if (c == coluna && l == linha)
            printf("\033[33m X \033[0m|");
        else
            printf(" %d |", matriz[l][c]);
        }
    }
    printf("\n-----------------\n");
}