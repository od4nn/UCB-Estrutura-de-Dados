#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p1;
    int p2;
}Point;


int main() {
    int length = 3;
    Point *array;

    array = malloc(sizeof(Point) * length);

    Point *Pato;
    Pato = &array[1];

    Pato->p1 = 23;

    array[0].p1 = 23;
    (*(array + 1)).p1 = 12;
    //array[1]->p2 = 2; errado!

    array = realloc(array, sizeof(Point) * length);

    return 0;
}