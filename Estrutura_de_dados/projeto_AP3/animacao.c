#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(){
    char frase_de_inicio[50] = "Carregando o jogo...";
    
    for (int i = 0; i < 3; i++){
        system("cls");
        Sleep(350);

        printf(" ________  ________  _____ ______   ________  ________          _____ ______   ___  ________   ________  ________   ________ \n"
                "|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\   __  \\|\\   __  \\        |\\   _ \\  _   \\|\\  \\|\\   ___  \\|\\   __  \\|\\   ___ \\ |\\   __  \\    \n"
                "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\  \\|\\  \\ \\  \\|\\  \\       \\ \\  \\\\\\__\\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\_|\\ \\\\ \\  \\|\\  \\      \n"
                " \\ \\  \\    \\ \\   __  \\ \\  \\\\|__| \\  \\ \\   ____\\ \\  \\\\\\  \\       \\ \\  \\\\|__| \\  \\ \\  \\ \\  \\\\ \\  \\ \\   __  \\ \\  \\ \\\\ \\\\ \\  \\\\\\  \\     \n"
                "  \\ \\  \\____\\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\___|\\ \\  \\\\\\  \\       \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\ \\  \\ \\  \\_\\\\ \\\\ \\  \\\\\\  \\      \n"
                "   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\__\\    \\ \\_______\\       \\ \\__\\    \\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\__\\ \\__\\ \\_______\\\\ \\_______\\  \n"
                "    \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|__|     \\|_______|        \\|__|     \\|__|\\|__|\\|__| \\|__|\\|__|\\|__|\\|_______| \\|_______|  \n");
        Sleep(600);
    }

    for (int i = 0; i < 4; i++){
        puts("");
        Sleep(500);
    }

    for (int i = 0; i < 50; i++){
        printf("%c", frase_de_inicio[i]);
        Sleep(50);
    }

    Sleep(1000);
    return 0;
}