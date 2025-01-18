#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

// Функция считывает диапозон для заполнения числами
void scanf_range (int* MIN, int* MAX) {
    
    printf("Введите диапозон заполнения массива :\n");
    printf("\tВведите MIN : ");
    if (scanf("%d", MIN)!= 1 ) {
        printf("Ошибка ввода! ");
        exit (1);
    }
    printf ("\tВведите MAX : ");
    if (scanf("%d",MAX)!= 1 ) {
        printf("Ошибка ввода! ");
        exit (1);
    }

}
// Функция заполнения матрицы
void fill_matrix (int** matrix, int rows, int columns, int* MIN, int* MAX) {
    for (int i = 0; i< rows; ++i) {
        for (int j = 0; j<columns; ++j) {
            matrix[i][j] = *MIN + (rand()/ (float)RAND_MAX) * (*MAX - *MIN); //преобразрвали тип данных, чтобы получались рандомные числа
        }
    }
} 
// Функция вывода матрицы
void print_matrix (int **matrix, int rows, int columns) {
    for (int i = 0; i< rows; ++i) {
        for (int j = 0; j<columns; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
// функция удаления строк
void change_matrix (int** matrix, int *rows, int columns) {
    bool remove = false;
    for (int i = 0; i<*rows ; ++i) { 
        if (matrix [i][0] % 2 == 0) { // операция деления без остатка применима только к int !
            remove = true;
            break;
            }
        
        if (remove) {
           
            for (int k = i+1; k<*rows; ++k){
                for (int j =0; j<columns ; ++j ){
                    matrix [k-1][j] = matrix [k][j];
                }
            }
            --(*rows);
            --i;
        }
    }
    printf("\n\nИзменённая матрица : \n");
    print_matrix(matrix, *rows, columns);
}

int main () {

    int temp_min, temp_max;
    srand(time(0));
    int n, m;


    printf("Введите количество строк :");
    if (scanf("%d", &n)!= 1 || n<1 || n >20) {
        printf("Ошибка ввода! ");
        exit (1);
    } 
    printf("Введите количество столбцов :");
    if (scanf("%d", &m)!= 1 || m<1 || m >20) {
        printf("Ошибка ввода! ");
        exit (1);
    }  

    int** arr = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i<n; ++i) {
        arr[i] = (int*) malloc(m * sizeof(int));
    }

    scanf_range(&temp_min, &temp_max);

    fill_matrix(arr, n , m, &temp_min, &temp_max);

    print_matrix(arr, n ,m);
    
    change_matrix(arr, &n, m);
    


    for (int i =0; i< n ; ++i) {
    free (arr[i]);
 
    }
    free (arr);
    arr = NULL;
return 0;
}