#include <stdio.h>

int main() {
    FILE *tabuada = fopen("tabuada.txt", "w");

    for (int i = 0; i <= 10; i++) {
        fprintf(tabuada, "\n%d x %d = %d", 7, i, 7 * i);
    }
    fclose(tabuada);

    return 0;
}