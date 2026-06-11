#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Weapon {
    char title[32];
    int damage;
    int durability;
};

struct Weapon* init_weapon (const char* title, int damage, int durability) {
    struct Weapon *init = malloc(sizeof(struct Weapon));
    if (init == NULL) {
        return NULL;
    }

    strcpy (init->title, title);
    init->damage = damage;
    init->durability = durability;

    return init;
}

void use_weapon_durability(struct Weapon *init, int durability) {
    if (init == NULL) return;

    init->durability -= durability;
    if (init->durability < 0)
        init->durability = 0;
}

void use_weapon_damage(struct Weapon *init, int damage) {
    if (init == NULL) return;

    init->damage -= damage;
    if (init->damage < 0)
        init->damage = 0;
}

int main () {
    struct Weapon *weapon = init_weapon("Sekiro", 15, 5);
    if (weapon == NULL) {
        printf("Не удалось выделить память\n");
        return 1;
    }

    printf("Оружие: %s, Урон: %d, Снижение защиты: %d\n", weapon->title, weapon->damage, weapon->durability);
    use_weapon_durability(weapon, 1);
    use_weapon_damage(weapon, 3);

    printf("Последствия от удара %s : Урон: %d, Снижение защиты: %d\n", weapon->title, weapon->damage, weapon->durability);
    free(weapon);
    weapon = NULL;

    return 0;
}