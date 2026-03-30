#include <stdio.h>
#include <string.h>

int main() {
    FILE *f = fopen("meleia.csv", "r");
    if (f == NULL) return 1;
    char LINHA[1000];
    while ((fgets(LINHA, 1000, f)) != NULL) {

        char *token = strtok(LINHA, ",");

        while (token != NULL) {
            printf("%s\n", token);
            token = strtok(NULL, ",");
        }
    }

    fclose(f);

    return 0;
}