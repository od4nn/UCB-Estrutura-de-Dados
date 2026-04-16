#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
    struct no *anterior;
}No;

typedef struct{
    int tamanho;
    No *inicio_lista;
}Lista;

No *adicionar_final(Lista *lista, int valor){
    No *novo_no = malloc(sizeof(No));
    novo_no->anterior = NULL;

    No *aux = lista->inicio_lista;
    if (aux == NULL) {
        novo_no->prox = NULL;
        novo_no->chave = valor;
        lista->inicio_lista = novo_no;
        lista->tamanho++;
        return novo_no;
    }

    while(aux != NULL){
        if(aux->prox == NULL){ //significa o fim da lista
            aux->prox = novo_no;
            novo_no->prox = NULL;
            novo_no->anterior = aux;
            novo_no->chave = valor;
            lista->tamanho++;
            break;
        }
        aux = aux->prox;
    }    

    return novo_no;
}

No *adicionar_inicio (Lista *lista, int valor){
    No *novo_no = malloc(sizeof(No));
    novo_no->anterior = NULL;

    if(lista->inicio_lista != NULL){
        novo_no->prox = lista->inicio_lista;
        lista->inicio_lista->anterior = novo_no;
        lista->inicio_lista = novo_no;
        novo_no->chave = valor;
        lista->tamanho++;
        return novo_no;
    }

    lista->inicio_lista = novo_no;
    novo_no->prox = NULL;
    novo_no->chave = valor;
    lista->tamanho++;

    return novo_no;
}

int main(){
    
    Lista *lista = malloc(sizeof(Lista));
    lista->tamanho = 0;
    lista->inicio_lista = NULL;

    adicionar_final(lista, 241);
    adicionar_inicio(lista, 213);
    adicionar_inicio(lista, 412);
    adicionar_inicio(lista, 411);
    adicionar_final(lista, 912);
    adicionar_final(lista, 472);

    
    No *aux = lista->inicio_lista;

    while(aux != NULL){
        printf("Eu sou o No id: %d.\n", aux->chave);
        aux = aux->prox;
    }
    printf("Tamanho da lista: %d", lista->tamanho);
    return 0;
    
}