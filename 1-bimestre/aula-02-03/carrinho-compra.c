#include <stdio.h>

int main() {
    FILE *carrinho;
    carrinho = fopen("carrinho.txt", "r");

    if (carrinho == NULL) {
        printf("ERRO!");
        return 1;
    }
    char Alimento[30];
    int quant, i = 1;
    float valor, total = 0;

    while (fscanf(carrinho, "%s %d %f", Alimento, &quant, &valor) == 3) {
        printf("%d)%s: %d * %.2f = %.2f\n", i, Alimento, quant, valor, valor*quant);
        total += valor*quant;
        i++;
    }
    printf("Total: %.2f\n", total);
    return 0;
}