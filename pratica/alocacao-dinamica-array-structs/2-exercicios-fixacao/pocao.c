#include <stdio.h>

typedef struct {
    int cura;
    float preco;
}Pocao;

int main() {
    Pocao inventario[5];

    inventario[4].cura = 20;
    Pocao *item_focado = &inventario[4];
    item_focado->cura = 500; //pq nao se utiliza *item_focado aqui?
    item_focado->preco = 150.0;

    printf("valores atuais itens curas: %d \t%.2f", item_focado->cura,
        item_focado->preco);
    return 0;
}