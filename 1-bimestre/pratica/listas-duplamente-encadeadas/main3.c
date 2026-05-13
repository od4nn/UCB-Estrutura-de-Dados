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

void adicionar_meio (Lista *lista, int valor){
    No *novo_no = malloc(sizeof(No));

    int elemento_alvo;

    if (lista->tamanho == 0){
        novo_no->prox = NULL;
        novo_no->anterior = NULL;
        novo_no->chave = valor;
        lista->inicio_lista = novo_no;
        lista->final_lista = novo_no;
        lista->tamanho++;
        return;
    }

    if(lista->tamanho == 1){
        No *aux = lista->inicio_lista;
        aux->prox = novo_no;
        novo_no->anterior = aux;
        novo_no->prox = NULL;
        novo_no->chave = valor;
        lista->tamanho++;
        return;
    }


    if (lista->tamanho % 2 != 0) {  //se for par
        elemento_alvo = (lista->tamanho / 2) + 1;
        //se for: 1 2 3 N 4 5
        //              ^ vai ser colocado aqui se for impar
    }

    else {
        elemento_alvo = lista->tamanho / 2;
        // se for par
        //se for: 1 2 N 4 5
        //            ^ entra aqui
    }

        No *aux = lista->inicio_lista;
        for(int contador = 1; contador <= elemento_alvo; contador++){
            if(contador == elemento_alvo){
                aux->prox->anterior = novo_no;
                novo_no->prox = aux->prox;
                novo_no->anterior = aux;
                aux->prox = novo_no;
                novo_no->chave = valor;
                lista->tamanho++;
                break;
            }
            aux = aux->prox;
        }
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

int main(){
    Lista *lista = malloc(sizeof(Lista));
    lista->tamanho = 0;
    lista->inicio_lista = NULL;
    lista->final_lista = NULL;
    int chave_alvo;

    adicionar_inicio(lista, 213);
    adicionar_final(lista, 241);
    adicionar_final(lista, 912);
    adicionar_final(lista, 472);

    printf("Informe a chave do no que voce quer liberar: ");
    scanf("%d", &chave_alvo);

    liberar_no(lista, chave_alvo);

    No *aux = lista->inicio_lista;

    while(aux != NULL){
        printf("Eu sou o No id: %d.\n", aux->chave);
        aux = aux->prox;
    }
    printf("Tamanho da lista: %d", lista->tamanho);

    free(lista);

    return 0;
}