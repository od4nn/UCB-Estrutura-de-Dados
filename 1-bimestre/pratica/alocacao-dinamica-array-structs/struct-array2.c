#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p1;
    int p2;
}Ponto;

int main() {
    Ponto b;
    b.p1 = 4;
    b.p2 = 6;

    printf("B:\n P1 = %d\n P2 = %d\n", b.p1, b.p2);

    Ponto *r = (Ponto*) malloc(sizeof(Ponto));

    r->p1 = 22;
    r->p2 = 23;
    //(*r).p2 = 23; tambem funciona

    printf("R:\n p1 = %d\n p2 = %d\n", r->p1, r->p2);
    free(r);
    return 0;
}