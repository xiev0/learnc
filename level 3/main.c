#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int critical_chance;
    float weight;
} Stats;

typedef struct {
    char title[32];
    int damage;
    Stats spec;
} Weapon;


Weapon* init_weapon(const char* title, int damage, int crit, float weight) {
    Weapon *init = malloc(sizeof(Weapon));
    if (init == NULL) return NULL;

    strcpy(init->title, title);
    init->damage = damage;


    init->spec.critical_chance = crit;
    init->spec.weight = weight;

    return init;
}

void use_weapon_damage(Weapon *init, int damage) {
    if (init == NULL) return;
    init->damage -= damage;
    if (init->damage < 0) init->damage = 0;
}

void use_weapon_critical_chance(Weapon *init, int critical_chance) {
    if (init == NULL) return;


    init->spec.critical_chance -= critical_chance;
    if (init->spec.critical_chance < 0)
        init->spec.critical_chance = 0;
}

int main () {
    Weapon *weapon = init_weapon("Sekiro", 15, 5, 1.2f);
    if (weapon == NULL) {
        printf("Не удалось выделить память\n");
        return 1;
    }
    
    printf("Оружие: %s, Урон: %d, Вес: %.1f, Крит: %d%%\n",
           weapon->title, weapon->damage, weapon->spec.weight, weapon->spec.critical_chance);

    use_weapon_critical_chance(weapon, 2);

    printf("После изменения крита - Крит: %d%%\n", weapon->spec.critical_chance);

    free(weapon);
    weapon = NULL;

    return 0;
}