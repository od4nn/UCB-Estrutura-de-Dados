#include <stdio.h>
#include <stdlib.h>

void selectionSort(int V[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (V[j] < V[min]) {
                min = j;
            }
        }

        int temp = V[i];
        V[i] = V[min];
        V[min] = temp;
    }
}

int main(){
    int Vetor[4] = {2,5,1,6};
    int num = 4;
    selectionSort(Vetor, num);

    printf("Vetor: %d", Vetor);
}