#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ano;
    int velocidade;
}Carro;

int main() {
    int tam = 2;

    Carro **frota = malloc(sizeof(Carro*) * tam);

    frota[0] = malloc(sizeof(Carro));

    frota[0]->ano = 2024;
    frota[0]->velocidade = 250;

    printf("Carro 0: Ano %d,"
           " Vel Máxima %d km/h\n", frota[0]->ano, frota[0]->velocidade);

    free(frota[0]);
    free(frota);
    return 0;
}