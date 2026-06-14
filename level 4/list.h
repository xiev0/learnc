#ifndef LIST_H  // Это Include Guards (защита от повторного включения файла)
#define LIST_H

#include <stddef.h>

typedef struct {
    int pid;          // ID процесса
    int priority;     // Приоритет (от 1 до 10)
} Task;

typedef struct Node {
    Task task;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head; // Указатель на первый элемент
    Node *tail; // Указатель на последний элемент
    size_t size;
} DoublyLinkedList;

#endif