#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


// arrays de char definidos globalmente para evitar uso de ponteiros
static char player_1[20]; // nome do player 1
static char player_2[20]; // nome do player 2
static char resposta_do_player_1[10]; // resposta do player 1
static char resposta_do_player_2[10]; // resposta do player 2


// Funções auxiliares

int ConverterEntradaParaInteiro(int player){ // converte a entrada do player para inteiro para facilitar a comparação
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

void MostrarPlacar(int resutado_das_partidas[], int partidas){ // mostra o placar final do jogo
    int vitorias_do_p1 = 0;  // armazena a quantidade de vitorias totais para comparar no final
    int vitorias_do_p2 = 0; // ou da máquina

    system("cls || clear");

    for (int i = 0; i < partidas; i++) { // mostra o resultado de cada partida iterando o array com o resultado
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

    if (vitorias_do_p1 > vitorias_do_p2)    // mostra quem ganhou no fim do jogo
        printf("%s, YOU WIN - - %s, YOU LOSE\n", player_1, player_2);
    else if (vitorias_do_p1 < vitorias_do_p2)
        printf("%s, YOU LOSE - - %s, YOU WIN\n", player_1, player_2);
    else
        printf("O jogo empatou\n");

}



// Funções de players vs maquina chamadas a partir de outras funções

void EscolhaDeMaoDoJogador(int tempo_do_turno){ // escolha da mão do jogador (contra a máquina)
    time_t inicio = time(NULL) + tempo_do_turno; // inicio recebe o tempo atual mais o tempo do turno
    int ler_entrada = 0; // condição de leitura da entrada
    
    while ((time(NULL) - inicio) < 0) // consulte a documentação axiliar (linha 388)
    {
        system("cls || clear");

        printf( "Digite Pedra, Papel Tesoura, Lagarto ou Spock\n"
                "Tempo: %d\n\n"
                "Sua entrada esta sendo lida...\n ", (time(NULL) - inicio) * (-1)); // mostra o tempo restante, veja a documentação auxiliar (linha 394)

        fflush(stdin);
        Sleep(1000);

        if (kbhit()) // verifica se algo foi digitado durante o turno
            ler_entrada = 1;
    }

    if (ler_entrada == 1) // se algo foi digitado será lido
        scanf("%s", resposta_do_player_1);
    else { // se nada foi digitado, a entrada não ficará em espera
        strcpy(resposta_do_player_1, "nada");
    }

}

void Jogo_PxM(int resutado_das_partidas[], int partida){ // jogo player vs maquina

    int resposta_p1 = ConverterEntradaParaInteiro(1); // converte a resposta para inteiro

    if (resposta_p1 == 0) // se o usuário errar a entrada perde automaticamente
        resutado_das_partidas[partida] = 2;
    else // caso contrario a maquina joga, veja a documentação axiliar (linha 397)
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
    if (resutado_das_partidas[partida] == 1) // mostra o resultado da partida
        printf("%s ganhou a partida %d\n", player_1, partida + 1);
    else if (resutado_das_partidas[partida] == 2)
        printf("%s ganhou a partida %d\n", player_2, partida + 1);
    else
        printf("A partida  %d empatou\n", partida + 1);

    Sleep(5000);
}



// Funções de player vs player chamadas a partir de outras funções

void EscolhaDeMaoDosJogadores(int tempo_do_turno){ // escolha da mão dos dois jogadores
    time_t inicio = time(NULL) + tempo_do_turno; // inicio recebe o tempo atual mais o tempo do turno
    int ler_entrada = 0; // condição de leitura da entrada
    
    while ((time(NULL) - inicio) < 0) // consulte a documentação axiliar (linha 388)
    {
        system("cls || clear");

        printf( "Digite Pedra, Papel Tesoura, Lagarto ou Spock\n"
                "Tempo: %d\n\n"
                "Sua entrada esta sendo lida...\n ", (time(NULL) - inicio) * (-1)); // mostra o tempo restante, veja a documentação auxiliar (linha 394)

        fflush(stdin);
        Sleep(1000);

        if (kbhit()) // verifica se algo foi digitado durante o turno
            ler_entrada = 1;
    }

    if (ler_entrada == 1) // se algo foi digitado será lido
        scanf("%s %s", resposta_do_player_1, resposta_do_player_2);
    else { // se nada foi digitado, a entrada não ficará em espera
        strcpy(resposta_do_player_1, "nada");
        strcpy(resposta_do_player_2, "nada");
    }
}

void Jogo_PxP(int resutado_das_partidas[], int partida){ // jogo player vs player

    int resposta_p1 = ConverterEntradaParaInteiro(1); // converte a resposta para inteiro
    int resposta_p2 = ConverterEntradaParaInteiro(2); // converte a resposta para inteiro

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
    if (resutado_das_partidas[partida] == 1) // mostra o resultado da partida
        printf("%s ganhou a partida %d\n", player_1, partida + 1);
    else if (resutado_das_partidas[partida] == 2)
        printf("%s ganhou a partida %d\n", player_2, partida + 1);
    else
        printf("A partida  %d empatou\n", partida + 1);

    Sleep(5000);
}



// Funções chamadas pela Main 

void Inicio(){ // mensagem de inicio do jogo
    char frase[60] = {"Pedra, Papel, Tesoura, Lagarto, Spock \nBem vindo ao jogo!"}; //frase de inicio do jogo

    for (int i = 0; i < 60; i++) // mostra a frase letra por letra
    {
        printf("%c", frase[i]);
        Sleep(50); // faz um efeito de digitação
    }
    Sleep(1000);
}

void Def_Player1(){ // define o nome do player 1
    system("cls || clear");
    
    printf("Player 1\n"
            "nome: ");
    scanf("%s", &player_1);
}

int Def_Player2(){ // define o nome do player 2 ou se vai ser a maquina
        system("cls || clear");

        printf("Player 2 (digite 'M' para jogar com maquina)\n"
            "Nome: ");
        scanf("%s", &player_2); // dependendo da resposta, retorna 0 ou 1

        if (strcmp(player_2, "M") == 0 || strcmp(player_2, "m") == 0)
            return 0; // maquina
        else 
            return 1; // player 2
}

int Def_QuantidadeDePartidas(){ // define a quantidade de partidas
    int partidas = 0;
    
    while (partidas % 2 == 0 || partidas < 1 || partidas > 29) // partidas tem que ser impar e o máximo é 29
    {
        system("cls || clear");

        printf("Defina o numero de partidas\n"
            "O jogo deve ter numero impar de partidas impar\n"
            "Partidas: ");
            scanf("%d", &partidas);        
    }
    return partidas;
}

int Def_TempoDeTurnos(){ // define o tempo de um turno
    int tempo = 0;

    while (tempo != 30 && tempo != 45 && tempo != 60)
    {        
        system("cls || clear");
        
        printf("Defina o tempo maximo de um turno no jogo\n"
            "30s, 45s ou 60s: ");
            scanf("%d", &tempo);
    }
}

int RegrasDoJogo(int partidas, int tempo_do_turno){ // mostra as regras do jogo ao jogar com player 2
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

int RegrasDoJogoComMaquina(int partidas, int tempo_do_turno){ // mostra as regras do jogo ao jogar com maquina
    system("cls || clear");
    printf("Jogo Pedra, Papel, Tesoura, Lagarto, Spock\n\n"
            "Regras do Jogo: \n"
            "- O jogo tem %d Partidas com %d segundos por turno\n"
            "- o jogo tem um turno para voce escolher a sua mao e depois eh mostado o resultado, para cada partida\n"
            "- Ao comecar o turno, digite sua escolha e pressione enter\n"
            "- As entradas validas sao: pedra, papel, tesoura, lagarto e spock\n"
            "- O tempo do turno eh mostrado na tela de forma decrescente\n"
            "- Por privacidade, a entrada digitada nao aparece na tela, CUIDADO!\n\n"
            "...pressione enter para comecar\n ", partidas, tempo_do_turno);
    getchar();
    getchar();
}

void JogadorXJogador(int partidas, int tempo_do_turno){ // Jogo jogador x jogador
    int resutado_das_partidas[30]; // array que armazena o resultado de cada partida

    RegrasDoJogo(partidas, tempo_do_turno);

    for (int partida = 0; partida < partidas; partida++) // loop na quantidade de partidas
    {
        system("cls || clear");

        EscolhaDeMaoDosJogadores(tempo_do_turno); // escolha da mão
        Jogo_PxP(resutado_das_partidas, partida); // jogo
    }

    MostrarPlacar(resutado_das_partidas, partidas); // mostra o placar ao encerrar o jogo
}

void JogadorXMaquina(int partidas, int tempo_do_turno){ // Jogo jogador x maquina
    int resutado_das_partidas[30]; // array que armazena o resultado de cada partida

    RegrasDoJogoComMaquina(partidas, tempo_do_turno);

    for (int partida = 0; partida < partidas; partida++) // loop na quantidade de partidas
    {
        system("cls || clear");

        EscolhaDeMaoDoJogador(tempo_do_turno); // escolha da mão
        Jogo_PxM(resutado_das_partidas, partida); // jogo
    }

    MostrarPlacar(resutado_das_partidas, partidas); // mostra o placar ao encerrar o jogo
}



int main(){
    int partidas; // define a quantidade de partidas do jogo
    int tempo_do_turno; // intervalo entre partidas
    int Jogador1_ou_maquina0; // '1' se existe player 2 ou '0' se vai ser a maquina

    Inicio(); // mensagem de inicio

    // Definição das regras de Jogo
    // Def é abreviação de Definir
    Def_Player1();
    Jogador1_ou_maquina0 = Def_Player2();
    partidas = Def_QuantidadeDePartidas();
    tempo_do_turno = Def_TempoDeTurnos();

    if (Jogador1_ou_maquina0 == 1) // se a variavel for igual a 1, o jogo será jogador X jogador
        JogadorXJogador(partidas, tempo_do_turno);
    else // se a variavel for igual a 0, o jogo será jogador X maquina
        JogadorXMaquina(partidas, tempo_do_turno);
}





/* 
    DOCUMENTAÇÃO AUXILIAR

    -foi usado o comando system("cls || clear"); para limpar a tela do 
    programa em linux e windows

    -while ((time(NULL) - inicio) < 0) é uma estrutura de repetição
    que repete enquanto o calculo for menor que 0
    se agora for um valor x, menos a variavel inicio, que é o valor x mais o tempo 
    de turno. o calculo vai ser -30, ou -45, ou -60 no inicio, e aumentando com o 
    passar dos segundos até chegar ao 0 e acabar o loop.

    -(time(NULL) - inicio) * (-1) mesma calculo do while, mas mutiplicado por -1 para
    ir de 30 até 0, ao invés de -30 até 0.

    -independente da mão da máquina, aleatória, a chance de ganhar, empatar o perder
    é a mesma, então foi feito apenas o calculo dessa chance, 1 chance em 5 de empatar,
    2 chances em 5 de ganhar ou de perder

*/