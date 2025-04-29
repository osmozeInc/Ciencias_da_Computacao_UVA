#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    int matricula;
    char nome[50];
    int provas[3];
};

int main(){
    struct Aluno a;

    printf("Ficha do Aluno");

    printf("\n matricula: ");
    scanf("%d", &a.matricula);

    printf("\n Nome: ");
    scanf("%49s", a.nome);

    for (int i = 0; i < 3; i++){
        printf("\n prova %d: ", i + 1);
        scanf("%d", &a.provas[i]);
    }

    printf("Dados do aluno\n"
            "Nome: %s\n"
            "Matricula: %d\n"
            "Notas: \nP1: %d \nP2: %d \nP3: %d \n",
            a.nome, a.matricula, a.provas[0], a.provas[1], a.provas[2]);

    int m_espaco = sizeof(struct Aluno);
    printf("O espaco de memoria ocupado pela ficha é: %d bites", m_espaco);

    return 0;
}
