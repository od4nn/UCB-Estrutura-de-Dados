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

No *adicionar_final(Lista *lista){
    No *novo_no = malloc(sizeof(No));

    No *aux = lista->inicio_lista;
    while(aux != NULL){
        if(aux->prox == NULL){ //significa o fim da lista
            aux->prox = novo_no;
            novo_no->anterior = aux;
            novo_no->prox = NULL;
            novo_no->chave = aux->chave + 1;
            break;
        }
        aux = aux->prox;
    }    

    return novo_no;
}

No *adicionar_inicio (Lista *lista){
    No *novo_no = malloc(sizeof(No));
    novo_no->anterior = NULL;

    if(lista->inicio_lista != NULL){
        novo_no->prox = lista->inicio_lista;
        lista->inicio_lista->anterior = novo_no;
        lista->inicio_lista = novo_no;
        
        No *aux = lista->inicio_lista;
        int contador = 1;

        while(aux != NULL){
            aux->chave = contador;
            contador++;
            aux = aux->prox;
        }

        return novo_no;
    }

    lista->inicio_lista = novo_no;
    novo_no->prox = NULL;
    novo_no->chave = 1;

    return novo_no;
}

int main(){
    
    Lista *lista = malloc(sizeof(Lista));
    lista->tamanho = 0;
    lista->inicio_lista = NULL;

    adicionar_inicio(lista);
    adicionar_inicio(lista);
    adicionar_inicio(lista);
    adicionar_final(lista);
    adicionar_final(lista);
    adicionar_final(lista);
    
    No *aux = lista->inicio_lista;

    while(aux != NULL){
        printf("Eu sou o No n%d.\n", aux->chave);
        aux = aux->prox;
    }

    return 0;
    
}