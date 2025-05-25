#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/stack.h"

void Menu();
void Empilhar(Stack *p);
void Desempilhar(Stack *p);
void VerTopo(Stack *p);

int main(){
    Stack p;
    Stack_init(&p);

    Menu(&p);


    return 0;
}

void Menu(Stack *p){
    system("clear");
    puts("Manipulação de pilha\n"
         "o que quer fazer?\n"
         "1. Empilhar\n"
         "2. Desempilhar\n"
         "3. Ver o topo\n"
         "4. Sair\n"
         "Escolha uma opção: ");

    int opcao;
    scanf("%d", &opcao);

    if (opcao != 4){
        if (opcao == 1)
            Empilhar(&p);
        else if (opcao == 2)
            Desempilhar(&p);
        else if (opcao == 3)
            VerTopo(&p);
    }
    else return;

    Menu(p);
}

void Empilhar(Stack *p) {
    if (!Stack_isFull(&p)) {
        puts("Pilha nao cheia\n"
             "Digite um numero: ");

        int numero;
        scanf("%d", &numero);

        Stack_push(&p, numero);
    }
    else
        puts("Pilha cheia\n");
}

void Desempilhar(Stack *p) {
    if (!Stack_isEmpty(&p)) {
        int numero = Stack_pop(&p);
        printf("Desempilhou %d\n", numero);
    }
    else
        puts("Pilha vazia\n");
}

void VerTopo(Stack *p) {
    if (!Stack_isEmpty(&p)){
        int numero = Stack_top(&p);
        printf("Topo da pilha: %d\n", numero);
    }
    else
        puts("Pilha vazia\n");
}