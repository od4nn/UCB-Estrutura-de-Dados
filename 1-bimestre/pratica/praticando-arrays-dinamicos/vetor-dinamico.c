#include <stdio.h>
#include <stdlib.h>

int main() {
    int tam;

    printf("Informe quantos numeros deseja informar: ");
    scanf("%d", &tam);

    int *vetor = (int*) malloc(sizeof(int) * tam);

    if (vetor == NULL) {
        return 1;
    }

    for (int i = 0; i <= tam; i++) {
        *(vetor+1) = 1 + i;
        printf("\n%d", vetor[i]);
    }
    printf("\nUltimo: %d", *(vetor+1));
    free(vetor);

    return 0;
}