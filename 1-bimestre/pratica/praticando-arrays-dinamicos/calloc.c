#include <stdio.h>

int main() {
    int *x = calloc(3, sizeof(int)); //os elementos ao inves de conter lixo como
    //no malloc sao preenchidos com zeros

    if (x) {
        x[0] = 10; // Primeiro elemento
        x[1] = 20; // Segundo elemento
        x[2] = 30; // Terceiro elemento

        printf("Posicao 1: %d\n", x[1]); // Mostra 20
    }
    return 0;
}