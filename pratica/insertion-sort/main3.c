#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int idade;
    char NOME[100];
    int dinheiro;
}Lista;

int main(){
    Lista lista[100];

    int tam = sizeof(lista) / sizeof(lista[50]);
    printf("Tamanho %d", tam);
}