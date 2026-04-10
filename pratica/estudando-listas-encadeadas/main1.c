#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
}Lista;

int main() {
    Lista *lista = malloc(sizeof(Lista));
    lista->prox = NULL;
    lista->valor = 20;
    printf("Valor: %d", lista->valor);

    free(lista);

    return 0;
}

// namoral cara, que negocio complicado, ta dando tanto nó no meu cerebro
