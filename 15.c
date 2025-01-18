#include <stdlib.h>

#include <stdio.h>

#include <errno.h>
#include <time.h>

int MIN = -100;
int MAX = 100;

int** memory_alocation(int n){
    int** arr = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i<n; ++i) {
        arr [i] = (int*) malloc(n*sizeof(int));
    }
    if (arr == NULL) {
        fprintf (stderr, "Ошибка выделения памяти !\n");
        for (int i =0 ; i<n; ++i) {
            free(arr[i]);
        }
    free(arr);
    exit(1);
    }   

    return arr;
}

void fill_matrix (int** matrix, int n, int MIN, int MAX){
    for (int i = 0; i< n; ++i) {
        for (int j = 0; j< n; ++j) {
            matrix[i][j] = MIN + (float)rand() / RAND_MAX * (MAX - MIN);
        }
    }

}

void print_matrix (int** matrix, int n) {
    for (int i = 0; i<n; ++i) {
        for (int j =0; j< n; ++j) {
            fprintf(stdout, "%d\t", matrix[i][j]);

        }
        fprintf(stdout, "\n");
    }
}
int k = 0 ; // счётчик для чисел, кратных 7. Обнуляется после каждой строки.
void change_matrix(int** matrix, int n ) {
    for (int i = 0; i < n; ++i) {
        k = 0; // обнуляем перед каждым проходом по строке.
        for (int j = 0; j< n; ++j) {
            if (matrix[i][j] % 7 == 0) {
                k++;
            }
        }
        if (k != 0) {
            matrix [i][i] = k; // присваиваем диагонали (по строкам) значение, равное количеству чисел в строке, кратных 7.
        }
        else {
            matrix[i][i] = 0; // иначе присваиваем 0.
        }
    }
    fprintf(stdout, "\nПреобразованная матрица : \n");
    print_matrix(matrix, n);
}

int main () {
    srand (time (0));
    int n;
    fprintf(stdout, "Введите число n : ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Ошибка ввода !\n");
        exit(2);
    }
    int** arr = memory_alocation(n); // выделили память 
    fill_matrix(arr, n, MIN, MAX);
    fprintf(stdout, "\nИсходная матрица : \n");
    print_matrix(arr, n);

    change_matrix(arr, n);

    for (int i = 0 ; i<n; ++i) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
} 