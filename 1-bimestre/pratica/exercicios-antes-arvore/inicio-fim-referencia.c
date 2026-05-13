#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
    struct no *anterior;
}No;

typedef struct{
    int tamanho;
    No *inicio;
    No *final;
}Lista;

void adicionar_inicio (Lista *lista, int chave) {
    No *novo_no = malloc(sizeof(No));

    if (lista->inicio == NULL) {
        novo_no->prox = NULL;
        novo_no->anterior = NULL;
        lista->inicio = novo_no;
        lista->final = novo_no;
        novo_no->chave = chave;
        lista->tamanho++;
        return;
    }

    novo_no->prox = lista->inicio;
    lista->inicio->anterior = novo_no;
    novo_no->anterior = NULL;
    novo_no->chave = chave;
    lista->inicio = novo_no;
    lista->tamanho++;
}

void adicionar_final (Lista *lista, int chave) {
    No *novo_no = malloc(sizeof(No));

    if (lista->inicio == NULL) {
        novo_no->prox = NULL;
        novo_no->anterior = NULL;
        novo_no->chave = chave;
        lista->inicio = novo_no;
        lista->final = novo_no;
        lista->tamanho++;
        return;
    }

    lista->final->prox = novo_no;
    novo_no->anterior = lista->final;
    novo_no->prox = NULL;
    novo_no->chave = chave;
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


    No *aux = lista->inicio;
    while (aux != NULL) {
        printf("\nValor: %d", aux->chave);
        aux = aux->prox;
    }
    return 0;
}