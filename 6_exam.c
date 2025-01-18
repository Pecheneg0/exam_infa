#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int** memory_allocation (int* rows, int* columns){
    int** matrix = (int**) malloc(*rows * sizeof(int*));
    for (int i = 0; i<*rows; ++i ) {
        matrix[i] = (int*) malloc(*columns * sizeof(int));
    }
    return matrix;
}
void free_all(int* rows, int* columns, int* MIN, int* MAX ){
    free(rows);
    free(columns);
    free(MIN);
    free(MAX); 
}
void fill_matrix(int** matrix, int* rows, int* columns, int* MIN, int* MAX ) {
    for (int i = 0; i < *rows; ++i ) {
        for(int j =0; j < *columns; ++j) {
            matrix [i][j] = *MIN + ((float)rand() / RAND_MAX) * (*MAX - *MIN);
        }
    }
}

void printmatrix (int** matrix, int* rows, int* columns) {
    for (int i = 0; i < *rows; ++i ) {
        for(int j =0; j < *columns; ++j) {

            fprintf(stdout, "%d\t", matrix[i][j]);
        }
        fprintf(stdout, "\n");
    }
}
void change_matrix(int** matrix, int* rows, int* columns) {
    int cols = *columns;
    for (int j = 0; j < cols; ++j) {
        if (matrix[0][j] % 3 == 0) {
            for (int k  = j + 1 ; k < cols; ++k) {
                for (int i = 0; i<*rows; ++i){
                    matrix[i][k-1] = matrix[i][k];
                }
            }
            cols--; //чтобы не было выхода за пределы 
            j--; // для проверки перенесённого столбца.
        }
         
    }
    *columns = cols;
    fprintf(stdout, "\nИзменённая матрица : \n"); 
    printmatrix(matrix, rows, columns );
}

int main() {
srand(time(0));
int* n = malloc (sizeof(int));
int* m = malloc (sizeof(int)); 
int* MIN = malloc(sizeof(int));
int* MAX = malloc(sizeof(int));

if (n == NULL || m == NULL) {
    fprintf(stdout, "\nОшибка выделени памяти. ");
    exit(1);
}

fprintf(stdout, "\nВведите количество строк : ");
if (scanf("%d",n) != 1 || *n > 20) {
    fprintf(stdout, "Ошибка ввода ");
    free_all(n,m,MIN,MAX);
    exit(2);
}

fprintf(stdout, "\nВведите количество столбцов : ");
if (scanf("%d",m) != 1 || *m > 20) {
    fprintf(stdout, "Ошибка ввода ");
    free_all(n,m,MIN,MAX);
    exit(3);
}

fprintf(stdout, "\nВведите минимальный элемент : ");
if (scanf("%d",MIN) != 1) {
    fprintf(stdout, "Ошибка ввода ");
    free_all(n,m,MIN,MAX);
    exit(4);
}

fprintf(stdout, "\nВведите максимальный элемент : ");
if (scanf("%d",MAX) != 1) {
    fprintf(stdout, "Ошибка ввода ");
    free_all(n,m,MIN,MAX);
    exit(5);
}

fprintf(stdout,"\n\tRows : %d", *n);
fprintf(stdout,"\n\tColumns : %d", *m);

int** arr  = memory_allocation (n,m);
fill_matrix(arr, n, m, MIN, MAX );
fprintf(stdout, "\nИсходная матрица : \n");
printmatrix(arr, n ,m);
change_matrix(arr, n , m);

free_all(n ,m, MIN, MAX);
for (int i =0; i< *n; ++i){
    free(arr[i]);
}
free(arr);
arr = NULL;
return 0;
}