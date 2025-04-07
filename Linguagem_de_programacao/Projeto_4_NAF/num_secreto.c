#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void RegrasDoJogo(int tentativas){
    printf("|||||| Jogo de Adivinhacao ||||||\n");
    printf("Tente adivinhar o numero entre 1 e 100\n");
    printf("Voce tem %d tentativas.\n\n", tentativas);
}

int IntervaloValido(int palpite){
    if (palpite < 1 || palpite > 100) {
        printf("O número deve estar entre 1 e 100.\n\n");
        return 0;
    }
    return 1;
}

int VerificacaoDoNumero(int palpite, int numero_secreto){
    if (palpite > numero_secreto)
        printf("O numero secreto e MENOR que %d.\n\n", palpite);
    else if (palpite < numero_secreto) 
        printf("O numero secreto e MAIOR que %d.\n\n", palpite);
    else {
        printf("Parabens! Voce acertou o numero secreto: %d\n\n", numero_secreto);
        return 1;
    }
    return 0;
}

void jogar(int tentativas) {
    srand(time(NULL));
    int numero_secreto = (rand() % 100) + 1; // gera um número aleatório entre 1 e 100
    int palpite; // palpite do jogador
    int tentativas_restantes = tentativas; // tentativas restantes, inicia no maximo

    RegrasDoJogo(tentativas);

    for (tentativas_restantes = tentativas; tentativas_restantes > 0; tentativas_restantes--) {
        printf("Tentativas %d/%d\n"
               "Palpite: ", tentativas_restantes, tentativas);
        scanf("%d", &palpite);

        if (!IntervaloValido(palpite))
            continue;

        if (VerificacaoDoNumero(palpite, numero_secreto))
            return;
    }

    printf("Suas tentativas acabaram! O número secreto era: %d\n\n", numero_secreto);
}

int main(int argc, char *argv[]) {
    int tentativas = 10; // chances que o usuário tem para acertar o número
    char jogar_novamente; // condição de parada e repetição do loop do jogo

    // verifica se o argumento foi fornecido
    if (argc == 2) {
        tentativas = atoi(argv[1]);

        // verifica se o argumento é um número positivo
        if (tentativas <= 0) {
            printf("Numero de tentativas deve ser maior que 0\n"
                    "Voce tem 10 tentativas\n");
            tentativas = 10;
        }
    }

    do {
        jogar(tentativas); // onde o jogo de adivinhação acontece

        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogar_novamente);
    } while (jogar_novamente == 's' || jogar_novamente == 'S'); // repete enquanto a resposta for 's' ou 'S'

    printf("Obrigado por jogar!\n");
    return 0;
}