#include "list.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void init_list(DoublyLinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void push_back(DoublyLinkedList *list, Task task) {
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) return;

    new_node->task = task;

    if (list->head == NULL) {
        new_node->prev = NULL;
        new_node->next = NULL;
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        new_node->next = NULL;
        list->tail = new_node;
    }

    list->size++;
}

Node* find_task_by_pid(DoublyLinkedList *list, int pid) {
    Node *current = list->head; // Встаем на начало цепи

    while (current != NULL) {
        // 1. Проверяем, тот ли это PID, который мы ищем?
        if (current->task.pid == pid)
            return current;

        // 2. Если не тот, прыгаем на следующий узел по стрелочке вперед!
        current = current->next;
    }
    return NULL;
}

int remove_node(DoublyLinkedList *list, Node *node) {
    if (node == NULL || list == NULL) return -1;

    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        list->head = node->next;
    }

    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        list->tail = node->prev;
    }
    free(node);
    list->size--;
    return 0;
}