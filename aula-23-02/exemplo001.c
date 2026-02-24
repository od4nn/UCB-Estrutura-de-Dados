#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Hello UCB!");
    /*system ("rmdir /s Estrutura_de_dados");
    system("rmdir /s Logica_de_programacao");*/
    FILE *arquivo;

    arquivo = fopen("arquivo.txt", "w");
    fprintf(arquivo, "Hello monster");

    fclose(arquivo);
    return 0;
}
