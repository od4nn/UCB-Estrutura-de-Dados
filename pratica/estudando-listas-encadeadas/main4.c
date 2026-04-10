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
    Lista *lista = NULL;

    lista = inserir(lista, 20);
    lista = inserir(lista, 10);
    lista = inserir(lista, 50);




    Lista *aux = lista;
    while (aux != NULL) {
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }
    free(lista);

    return 0;
}

