#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    float nota;
}Aluno;

int main() {
    Aluno **turma = malloc(sizeof(Aluno*) * 3);
    turma[1] = malloc(sizeof(Aluno));
    turma[1]->matricula = 1010;
    turma[1]->nota = 9.0;

    printf("Matricula:%d\nNota:%.2f\n", turma[1]->matricula, turma[1]->nota);
    free(turma[1]);
    free(turma);
    return 0;
}