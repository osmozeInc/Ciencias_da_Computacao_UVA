#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int main() {
    char entrada[20];
    char entrada2[20];
    time_t inicio = time(NULL) + 30;
    
    while ((time(NULL) - inicio) < -20)
    {
        printf("Tempo: %d\n", (time(NULL) - inicio) * (-1));
        printf("Sua entrada stá sendo lida...\n Digite algo: ");
        fflush(stdin);
        Sleep(1000);
        system("cls");

    }

    scanf("%s %s", entrada, entrada2);
    printf("Voce digitou: %s, %s\n", entrada, entrada2);
    
    
}
