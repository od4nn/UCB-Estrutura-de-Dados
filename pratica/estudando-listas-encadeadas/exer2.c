#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
}Lista;

Lista *inserir_final(Lista *inicio, int valor);
int conta_no(Lista *inicio);

int main() {
    Lista *lista = NULL;

    lista = inserir_final(lista, 10);
    lista = inserir_final(lista, 20);
    lista = inserir_final(lista, 30);
    lista = inserir_final(lista, 40);

    Lista *aux = lista;
    while (aux != NULL) {
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }

    int quant_nos = conta_no(lista);

    printf("\nA lista tem %d nos.\n", quant_nos);

    Lista *liberar = lista;
    while (liberar != NULL) {
        Lista *proximo = liberar->prox; // salva o próximo ANTES de liberar
        free(liberar);                  // agora pode liberar
        liberar = proximo;              // avança pro próximo
    }

    return 0;
}

Lista *inserir_final(Lista *inicio, const int valor) {
    Lista *cauda = malloc(sizeof(Lista));
    cauda->valor = valor;
    cauda->prox = NULL;

    if (inicio == NULL) {
        return cauda;
    }

    Lista *aux = inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = cauda;
    return inicio;
}

int conta_no(Lista *inicio) {
    if (inicio == NULL) {
        printf("\nA lista esta vazia.");
        exit(1);
    }
    int contador = 0;
    while (inicio != NULL) {
        contador++;
        inicio = inicio->prox;
    }
    return contador;
}