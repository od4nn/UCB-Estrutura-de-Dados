#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int bola1;
    int bola2;
}Cone;

int main() {
    Cone *array;

    array = (Cone*)malloc(sizeof(Cone));
    if (array == NULL) {
        printf("ERRO!");
        return 1;
    }
    array->bola1 = 6;
    array->bola2 = 4;

    printf("%d %d", array->bola1, array->bola2);
    free(array);
    return 0;
}