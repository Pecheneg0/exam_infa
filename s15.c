#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
int** memory_allocation (int n) {
	int** matrix = (int**)malloc (n* sizeof (int*));
	if (matrix == NULL) {	
		fprintf (stderr, "Ошибка выделения памяти !\n");
		free (matrix);
		exit (1)
	}
	for (int i = 0; i < n; ++i) {
		matrix[i] = (int*) malloc (n * sizeof(int));
		if (matrix[i] = NULL) {
			fprintf (stderr, "Ошибка ввода !\n");
			free (matrix [i]);
			exit (2);
		}
	}
	return matrix;
}
	
void fill_matrix (int** matrix, int n, int MIN, int MAX) {
	for (int i = 0; i< n; ++i) {
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = MIN + ((float)rand() / RAND_MAX ) * (MAX - MIN);
		}
	}
}

void change_matrix (int** matrix, int n) {
	int k = 0; // счётчик слов, кратных 7.
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] % 7 == 0) {
				k++;
			} 
		}
		if (k != 0) {
			matrix [i][i] = k;	
		}
	}
	fprintf (stdout, "Изменённая матрица : \n");
	print_matrix (matrix, n);
}

void print_matrix (int** matrix, int n){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			fprintf (stdout, "%d\t", matrix[i][j]);
		}
	fprintf (stdout, "\n");
	}
}

int main () {
srand (time (0));
int n = 0;
int MIN = 0;
int MAX = 0;

fprintf (stdout, "Введите число n : ");
if (scanf ("%d", &n) != 1  && n > 10)  {
	fprintf(stdout, "Ошибка считывания !");
	exit (3);
}

fprintf (stdout, "Введите минимальноое значение элемента : ");
if (scanf ("%d", &MIN) != 1 ) {
	fprintf (stdout, "Ошибка ввода ! \n");
	exit (4);
}

fprintf (stdout, "Введите максимальноое значение элемента : ");
if (scanf ("%d", &MAX) != 1 ) {
	fprintf (stdout, "Ошибка ввода ! \n");
	exit (5);
}

int** arr  = memory_allocation (n);
fill_matrix (arr, n , MIN, MAX);
fprintf (stdout, "\nИсходная матрица\n");
print_matrix (arr, n);
change_matrix (arr, n);


for (int i = 0; i < n; ++i ) {
	free (arr [i]);
}
free (arr);
	return 0;
}
