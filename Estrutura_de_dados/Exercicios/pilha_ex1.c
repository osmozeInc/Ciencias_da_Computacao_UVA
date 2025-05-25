// EXEMPLO DE PILHA COM ALOCAÇÃO ESTÁTICA
// gcc pilha_ex1.c ../bibliotecas/stack_static.c -o pilha

#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/stack_static.h"

void Menu();
void Empilhar(Stack *p);
void Desempilhar(Stack *p);
void VerTopo(Stack *p);
void LimparPilha(Stack *p);

int main(){
    Stack p;
    Stack_init(&p);

    Menu(&p);


    return 0;
}

void Menu(Stack *p){
    puts("\n\nManipulacao de pilha\n"
         "o que quer fazer?\n"
         "1. Empilhar\n"
         "2. Desempilhar\n"
         "3. Ver o topo\n"
         "4. Limpar pilha\n"
         "5. Sair\n"
         "Escolha uma opcao: ");

    int opcao;
    scanf("%d", &opcao);

    if (opcao != 5){
        if (opcao == 1)
            Empilhar(p);
        else if (opcao == 2)
            Desempilhar(p);
        else if (opcao == 3)
            VerTopo(p);
        else if (opcao == 4)
            LimparPilha(p);
    }
    else return;

    Menu(p);
}

void Empilhar(Stack *p) {
    if (!Stack_isFull(p)) {
        puts("\n\nPilha nao cheia\n"
             "Digite um numero: ");

        int numero;
        scanf("%d", &numero);

        Stack_push(p, numero);
    }
    else
        puts("\n\nPilha cheia\n");
}

void Desempilhar(Stack *p) {
    if (!Stack_isEmpty(p)) {
        int numero = Stack_pop(p);
        printf("\n\nDesempilhou %d\n", numero);
    }
    else
        puts("\n\nPilha vazia\n");
}

void VerTopo(Stack *p) {
    if (!Stack_isEmpty(p)){
        int numero = Stack_top(p);
        printf("\n\nTopo da pilha: %d\n", numero);
    }
    else
        puts("\n\nPilha vazia\n");
}

void LimparPilha(Stack *p) {
    Stack_clear(p);
    puts("\n\nPilha limpa\n");
}