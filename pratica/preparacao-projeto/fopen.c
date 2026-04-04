#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = fopen("teste_TRE-TO.csv", "r");
    if (f == NULL) return 1;
    char LINHA[1000];
    fgets(LINHA, 1000, f);

    while ((fgets(LINHA, 1000, f)) != NULL) {
        char nome1[100], nome2[100];
        char *token = strtok(LINHA, ",");
        int i = 0;
        while (token != NULL) {
            if (i == 0) {
                strcpy(nome1, token);
            }
            if (i == 5) {
                strcpy(nome2, token);
            }
            token = strtok(NULL, ",");

            i++;
        }

        printf("%s | %s\n", nome1, nome2);
    }

    fclose(f);

    return 0;
}