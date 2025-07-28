#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main() {
    system("chcp 65001");
    system("cls");
    system("gcc animacao.c -o animacao.exe");
    system("animacao.exe");

    return 0;
}