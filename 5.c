#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float MIN = -100.0; 
float MAX = 100.0; 
float sum_min = 2000000;
float sum_max = -2000000;
int m,n;
int N_max;
int N_min;

void summ_matrix (float** matrix, int row, int column ) {
    for (int j = 0; j < column; ++j) {
        float sum = 0;
        for (int i =0; i < row ; ++i) {
            sum += matrix[i][j];
        }
        if (sum > sum_max) {
            sum_max = sum;
            N_max = j;
        }
        if (sum < sum_min) {
            sum_min = sum;
            N_min = j;
        }
    }

printf("\n\nНомер столбца с минимальной суммой : %d \n", N_min+1);
printf("Номер столбца с максимальной суммой : %d\n", N_max+1);
printf("Минимальная сумма : %f\n", sum_min);
printf("Максимальная сумма : %f\n", sum_max);


}
void fill_matrix (float** matrix, int row, int column) {
    for (int i =0; i<row ; ++i) {
        for (int j = 0; j<column; ++j) {
            matrix[i][j] = MIN + ((float)rand() / RAND_MAX) * (MAX - MIN);
        }
    }
}

void change_matrix (float** matrix, int N_max, int N_min) {

    printf("Исходная матрица:\n" );
    for (int i =0; i<n; ++i) {
        for (int j =0 ; j<m; ++j) {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i<n; ++i) {
        float k = 0;
        k = matrix[i][N_max];
        matrix [i][N_max] = matrix [i][N_min];
        matrix [i][N_min] = k;
    }
    printf("\nПреобразованная матрица : \n");
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            printf ("%f\t", matrix[i][j]);
        }
        printf("\n");
    
    }
}

int main () {
srand(time(0));
printf("\nВведите количество строк : ");
if (scanf("%d", &n) != 1 || n<1 || n> 10) {
    printf("Ошибка ввода !");
    exit (1);
} 
printf("Введите количество столбцов : ");
if (scanf("%d", &m) != 1 || m<1 || m>15) {
    printf("Ошибка ввода !");
    exit (1);
} 

float** arr = (float**) malloc(n * sizeof(float*)) ;
for (int i = 0; i<n; ++i) {
    arr[i] = (float*) malloc(m * sizeof(float));
}

fill_matrix(arr, n, m);
summ_matrix(arr, n, m);
change_matrix(arr, N_max, N_min);

for (int i = 0; i<n; ++i) {
    free (arr[i]);
    arr[i] = NULL;
}
free (arr);
return 0;
}