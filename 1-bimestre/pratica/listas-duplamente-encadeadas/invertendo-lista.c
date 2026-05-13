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
    No *final_lista;
}Lista;

void adicionar_final(Lista *lista, int valor){
    No *novo_no = malloc(sizeof(No));
    novo_no->anterior = NULL;

    No *aux = lista->inicio_lista;
    if (aux == NULL) {
        novo_no->prox = NULL;
        novo_no->chave = valor;
        lista->inicio_lista = novo_no;
        lista->final_lista = novo_no;
        lista->tamanho++;
        return;
    }

    novo_no->prox = NULL;
    novo_no->anterior = lista->final_lista;
    lista->final_lista->prox = novo_no;
    novo_no->chave = valor;
    lista->final_lista = novo_no;
    lista->tamanho++;

}

void adicionar_inicio (Lista *lista, int valor){
    No *novo_no = malloc(sizeof(No));
    novo_no->anterior = NULL;

    if(lista->inicio_lista != NULL){
        novo_no->prox = lista->inicio_lista;
        lista->inicio_lista->anterior = novo_no;
        lista->inicio_lista = novo_no;
        novo_no->chave = valor;
        lista->tamanho++;
        return;
    }

    lista->inicio_lista = novo_no;
    lista->final_lista = novo_no;
    novo_no->prox = NULL;
    novo_no->chave = valor;
    lista->tamanho++;

}

void liberar_no (Lista *lista, int valor_alvo) {
    No *aux = lista->inicio_lista;
    while (aux != NULL) {
        if (aux->chave == valor_alvo) {
            if (aux->prox != NULL && aux->anterior != NULL) { //tem um na frente e um atras
                aux->prox->anterior = aux->anterior;
                aux->anterior->prox = aux->prox;
                free(aux);
                lista->tamanho--;
                return;
            }
            if (aux->prox != NULL) { //so na frente
                aux->prox->anterior = NULL;
                lista->inicio_lista = aux->prox;
                free(aux);
                lista->tamanho--;
                return;
            }
            if (aux->anterior != NULL) { //so atras
                aux->anterior->prox = NULL;
                lista->final_lista = aux->anterior;
                free(aux);
                lista->tamanho--;
                return;
            }
            else { //nem na frente nem atras
                lista->inicio_lista = NULL;
                lista->final_lista = NULL;
                free(aux);
                lista->tamanho--;
                return;
            }
        }
        aux = aux->prox;
    }

    printf("\nNo nao encontrado.\n");
}

void inverter_lista (Lista *lista) {
    No *aux = lista->inicio_lista;
    while (aux != NULL) {
        No *temp = aux->anterior;
        aux->anterior = aux->prox;
        aux->prox = temp;
        aux = aux->anterior;
    }
    No *temp = lista->inicio_lista;
    lista->inicio_lista = lista->final_lista;
    lista->final_lista = temp;
}

int main(){
    Lista *lista = malloc(sizeof(Lista));
    lista->tamanho = 0;
    lista->inicio_lista = NULL;
    lista->final_lista = NULL;
    int chave_alvo;

    adicionar_inicio(lista, 50);
    adicionar_inicio(lista, 40);
    adicionar_inicio(lista, 30);
    adicionar_inicio(lista, 20);
    adicionar_inicio(lista, 10);

    inverter_lista(lista);

    No *aux = lista->inicio_lista;

    while(aux != NULL){
        printf("Eu sou o No id: %d.\n", aux->chave);
        aux = aux->prox;
    }
    printf("Tamanho da lista: %d", lista->tamanho);

    free(lista);

    return 0;
}