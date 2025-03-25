#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


// arrays de char definidos globalmente para evitar uso de ponteiros
static char player_1[20];
static char player_2[20];
static char resposta_do_player_1[10];
static char resposta_do_player_2[10];


// Funções auxiliares

int ConverterEntradaParaInteiro(int player){
    if (player == 1) {
        if (strcmp(resposta_do_player_1, "pedra") == 0) return 1;
        else if (strcmp(resposta_do_player_1, "papel") == 0) return 2;
        else if (strcmp(resposta_do_player_1, "tesoura") == 0) return 3;
        else if (strcmp(resposta_do_player_1, "lagarto") == 0) return 4;
        else if (strcmp(resposta_do_player_1, "spock") == 0) return 5;
        else return 0; // caso a entrada seja diferente das opções, retorna 0
    }

    else if (player == 2) {
        if (strcmp(resposta_do_player_2, "pedra") == 0) return 1;
        else if (strcmp(resposta_do_player_2, "papel") == 0) return 2;
        else if (strcmp(resposta_do_player_2, "tesoura") == 0) return 3;
        else if (strcmp(resposta_do_player_2, "lagarto") == 0) return 4;
        else if (strcmp(resposta_do_player_2, "spock") == 0) return 5;
        else return 0; // caso a entrada seja diferente das opções, retorna 0
    }
}

void MostrarPlacar(int resutado_das_partidas[], int partidas){
    int vitorias_do_p1 = 0;
    int vitorias_do_p2 = 0; // ou da máquina

    system("cls || clear");

    for (int i = 0; i < partidas; i++) {
        if (resutado_das_partidas[i] == 1){
            printf("%s ganhou a partida %d\n", player_1, i + 1);
            vitorias_do_p1++;
        }
        else if (resutado_das_partidas[i] == 2){
            printf("%s ganhou a partida %d\n", player_2, i + 1);
            vitorias_do_p2++;
        }
        else
            printf("A partida %d empatou\n", i + 1);
    }

    printf("\n\n");

    if (vitorias_do_p1 > vitorias_do_p2)
        printf("%s, YOU WIN - - %s, YOU LOSE\n", player_1, player_2);
    else if (vitorias_do_p1 < vitorias_do_p2)
        printf("%s, YOU LOSE - - %s, YOU WIN\n", player_1, player_2);
    else
        printf("O jogo empatou\n");

}


// Funções de players vs maquina chamadas a partir de outras funções

void EscolhaDeMaoDoJogador(int tempo_do_turno){
    time_t inicio = time(NULL) + tempo_do_turno;
    int ler_entrada = 0;
    
    while ((time(NULL) - inicio) < 0)
    {
        system("cls || clear");

        printf( "Digite Pedra, Papel Tesoura, Lagarto ou Spock\n"
                "Tempo: %d\n\n"
                "Sua entrada esta sendo lida...\n ", (time(NULL) - inicio) * (-1));

        fflush(stdin);
        Sleep(1000);

        if (kbhit())
            ler_entrada = 1;
    }

    if (ler_entrada == 1)
        scanf("%s", resposta_do_player_1);
    else {
        strcpy(resposta_do_player_1, "nada");
    }

}

void Jogo_PxM(int resutado_das_partidas[], int partida){

    int resposta_p1 = ConverterEntradaParaInteiro(1);

    if (resposta_p1 == 0) // se o usuário errar a entrada perde automaticamente
        resutado_das_partidas[partida] = 2;
    else // caso contrario a maquina joga, veja a documentação axiliar, no fim do código
    {
        int r = rand() % 5 + 1;
        if (r == 1)
            resutado_das_partidas[partida] = 0;
        else if (r == 2 || r == 3)
            resutado_das_partidas[partida] = 1;
        else if (r == 4 || r == 5)
            resutado_das_partidas[partida] = 2;
    }

    system("cls || clear");
    if (resutado_das_partidas[partida] == 1)
        printf("%s ganhou a partida %d\n", player_1, partida + 1);
    else if (resutado_das_partidas[partida] == 2)
        printf("%s ganhou a partida %d\n", player_2, partida + 1);
    else
        printf("A partida  %d empatou\n", partida + 1);

    Sleep(5000);
}


// Funções de player vs player chamadas a partir de outras funções

