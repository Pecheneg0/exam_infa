#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int n , m;
float MIN, MAX;


void fill_mairix (float** matrix, int rows, int columns, float min_z, float max_z) {
    for (int i = 0; i< rows; ++i) {
        for (int j = 0; j<columns; ++j) {
            matrix [i][j] = min_z + (rand() / (float)RAND_MAX) * (max_z - min_z);
        }
    }
}

void print_matrix (float** matrix, int rows, int columns) {
    for (int i = 0; i<rows; ++i) {
        for (int j = 0; j<columns; ++j) {
            fprintf(stdout, "%f\t", matrix[i][j]);
        }
        fprintf(stdout, "\n");
    }
}

float** memory_allocation (int rows, int columns){
   float** arr = (float**) malloc(rows * sizeof(float*));
    for (int i = 0; i< rows; ++i) {
        arr[i] = (float*) malloc(columns  * sizeof(float));
    } 
return arr; 
}

void change_matrix (float** matrix, int rows, int columns){
    float max_Sum = -2.e5;
    float min_Sum = 2.e5;
    int min_column = 0;
    int max_column = 0;
    float Sum = 0; // Переменная хранящая сумму элементам по столбцам
    for (int j = 0; j<columns; ++j) {
        Sum = 0;
        for (int i = 0; i < rows; ++i){
            Sum += matrix[i][j];
            
        }
        if (Sum > max_Sum) {
            max_Sum = Sum;
            max_column = j; 
        }
        if (Sum < min_Sum) {
            min_Sum = Sum;
            min_column = j;
        }
        fprintf(stdout, "Сумма столбца %d : %f\n", j, Sum);
    }

    for (int i = 0 ; i < rows; ++i) {
        float temp = 0;
        temp = matrix[i][min_column];
        matrix[i][min_column] = matrix[i][max_column];
        matrix[i][max_column]= temp;
    }
    fprintf(stdout ,"\nИзменённая матрица \n");
    print_matrix(matrix, rows, columns);


}

int main () {
    fprintf(stdout,"\nВведите максимальное значение для элемента : ");
    if (scanf("%f", &MIN) != 1) {
        fprintf(stdout,"Ошибка ввода !\n");
        exit(1);
    }
    fprintf(stdout,"Введите минимальное значение для элемента : ");
    if (scanf("%f", &MIN) != 1) {
        fprintf(stdout,"Ошибка ввода !\n");
        exit(1);
    }
    srand(time(0));
    fprintf(stdout, "Введите количество строк : "); 
    if (scanf("%d", &n) != 1 || n >10) {
        fprintf(stdout, "Ошибка ввода !\n");
        exit(1);
    } 
    fprintf(stdout, "Введите количество столбцов : "); 
    if (scanf("%d", &m) != 1 || n >15) {
        fprintf(stdout, "Ошибка ввода !\n");
        exit(1);
    } 

    float** arr = memory_allocation(n , m); 
    fill_mairix(arr, n, m, MIN, MAX);
    fprintf(stdout, "Исходная матрица : \n");
    print_matrix(arr, n, m);
    change_matrix (arr, n, m);
 


for (int i = 0; i < n; ++i) {
    free (arr[i]);
}
free(arr);


    return 0 ;
}