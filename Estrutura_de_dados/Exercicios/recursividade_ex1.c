//Crie uma função recursiva para a impressão de um vetor de números inteiros.

#include <stdio.h>

void ImprimirTodosElementosDoVetor(int vetor[7], int iteracao, int parada){
    if (iteracao < parada){
        printf("{%d} ", vetor[iteracao]);
        ImprimirTodosElementosDoVetor(vetor, iteracao + 1, parada);
    }
}

int main(){
    int int_vetor[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int tamanho = sizeof(int_vetor) / sizeof(int_vetor[0]);


    ImprimirTodosElementosDoVetor(int_vetor, 0, tamanho);

    return 0;
}