void EscolhaDeMaoDosJogadores(int tempo_do_turno)
{
    time_t inicio = time(NULL) + tempo_do_turno;
    int ler_entrada = 0;
    
    while ((time(NULL) - inicio) < 0)
    {
        system("cls || clear");

        printf( "Digite Pedra, Papel Tesoura, Lagarto ou Spock\n"
                "Tempo: %d\n\n"
                "Sua entrada esta sendo lida...\n ", (time(NULL) - inicio) * (-1));

        fflush(stdin);
        Sleep(1000);

        if (kbhit())
            ler_entrada = 1;
    }

    if (ler_entrada == 1)
        scanf("%s %s", resposta_do_player_1, resposta_do_player_2);
    else {
        strcpy(resposta_do_player_1, "nada");
        strcpy(resposta_do_player_2, "nada");
    }
}

void Jogo_PxP(int resutado_das_partidas[], int partida){

    int resposta_p1 = ConverterEntradaParaInteiro(1);
    int resposta_p2 = ConverterEntradaParaInteiro(2);

    // a variavel resultado da partida recebe 0 caso seja empate, 1 caso p1 ganhe, 2 caso p2 ganhe
    // o switch faz a verificação comparando a jogada do p1 com a jogada do p2
    switch (resposta_p1)
    {
        case 0: // entrada do player 1 errada
            if (resposta_p2 == 0) // empate se as duas entradas forem erradas
                resutado_das_partidas[partida] = 0;
            else
                resutado_das_partidas[partida] = 2;
            break;

        case 1: // pedra
            if (resposta_p2 == 1) // pedra empata
                resutado_das_partidas[partida] = 0;
            else if (resposta_p2 == 3 || resposta_p2 == 4) // pedra ganha de tesoura e lagarto
                resutado_das_partidas[partida] = 1;
            else
                resutado_das_partidas[partida] = 2;
            break;
        
        case 2: // papel
            if (resposta_p2 == 2) // papel empata
                resutado_das_partidas[partida] = 0;
            else if (resposta_p2 == 1 || resposta_p2 == 5) // papel ganha de pedra e spock
                resutado_das_partidas[partida] = 1;
            else
                resutado_das_partidas[partida] = 2;
            break;
        
        case 3: // tesoura
            if (resposta_p2 == 3) // tesoura empata
                resutado_das_partidas[partida] = 0;
            else if (resposta_p2 == 2 || resposta_p2 == 4) // tesoura ganha de papel e lagarto
                resutado_das_partidas[partida] = 1;
            else
                resutado_das_partidas[partida] = 2;
            break;
        
        case 4: // lagarto
            if (resposta_p2 == 4) // lagarto empata
                resutado_das_partidas[partida] = 0;
            else if (resposta_p2 == 2 || resposta_p2 == 5) // lagarto ganha do papel e spock
                resutado_das_partidas[partida] = 1;
            else
                resutado_das_partidas[partida] = 2;
            break;
        
        case 5: // spock
            if (resposta_p2 == 5) // spock empata
                resutado_das_partidas[partida] = 0;
            else if (resposta_p2 == 3 || resposta_p2 == 1) // spock ganha de tesoura e pedra
                resutado_das_partidas[partida] = 1;
            else
                resutado_das_partidas[partida] = 2;
            break;
    }

    system("cls || clear");
    if (resutado_das_partidas[partida] == 1)
        printf("%s ganhou a partida %d\n", player_1, partida + 1);
    else if (resutado_das_partidas[partida] == 2)
        printf("%s ganhou a partida %d\n", player_2, partida + 1);
    else
        printf("A partida  %d empatou\n", partida + 1);

    Sleep(5000);
}


// Funções chamadas pela Main 

void Def_Player1(){
    system("cls || clear");
    
    printf("Player 1\n"
            "nome: ");
    scanf("%s", &player_1);
}

int Def_Player2(){
        system("cls || clear");

        printf("Player 2 (digite 'M' para jogar com maquina)\n"
            "Nome: ");
        scanf("%s", &player_2);

        if (strcmp(player_2, "M") == 0 || strcmp(player_2, "m") == 0)
            return 0;
        else 
            return 1;
}

