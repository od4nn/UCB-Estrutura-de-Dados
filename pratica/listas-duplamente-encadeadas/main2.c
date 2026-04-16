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

No *adicionar_meio (Lista *lista, int valor){
    No *novo_no = malloc(sizeof(No));

    int elemento_alvo;
    
    if (lista->tamanho == 0){ 
        novo_no->prox = NULL;
        novo_no->anterior = NULL;
        novo_no->chave = valor;
        lista->inicio_lista = novo_no;
        lista->tamanho++;
        return novo_no;
    }

    if(lista->tamanho == 1){
        No *aux = lista->inicio_lista;
        aux->prox = novo_no;
        novo_no->anterior = aux;
        novo_no->prox = NULL;
        novo_no->chave = valor;
        lista->tamanho++;
        return novo_no;
    }

    if (lista->tamanho % 2 != 0){ //se for par
        elemento_alvo = (lista->tamanho / 2) + 1; //decidi que vai ser colocado a frente do numero do meio atual
        //se for: 1 2 3 N 4 5 
        //              ^ vai ser colocado aqui se for impar
        No *aux = lista->inicio_lista;
        for(int contador = 1; contador <= elemento_alvo; contador++){
            if(contador == elemento_alvo){
                aux->prox->anterior = novo_no;
                novo_no->prox = aux->prox;
                novo_no->anterior = aux;
                aux->prox = novo_no;
                novo_no->chave = valor;
                lista->tamanho++;
                return novo_no;
            }
            aux = aux->prox;
        }
    }

    else { // se for par
    //se for: 1 2 N 4 5
    //            ^ entra aqui 
        elemento_alvo = (lista->tamanho / 2);
        No *aux = lista->inicio_lista;
        for(int contador = 1; contador <= elemento_alvo; contador++){
            if(contador == elemento_alvo){
                aux->prox->anterior = novo_no;
                novo_no->prox = aux->prox;
                novo_no->anterior = aux;
                aux->prox = novo_no;
                novo_no->chave = valor;
                lista->tamanho++;
                return novo_no;
            }
            aux = aux->prox;
        }
    }
}

int main(){
    
    Lista *lista = malloc(sizeof(Lista));
    lista->tamanho = 0;
    lista->inicio_lista = NULL;

    adicionar_inicio(lista, 213);
    adicionar_inicio(lista, 412);
    adicionar_meio(lista, 331);
    //adicionar_inicio(lista, 411);
    //adicionar_final(lista, 241);
    //adicionar_final(lista, 912);
    //adicionar_final(lista, 472);

    
    No *aux = lista->inicio_lista;

    while(aux != NULL){
        printf("Eu sou o No id: %d.\n", aux->chave);
        aux = aux->prox;
    }
    printf("Tamanho da lista: %d", lista->tamanho);

    return 0;
}