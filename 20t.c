#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main () {


fprintf(stdout, "\nВведите строку : ");
char* line = NULL;
size_t size_l = 0;
ssize_t read = getline (&line, &size_l, stdin);
if (read == -1) {
    fprintf(stdout, "Ошибка чтения строки ");
    free (line);
    exit (1);
}
if (read != 0 && line[read - 1 ]== '\n') {
    line [read - 1 ] = '\0';
}

fprintf(stdout, "\nИсходная строка : %s", line) ;

char** tokens = NULL;
const char* delim = " ";
size_t size_tok = 0; // количество токенов в tokens
char* token = strtok (line, delim);

while (token != 0) {
    tokens = realloc (tokens, sizeof(char*) * (size_tok + 1));
    if (tokens == NULL) {
        fprintf(stdout, "Ошибка при увеличении массива !");
        free (line);
        free (tokens);
        exit (1);
    }
    tokens [size_tok] = token;
    fprintf(stdout, "Token № %lu : %s\n", size_tok + 1, token);
    token = strtok(NULL, delim);
    size_tok++;
}
float k =0;
float sum = 0;
fprintf(stdout , "\nОтвет на задачу :\n");
for (int i =0; i<size_tok; ++i) {
    float num  = atof(tokens[i]);
    //fprintf(stdout, "Number № %d : %f\n", i+1, num);
    if (num > 0) {
        fprintf(stdout, "Number (> 0) № %d: %.3f\n", i+1, num );
        k++;
        sum += num;
    }
}

if (k==0) {
    fprintf(stdout, "\nПоложительных чисел нет. ");
}

fprintf(stdout, "\nСреднее арифметическое = %.3f ", sum/k);


return 0 ;
}