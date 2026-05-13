#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

typedef struct{
    int tamanho;
    No *inicio;
    No *final;
}Lista;

void adicionar_inicio (Lista *lista, int chave) {
    No *novo_no = malloc(sizeof(No));

    if (lista->inicio == NULL) {
        novo_no->prox = novo_no;
        lista->inicio = novo_no;
        lista->final = novo_no;
        lista->tamanho++;
        return;
    }

    novo_no->prox = lista->inicio;
    lista->final->prox = novo_no;
    lista->inicio = novo_no;
    lista->tamanho++;
}

void adicionar_final (Lista *lista, int chave) {
    No *novo_no = malloc(sizeof(No));

    if (lista->final == NULL) { //circular
        novo_no->prox = novo_no;;
        lista->inicio = novo_no;
        lista->final = novo_no;
        lista->tamanho++;
        return;
    }

    novo_no->prox = lista->inicio;
    lista->final->prox = novo_no;
    lista->final = novo_no;
    lista->tamanho++;
}

int main() {
    Lista *lista = malloc(sizeof(Lista));
    lista->tamanho = 0;
    lista->inicio = NULL;
    lista->final = NULL;

    adicionar_final(lista, 10);
    adicionar_final(lista, 20);
    adicionar_final(lista, 30);
    adicionar_final(lista, 40);
    adicionar_inicio(lista, 5);

    No *aux = lista->inicio;
    if (aux == NULL) return 1;
    int contador = 0;

    do {
        contador++;
        aux = aux->prox;
    }while (aux != lista->inicio);

    printf("\nExistem %d elementos na lista.", contador);
    return 0;
}