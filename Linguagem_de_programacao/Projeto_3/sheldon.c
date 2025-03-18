#include <stdio.h>
#include <stdlib.h>


/*
2. O jogo será disputado em turnos de 30s, 45s ou 60s. 
3. Durante o turno, sucessivas escolhas são feitas de forma alternada por cada jogador, as escolhas 
são avaliadas e o placar é atualizado. No final do turno quem tiver mais pontos é o vencedor. 
4. Implementar sistema de pontos com atualização contínua. 
5. Implementar tempo regressivo para cada competidor. 
6. Implementar teclas de uso para cada escolha. 
7. Penalidades: teclas erradas e estouro de tempo dão pontos ao adversário. 
8. Implementar mensagens informando o andamento do jogo. 
9. Ao final do turno a mensagem “You Win!” deve ser mostrada ao campeão e a mensagem 
“You Lose!” ao perdedor. 
*/

// arrays de char definidos globalmente para evitar uso de ponteiros
static char player_1[20];
static char player_2[20];


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

        if (player_2 == "M" || player_2 == "m")
            return 0;
        else 
            return 1;
}

int Def_QuantidadeDePartidas(){
    int partidas;

    system("cls || clear");

    printf("Defina o numero de partidas\n"
            "O jogo deve ter numero impar de partidas impar\n"
            "Partidas: ");
    scanf("%d", &partidas);

    return partidas;
}

int Def_TempoDeTurnos(){
    int tempo = 0;

    system("cls || clear");

    printf("Defina o tempo máximo de um turno no jogo\n"
            "30s, 45s ou 60s: ");
    scanf("%d", &tempo);
    
    if (tempo == 30 && tempo == 45 && tempo == 60)
        return tempo;
}

int RegrasDoJogo(int partidas, int tempo){
    printf("Jogo Pedra, Papel, Tesoura, Lagarto, Spook\n"
            "Regras do Jogo: \n"
            "- Digite Pedra, Papel Tesoura...Etc para jogar"
            "- %d Partidas com %d segundos cada\n\n"
            "...pressione enter\n ", partidas, tempo);
    getchar();
    getchar();
}


void JogadorComJogador(int partidas, int tempo){
    char resposta_do_player_1[10];
    char resposta_do_player_2[10];
    
    system("cls || clear");
    
    printf("- Digite Pedra, Papel Tesoura, Lagarto ou Spook para jogar");
    scanf(" %s", &resposta_do_player_1)
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
        JogarComJogador(partidas, tempo_do_turno);
    }
    
}





/* 
    DOCUMENTAÇÃO AUXILIAR

    -foi usado o comando system("cls || clear"); para limpar a tela do 
    programa em linux e windows

    -





*/