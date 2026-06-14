#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int id;
    char name[28];
} Item;

typedef struct Node {
    Item item;
    struct Node *next;
} Node;

typedef struct {
    Item *base_array;
    size_t capacity;
    size_t size;
    Node *overflow;
} Section;

void init_section(Section *sec, size_t initial_cap) {
    sec->capacity = initial_cap;
    sec->size = 0;
    sec->base_array = malloc(initial_cap * sizeof(Item));
    sec->overflow = NULL;
}

int insert_item(Section *sec, Item item) {
    if (sec->size < sec->capacity) {
        sec->base_array[sec->size] = item;
        sec->size++;
        return 0;
    }

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        return -1;
    }

    new_node->item = item;

    new_node->next = sec->overflow;
    sec->overflow = new_node;

    return 1;
}

void free_section(Section *sec) {
    if (sec->base_array != NULL) {
        free(sec->base_array);
        sec->base_array = NULL;
    }

    Node *current = sec->overflow;
    while (current != NULL) {
        Node *next_node = current->next;
        free(current);
        current = next_node;
    }
    sec->overflow = NULL;
    sec->size = 0;
    sec->capacity = 0;
}

int main(void) {
    Section my_section;
    init_section(&my_section, 3);

    for (int i = 0; i < 5; i++) {
        Item tmp_item;
        tmp_item.id = 100 + i;
        snprintf(tmp_item.name, sizeof(tmp_item.name), "Item_%d", i);

        int res = insert_item(&my_section, tmp_item);
        printf("Insert ID %d: %s\n", tmp_item.id, (res == 0) ? "Array" : "Overflow Chain");
    }
    
    free_section(&my_section);
    printf("Memory freed successfully.\n");

    return 0;
}