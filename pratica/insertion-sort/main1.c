#include <stdio.h>
#include <stdlib.h>

int main(){

    int V[4] = {4,2,7,1};

    for (int i = 1; i < 4; i++) { // i = 3
    int Chave = V[i];  // chave = 1    // pega o elemento atual
    int j = i - 1;

    // enquanto ainda há elementos à esquerda E eles são maiores que a Chave
    while (j >= 0 && V[j] > Chave) { // j = 2
        V[j + 1] = V[j];  // empurra o elemento uma posição para a direita
        j--;
    }
    V[j + 1] = Chave;     // insere a Chave no lugar correto
    }

    return 0;
}