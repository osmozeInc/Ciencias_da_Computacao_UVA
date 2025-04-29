#include <stdio.h>
#include <stdlib.h>


int main(){
    int N = 0;
    int *vetor;

    while (N <= 0){
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);
    }

    vetor = malloc(N * sizeof(int));

    printf("vetor:\n");
    for (int i = 0; i < N; i++){
        vetor[i] = i + 2;
        printf("%d \n", vetor[i] = i + 2);
    }

    return 0;
}