int Def_QuantidadeDePartidas(){
    int partidas = 0;
    
    while (partidas % 2 == 0 || partidas < 1 || partidas > 29)
    {
        system("cls || clear");

        printf("Defina o numero de partidas\n"
            "O jogo deve ter numero impar de partidas impar\n"
            "Partidas: ");
            scanf("%d", &partidas);        
    }
    return partidas;
}

int Def_TempoDeTurnos(){
    int tempo = 0;

    while (tempo != 30 && tempo != 45 && tempo != 60)
    {        
        system("cls || clear");
        
        printf("Defina o tempo maximo de um turno no jogo\n"
            "30s, 45s ou 60s: ");
            scanf("%d", &tempo);
    }
}

int RegrasDoJogo(int partidas, int tempo_do_turno){
    system("cls || clear");
    printf("Jogo Pedra, Papel, Tesoura, Lagarto, Spock\n\n"
            "Regras do Jogo: \n"
            "- O jogo tem %d Partidas com %d segundos por turno\n"
            "- o jogo tem um turno para escolher a mao de cada jogador e depois eh mostado o resultado, em cada partida\n"
            "- Ao comecar o turno, digite sua escolha e pressione enter, passe para o proximo jogador para ele fazer o mesmo\n"
            "- As entradas validas sao: pedra, papel, tesoura, lagarto e spock\n"
            "- O tempo do turno eh mostrado na tela de forma decrescente\n"
            "- Por privacidade, a entrada digitada nao aparece na tela, CUIDADO!\n\n"
            "...pressione enter para comecar\n ", partidas, tempo_do_turno);
    getchar();
    getchar();
}

int RegrasDoJogoComMaquina(int partidas, int tempo_do_turno){
    system("cls || clear");
    printf("Jogo Pedra, Papel, Tesoura, Lagarto, Spock\n\n"
            "Regras do Jogo: \n"
            "- O jogo tem %d Partidas com %d segundos por turno\n"
            "- o jogo tem um turno para voce escolher a sua mao e depois eh mostado o resultado, em cada partida\n"
            "- Ao comecar o turno, digite sua escolha e pressione enter\n"
            "- As entradas validas sao: pedra, papel, tesoura, lagarto e spock\n"
            "- O tempo do turno eh mostrado na tela de forma decrescente\n"
            "- Por privacidade, a entrada digitada nao aparece na tela, CUIDADO!\n\n"
            "...pressione enter para comecar\n ", partidas, tempo_do_turno);
    getchar();
    getchar();
}

void JogadorXJogador(int partidas, int tempo_do_turno){
    int resutado_das_partidas[30];


    for (int partida = 0; partida < partidas; partida++)
    {
        system("cls || clear");

        EscolhaDeMaoDosJogadores(tempo_do_turno);
        Jogo_PxP(resutado_das_partidas, partida);
    }

    MostrarPlacar(resutado_das_partidas, partidas);
}

void JogadorXMaquina(int partidas, int tempo_do_turno){
    int resutado_das_partidas[30];

    for (int partida = 0; partida < partidas; partida++)
    {
        system("cls || clear");

        EscolhaDeMaoDoJogador(tempo_do_turno);
        Jogo_PxM(resutado_das_partidas, partida);
    }

    MostrarPlacar(resutado_das_partidas, partidas);
}



int main(){
    int partidas; // define a quantidade de partidas do jogo
    int tempo_do_turno; // intervalo entre partidas
    int Jogador1_ou_maquina0; // '1' se existe player 2 ou '0' se vai ser a maquina

    // Definição das regras de Jogo
    // Def é abreviação de Definir
    Def_Player1();
    Jogador1_ou_maquina0 = Def_Player2();
    partidas = Def_QuantidadeDePartidas();
    tempo_do_turno = Def_TempoDeTurnos();

    // se a variavel for igual a 1, o jogo será jogador X jogador
    if (Jogador1_ou_maquina0 == 1){
        RegrasDoJogo(partidas, tempo_do_turno);
        JogadorXJogador(partidas, tempo_do_turno);
    }

    if (Jogador1_ou_maquina0 == 0){
        RegrasDoJogoComMaquina(partidas, tempo_do_turno);
        JogadorXMaquina(partidas, tempo_do_turno);
    }
}





/* 
    DOCUMENTAÇÃO AUXILIAR

    -foi usado o comando system("cls || clear"); para limpar a tela do 
    programa em linux e windows

    -





*/