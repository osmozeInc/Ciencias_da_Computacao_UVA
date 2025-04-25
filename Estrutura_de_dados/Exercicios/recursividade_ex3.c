
#include <stdio.h>
void Procurar8PelaMatriz(int matriz[4][4], int linha, int coluna);
void DesenharMatriz(int matriz[4][4], int linha, int coluna);

int main(){
    int matriz[4][4] = {{2, 2, 2, 3}, {3, 4, 4, 3}, {3, 8, 1, 3}, {2, 1, 1, 4}};
    int linha = 0;
    int coluna = 0;

    DesenharMatriz(matriz, linha, coluna);
    //Procurar8PelaMatriz(matriz, linha, coluna);

    return 0;
}

void Procurar8PelaMatriz(int matriz[4][4], int linha, int coluna){
    printf("\nPosição do cursor é: [%d][%d]\n"
            "Numero nessa posicao eh: %d,", linha, coluna, matriz[linha][coluna]);

    switch (matriz[linha][coluna]){
        case 1:
            printf("indo para cima\n");
            linha--;
            Procurar8PelaMatriz(matriz, linha, coluna);
            break;
        case 2:
            printf("indo para direita\n");
            coluna++;
            Procurar8PelaMatriz(matriz, linha, coluna);
            break;
        case 3:
            printf("indo para baixo\n");
            linha++;
            Procurar8PelaMatriz(matriz, linha, coluna);
            break;
        case 4:
            printf("indo para esquerda\n");
            coluna--;
            Procurar8PelaMatriz(matriz, linha, coluna);
            break;
        case 8:
            printf("----------------------------------------\n"
                    "numero 8 encontrado na posicao: [%d][%d]", linha, coluna);
            break;
    }
}

void DesenharMatriz(int matriz[4][4], int linha, int coluna){

    printf("\n-----------------\n|");

    for (int l = 0; l < 4; l++){
        for (int c = 0; c < 4; c++){
        if (c == coluna && l == linha)
            printf(" X |");
        else
            printf(" %d |", matriz[l][c]);
        }
    printf("\n-----------------\n|");
    }
}
