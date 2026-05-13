#include <stdio.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
}Arraycircular;

void adicionar(Arraycircular *a, int valor) {
    if (a->tamanho == MAX) {
        printf("\nFila cheia!");
        return;
    }
    a->dados[a->fim] = valor;
    a->fim = (a->fim + 1) % MAX;
    a->tamanho++;
}

void remover(Arraycircular *a) {
    if (a->tamanho == 0) {
        printf("\nFila vazia!");
        return;
    }
    printf("%d foi removido.", a->dados[a->inicio]);
    a->inicio = (a->inicio + 1) % MAX;
    a->tamanho--;
}

int main() {
    int num;
    int resp;

    Arraycircular array;

    array.inicio = 0;
    array.fim = 0;
    array.tamanho = 0;

    do {
        printf("\n=== Menu ===\n\n1.Adicionar numero\n2.Remover numero\n"
               "3.Imprimir fila\n0.Sair\nEscolha:");
        scanf("%d", &resp);

        switch (resp) {
            case 1: {
                printf("\nInforme o numero: ");
                scanf("%d", &num);

                adicionar(&array, num);
                break;
            }
            case 2: {
                int idx;

                remover(&array);
                break;
            }
            case 3: {
                if (array.tamanho == 0) {
                    printf("\nFila vazia!");
                    break;
                }
                int idx = array.inicio;

                for (int i = 0; i < array.tamanho; i++) {
                    printf("[%d] ", array.dados[idx]);
                    idx = (idx + 1) % MAX;
                }

                break;
            }
            case 0: {
                printf("\nEncerrando...\n");
                break;
            }
            default: {
                printf("\nErro: resposta invalida!");
            }
        }
    }while (resp != 0);

    return 0;
}