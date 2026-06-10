#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void double_shadow(int **p, int size) {
    //цикл увелечения каждого числа из массива на *2
    for (int i = 0; i < size; i++) {
        (*p)[i] = (*p)[i] * 2;
    }
    //выделение памяти + присваивание обьектам числа
    int *new_arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        new_arr[i] = (*p)[i];
    }
    free(*p);

    *p = new_arr;
}

int main() {
    int size;
    srand(time(NULL));

    printf("Размер массива: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    // Проверка на выделение памяти
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
    }

    // заполенние массива рандом числами
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    // вывод для проверки
    printf("Ваш массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double_shadow(&arr, size);

    printf("Новый массив и другого места памяти: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}