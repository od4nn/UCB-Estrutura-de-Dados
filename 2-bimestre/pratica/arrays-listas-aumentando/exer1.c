#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *dados;
    int inicio;
    int fim;
    int tamanho;
}Arraycircular;

void adicionar(Arraycircular *f, int valor) {
    if (f->tamanho == f->fim) {
        f->tamanho *= 2;
        f->dados = realloc(f->dados, sizeof(int) * f->tamanho);
    }
    f->dados[f->fim] = valor;
    f->fim++;
}

int main() {
    char resp;
    int num;

    Arraycircular fila;
    fila.dados = malloc(sizeof(int));
    fila.inicio = 0;
    fila.fim = 0;
    fila.tamanho = 1;

    while (1) {
        printf("\nDeseja adicionar um numero novo? [s/n]");
        scanf(" %c", &resp);

        if (resp == 'n') {
            break;
        }

        printf("\nInforme o numero: ");
        scanf("%d", &num);

        adicionar(&fila, num);
    }

    for (int i = 0; i < fila.fim; i++) {
        printf("\nPosicao %d: [%d]", i+1, fila.dados[i]);
    }

    return 0;
}