#include <stdio.h>

int main() {
    FILE *dados;
    dados = fopen("dados.csv", "r");
    if (!dados) {
        return 1;
    }

    int ID, idade;
    char nome[30];
    while (fscanf(dados,"%d,%[^,], %d", &ID, nome, &idade) == 3) {
        printf("%d\t %s\t %d\n", ID,nome, idade);
    }
    fclose(dados);
    return 0;
}