#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int num;
    int *vator;
    srand(time(NULL));

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &num);

    int *temp = (int*) malloc(sizeof(int) * num);

    if (temp != NULL) {
        vator = temp;
    }
    else {
        return 1;
    }

    for (int i = 0; i < num; i++) {
        *(vator + i) = rand() % 100;
        printf("%d ", *(vator + i));
    }

    printf("\nInforme o novo tamanho: ");
    scanf("%d", &num);

    temp = (int*) realloc(temp, sizeof(int) * num);

    if (temp != NULL) {
        vator = temp;
    }
    else {
        return 1;
    }
    printf("\nNovos valores: \n");
    for (int i = 0; i < num; i++) {
        *(vator + i) = rand() % 100;
        printf("%d ", *(vator + i));
    }
    free(vator);
    vator = NULL;
    return 0;
}
