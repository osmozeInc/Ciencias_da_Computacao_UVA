#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


static char palavra_secreta[12];   // palavra que deve ser descorberta
static char palavra_usuario[12];   // palavra que o jogador deve adivinhar
static char letras_digitadas[15];

void BuscarPalavra(){
    srand(time(NULL));
    int contador_linha = 0;
    int linha = rand() % 20 + 1;

    FILE* arquivo = fopen("jogo\\palavras_por_linha.txt", "r");

    while (fgets(palavra_secreta, sizeof(palavra_secreta), arquivo))
    {
        contador_linha++;
        if (contador_linha == linha) {
            break;
        }
    }

    fclose(arquivo);
}

void DefinirTamanhoPalavra(){
    int tamanho = strlen(palavra_secreta);

    for (int i = 0; i < tamanho; i++)
    {
        if (palavra_secreta[i] != '\n')
            palavra_usuario[i] = '_';
        else{
            palavra_usuario[i] = '\0';
            palavra_secreta[i] = '\0';
            // evita bugs que ocorriam
        }
    }
}

int VerificarLetra(){
    int houve_acerto = 0;
    char letra;

    printf("Digite uma letra: ");
    scanf(" %c", &letra);

    for (int i = 0; i < strlen(letras_digitadas); i++) {
        if (letra == letras_digitadas[i]) {
            return 1;
        }
    }

    letras_digitadas[strlen(letras_digitadas)] = letra;

    // troca o hifen pela letra correta
    for (int i = 0; i < strlen(palavra_secreta); i++)
    {
        if (letra == palavra_secreta[i])
        {
            palavra_usuario[i] = letra;
            houve_acerto = 1;
        }
    }
    
    return houve_acerto;
}

void MensagemFinal(int tentativas){
    system("cls");

    if (tentativas == 0)
        printf("YOU LOSE!\n\n");
    else
        printf("YOU WIN!\n\n");

    printf("A Resposta era: %s", palavra_secreta);
}


int main(){
    int tentativas = 5;
    int acerto = 0;

    // escolhe uma palavra aleatória e define o tanto de hifens na palavra
    BuscarPalavra();
    DefinirTamanhoPalavra(palavra_secreta, palavra_usuario);

    for (int i = 0; i < tentativas; tentativas--)
    {
        system("cls");
        printf("Tentativas: %d\t\t", (tentativas));

        for (int i = 0; i < strlen(letras_digitadas); i++)
        {
            printf(" %c", letras_digitadas[i]);
        }
        
        printf("\nPalavra: %s\n", (palavra_usuario));
        acerto = VerificarLetra(palavra_secreta, palavra_usuario);

        if (acerto == 1){
            tentativas ++;

            if (strcmp(palavra_secreta, palavra_usuario) == 0)
                break;
        }
    }

    MensagemFinal(tentativas);
    
    return 0;
}