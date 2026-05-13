#include <stdlib.h>
#include <stdio.h>

void ordena (int *Vetor, int tam){
    for(int i = 0; i < tam - 1; i++){
        int min = i;
        for(int j = i + 1; j < tam; j++){
            if(Vetor[j] < Vetor[min]){
                min = j;
            }
        }

        int temp = Vetor[i];
        Vetor[i] = Vetor[min];
        Vetor[min] = temp;
    }
}

int main(){

    int vetor[4];

    for(int i = 0; i < 4; i++){
        scanf("%d", &vetor[i]);
    }

    ordena(vetor, 4);

    printf("\n");

    for(int i = 0; i < 4; i++){
        printf("Lista: %d\n", vetor[i]);
    }
}