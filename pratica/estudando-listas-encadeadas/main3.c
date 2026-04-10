#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
}Lista;

Lista *inserir (Lista *lista, int valor) {
    Lista *inicio = malloc(sizeof(Lista));
    inicio->prox = lista;
    inicio->valor = valor;
    return inicio;
}

int main() {
    Lista *lista = malloc(sizeof(Lista));
    lista->valor = 20;
    lista->prox = NULL;

    Lista *inicio_lista = inserir(lista, 10);

    Lista *aux = inicio_lista;
    while (aux != NULL) {
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }

    free(inicio_lista);
    free(lista);

    return 0;
}

