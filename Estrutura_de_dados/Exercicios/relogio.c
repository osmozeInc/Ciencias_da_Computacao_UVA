#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void AtualizarTempo(int *h, int *m, int *s, short *fim);
void MostrarTempo(int h, int m, int s);


int main(){
    int horas = 0;
    int minutos = 0;
    int segundos = 0;
    short fim = 0;

    while(fim <= 1){
        MostrarTempo(horas, minutos, segundos);
        AtualizarTempo(&horas, &minutos, &segundos, &fim);
        sleep(1);
    }

    return 0;
}

void AtualizarTempo(int *h, int *m, int *s, short *fim){

    if (*h == 0 && *m == 0 && *s == 0){
    *h = 23;
    *m = 59;
    *s = 60;

    *fim += 1;
    }

    else if (*m == 0 && *s == 0){
    *m = 59;
    *s = 60;
    *h -= 1;
    }

    else if (*s == 0){
    *s = 60;
    *m -= 1;
    }

    *s -= 1;
}

void MostrarTempo(int h, int m, int s){
    system("clear");
    printf("%02d:%02d:%02d\n", h, m, s);
}
