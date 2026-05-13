#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int **mat, i, j, tam;

    printf("Informe quantas meias tera cada gaveta: ");
    scanf("%d", &tam);
    mat = (int**) malloc(tam * sizeof(int*));

    for (i = 0; i < tam; i++) {
        mat[i] = malloc(tam * sizeof(int));
    }
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++) {
            *(*(mat + i) + j) = rand() % 100;
            printf("Gaveta %d\t Meia:%d\n", i+1, *(*(mat + i) + j));
        }

    }
    free(mat);
    return 0;
}