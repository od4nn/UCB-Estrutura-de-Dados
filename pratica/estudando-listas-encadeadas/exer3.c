#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
}Lista;

Lista *inserir_final(Lista *inicio, int valor);
Lista *busca_numero(Lista *inicio, int valor);

int main() {
    Lista *lista = NULL;

    lista = inserir_final(lista, 10);
    lista = inserir_final(lista, 20);
    lista = inserir_final(lista, 30);
    lista = inserir_final(lista, 40);

    Lista *localizado = busca_numero(lista, 40);

    printf("\nValor encontrado: %d", localizado->valor);

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

Lista *busca_numero(Lista *inicio, int valor) {
    if (inicio == NULL) {
        printf("\nA lista esta vazia.");
        exit(1);
    }
    int contador = 0;
    Lista *aux = inicio;
    while (aux != NULL) {
        if (aux->valor == valor) {
            contador++;
            printf("Valor encontrado no nó %d.", contador);
            return aux;
        }
        contador++;
        aux = aux->prox;
    }
    printf("\nO valor nao foi encontrado.");
    exit(0);
}