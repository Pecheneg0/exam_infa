#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int MIN = -100.0;
int MAX = 100.0;
int m = 4;
int n = 5;
void print_matrix (float** matrix, int raw, int column);
int main () {

int a = 56; 
int *p = &a;
float **arr = (float**) malloc( m * sizeof (float*)) ;
for (int i = 0; i<m; ++i) {
    arr[i] = (float*)malloc (n * sizeof(float));
}

for (int i = 0 ;i< m ; ++i) {
    for (int j = 0; j<n ; ++j) {
        arr[i][j] = MIN + ((float) rand() / RAND_MAX )* (MAX - MIN) ;
    } 
}
print_matrix(arr, m, n );
for (int i = 0; i<m ; ++i) {
    free (arr[i]); 
    arr[i] = NULL;
}
printf("%c", a);
free (arr);
return 0; 
}



void print_matrix (float** matrix, int raw , int column) {
   
    for (int i = 0 ;i< raw ; ++i) {
        for (int j = 0; j<n ; ++j) {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
}