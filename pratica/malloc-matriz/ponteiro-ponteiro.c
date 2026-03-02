#include <stdio.h>
#include <stdlib.h>

int main() {

    int **mat, i, j, tam;

    printf("Informe quantas meias tera cada gaveta: ");
    scanf("%d", &tam);
    mat = (int**) malloc(tam * sizeof(int*));

    for (i = 0; i < tam; i++) {
        mat[i] = malloc(tam - 1 * sizeof(int));
    }
    return 0;
}