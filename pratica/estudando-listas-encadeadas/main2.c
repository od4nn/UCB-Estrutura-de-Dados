#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
}Lista;

int main() {
    Lista *inicial = malloc(sizeof(Lista));
    inicial->valor = 10;

    Lista *segunda = malloc(sizeof(Lista));
    segunda->valor = 20;
    inicial->prox = segunda;
    segunda->prox = NULL;

    Lista *aux = inicial;
    while (aux != NULL) {
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }

    free (segunda);
    free (inicial);
    return 0;
}