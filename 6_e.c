#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Функция для выделения памяти под матрицу
int** memory_allocation(int* rows, int* columns) {
    int** matrix = (int**)malloc(*rows * sizeof(int*));
    if (matrix == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(1);
    }
    for (int i = 0; i < *rows; ++i) {
        matrix[i] = (int*)malloc(*columns * sizeof(int));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            // Освобождаем ранее выделенную память
            for (int j = 0; j < i; ++j) {
                free(matrix[j]);
            }
            free(matrix);
            exit(1);
        }
    }
    return matrix;
}

// Функция для освобождения памяти
void free_all(int* rows, int* columns, int* MIN, int* MAX) {
    free(rows);
    free(columns);
    free(MIN);
    free(MAX);
}

// Функция для заполнения матрицы случайными числами
void fill_matrix(int** matrix, int* rows, int* columns, int* MIN, int* MAX) {
    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < *columns; ++j) {
            matrix[i][j] = *MIN + rand() % (*MAX - *MIN + 1); // Случайное число в диапазоне [MIN, MAX]
        }
    }
}

// Функция для вывода матрицы
void printmatrix(int** matrix, int* rows, int* columns) {
    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < *columns; ++j) {
            fprintf(stdout, "%d\t", matrix[i][j]);
        }
        fprintf(stdout, "\n");
    }
}

// Функция для изменения матрицы
void change_matrix(int** matrix, int* rows, int* columns) {
    int cols = *columns; // Локальная переменная для работы с количеством столбцов
    for (int j = 0; j < cols; ++j) {
        if (matrix[0][j] % 3 == 0) {
            // Удаляем столбец j
            for (int k = j + 1; k < cols; ++k) {
                for (int i = 0; i < *rows; ++i) {
                    matrix[i][k - 1] = matrix[i][k];
                }
            }
            cols--; // Уменьшаем количество столбцов
            j--;    // Проверяем текущий столбец снова
        }
    }
    *columns = cols; // Обновляем значение columns в вызывающем коде

    fprintf(stdout, "\nИзменённая матрица:\n");
    printmatrix(matrix, rows, columns);
}

int main() {
    srand(time(0));

    int* n = malloc(sizeof(int));
    int* m = malloc(sizeof(int));
    int* MIN = malloc(sizeof(int));
    int* MAX = malloc(sizeof(int));

    if (n == NULL || m == NULL || MIN == NULL || MAX == NULL) {
        fprintf(stdout, "\nОшибка выделения памяти. ");
        free_all(n, m, MIN, MAX);
        exit(1);
    }

    fprintf(stdout, "\nВведите количество строк: ");
    if (scanf("%d", n) != 1 || *n > 20 || *n <= 0) {
        fprintf(stdout, "Ошибка ввода ");
        free_all(n, m, MIN, MAX);
        exit(2);
    }

    fprintf(stdout, "\nВведите количество столбцов: ");
    if (scanf("%d", m) != 1 || *m > 20 || *m <= 0) {
        fprintf(stdout, "Ошибка ввода ");
        free_all(n, m, MIN, MAX);
        exit(3);
    }

    fprintf(stdout, "\nВведите минимальный элемент: ");
    if (scanf("%d", MIN) != 1) {
        fprintf(stdout, "Ошибка ввода ");
        free_all(n, m, MIN, MAX);
        exit(4);
    }

    fprintf(stdout, "\nВведите максимальный элемент: ");
    if (scanf("%d", MAX) != 1 || *MAX < *MIN) {
        fprintf(stdout, "Ошибка ввода ");
        free_all(n, m, MIN, MAX);
        exit(5);
    }

    fprintf(stdout, "\n\tRows: %d", *n);
    fprintf(stdout, "\n\tColumns: %d", *m);

    int** arr = memory_allocation(n, m);
    fill_matrix(arr, n, m, MIN, MAX);
    fprintf(stdout, "\nИсходная матрица:\n");
    printmatrix(arr, n, m);

    change_matrix(arr, n, m);

    free_all(n, m, MIN, MAX);
    for (int i = 0; i < *n; ++i) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}