//Crie uma função recursiva para realizar a soma de todos os elementos de um vetor de números reais.

#include <stdio.h>

float SomarTodosElementosDoVetor(float vetor[], float soma, int iteracao, int parada){
    if (iteracao < parada){

        soma += vetor[iteracao];
        soma = SomarTodosElementosDoVetor(vetor, soma, iteracao + 1, parada);
    }

    return soma;
}

void ImprimirTodosElementosDoVetor(float vetor[], int iteracao, int parada){
    if (iteracao < parada){
        printf("{%g} ", vetor[iteracao]);
        ImprimirTodosElementosDoVetor(vetor, iteracao + 1, parada);
    }
}

int main(){
    float float_vetor[] = {1, 0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625};
    float soma = 0;
    int tamanho = sizeof(float_vetor) / sizeof(float_vetor[0]);


    soma = SomarTodosElementosDoVetor(float_vetor, soma, 0, tamanho);

    printf("Vetor: ");
    ImprimirTodosElementosDoVetor(float_vetor, 0, tamanho);

    printf("\nA soma de todos os elementos do vetor é: %g\n\n", soma);

    return 0;
}
