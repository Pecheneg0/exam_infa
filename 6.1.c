#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// Функция считывает диапазон для заполнения числами
void scanf_range(int* MIN, int* MAX) {
    printf("Введите диапазон заполнения массива:\n");
    printf("\tВведите MIN: ");
    if (scanf("%d", MIN) != 1) {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    printf("\tВведите MAX: ");
    if (scanf("%d", MAX) != 1) {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    if (*MIN > *MAX) {
        printf("Ошибка: MIN не может быть больше MAX.\n");
        exit(1);
    }
}

// Функция заполнения матрицы
void fill_matrix(int** matrix, int rows, int columns, int* MIN, int* MAX) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = *MIN + (rand() / (float)RAND_MAX) * (*MAX - *MIN);
        }
    }
}

// Функция вывода матрицы
void print_matrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Функция удаления строк
void change_matrix(int** matrix, int* rows, int columns) {
    for (int i = 0; i < *rows; ++i) {
        if (matrix[i][0] % 2 == 0) {
            for (int k = i + 1; k < *rows; ++k) {
                for (int j = 0; j < columns; ++j) {
                    matrix[k - 1][j] = matrix[k][j];
                }
            }
            (*rows)--;
            i--; // Повторно проверить текущую строку
        }
    }
    printf("\n\nИзменённая матрица:\n");
    print_matrix(matrix, *rows, columns);
}

int main() {
    int temp_min, temp_max;
    srand(time(0));
    int n, m;

    printf("Введите количество строк: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 20) {
        printf("Ошибка ввода!\n");
        exit(1);
    }
    printf("Введите количество столбцов: ");
    if (scanf("%d", &m) != 1 || m < 1 || m > 20) {
        printf("Ошибка ввода!\n");
        exit(1);
    }

    // Создание динамической матрицы
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        arr[i] = (int*)malloc(m * sizeof(int));
    }

    // Считывание диапазона
    scanf_range(&temp_min, &temp_max);

    // Заполнение матрицы
    fill_matrix(arr, n, m, &temp_min, &temp_max);

    // Вывод матрицы
    printf("Исходная матрица:\n");
    print_matrix(arr, n, m);

    // Изменение матрицы
    change_matrix(arr, &n, m);

    // Освобождение памяти
    for (int i = 0; i < n; ++i) {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;

    return 0;
}
