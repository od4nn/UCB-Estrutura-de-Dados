#include <stdio.h>

typedef struct {
    int hp;
    int atq;
}Monstro;

int main() {
    Monstro horda[3];

    horda[2].hp = 50;
    horda[2].atq = 10;

    Monstro *boss;
    boss = &horda[2];

    boss->hp = 500;
    boss->atq = 100;

    printf("Status do Boss na horda[2]:"
           " HP = %d, Ataque = %d\n", horda[2].hp, horda[2].atq);

    return 0;
}