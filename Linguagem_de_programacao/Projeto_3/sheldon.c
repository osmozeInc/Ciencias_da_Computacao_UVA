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

    printf("Defina o número de partidas"
            "O jogo deve ter numero impar de partidas"
            "Partidas: ");
    scanf("%d", &partidas);

    return partidas;
}

int Def_TempoDeJogo(){
    system("cls || clear");
}

int main(){
    int partidas; // define a quantidade de partidas do jogo
    int tempo; // intervalo entre partidas
    int player2_ou_maquina; // '1' se existe player 2 e '0' se vai ser a maquina

    // Definição das regras de Jogo
    // Def é abreviação de Definir
    Def_Player1();
    player2_ou_maquina = Def_Player2();
    partidas = Def_QuantidadeDePartidas();
    tempo = Def_TempoDeJogo();
    

}





/* 
    DOCUMENTAÇÃO AUXILIAR

    -foi usado o comando system("cls || clear"); para limpar a tela do 
    programa em linux e windows

    -





*/