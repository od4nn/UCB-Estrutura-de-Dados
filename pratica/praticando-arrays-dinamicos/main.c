#include <stdio.h>
#include <stdlib.h>

int main() {

    int *x;

    x = malloc(sizeof(int));

    //mesma coisa
    if (x) {

    }
    if (x != NULL) {

    }

    int n;
    int *vator;

    printf("Quantos números você quer guardar? ");
    scanf("%d", &n); // O programa já está rodando!

    // Agora o "superpoder": alocamos exatamente o que o usuário pediu
    vator = malloc(n * sizeof(int));

    if (vator == NULL) {
        printf("Erro: Memória cheia!\n");
        return 1;
    }

    // Preenchendo o array dinâmico
    for (int i = 0; i < n; i++) {
        vator[i] = i * 10;
        printf("vator[%d] = %d\n", i, vator[i]);
    }
    return 0;
}