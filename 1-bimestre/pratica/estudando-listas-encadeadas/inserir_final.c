#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} Lista;

Lista *inserir_no_final(Lista *inicio, int valor) ;

int main() {
    Lista *lista = NULL;

    lista = inserir_no_final(lista, 10);
    lista = inserir_no_final(lista, 20);
    lista = inserir_no_final(lista, 30);

    Lista *aux = lista;
    while (aux != NULL) {
        printf("Valor: %d\n", aux->valor);
        aux = aux->prox;
    }
    return 0;
}

Lista *inserir_no_final(Lista *inicio, int valor) {
    Lista *novo = malloc(sizeof(Lista));
    novo->valor = valor;
    novo->prox = NULL;

    // se a lista tiver vazia, o novo nó é o primeiro
    if (inicio == NULL) {
        return novo;
    }

    // percorre até achar a cauda
    Lista *aux = inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    // aux agora é a cauda, conecta o novo nó
    aux->prox = novo;

    return inicio; // o início não muda quando insere no final
}