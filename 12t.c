#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int main () {

fprintf(stdout, "Введите строку : ") ;
char* line = NULL;
size_t size_l = 0;
ssize_t read = getline(&line, &size_l, stdin);
if (line == NULL) {
    fprintf(stdout, "Ошибка чтения строки ");
    free(line);
    exit (1);
}
if (read > 0 && line[read - 1] == '\n' ) {
    line [read -1 ] = '\0';
}
fprintf(stdout, "\nИсходная строка : %s\n", line);

char** tokens = NULL;
const char* delim = " ";
char* tok = strtok(line , delim );
size_t len_t = 0; // количество токенов в масстве tokens 

while (tok != 0) {
    tokens = realloc(tokens, (len_t + 1) * sizeof(char*));
    if (tokens == NULL) {
        fprintf(stdout, "Ошибка увеличения массива !");
        free (line);
        free(tokens);
        exit(1);
    }
    tokens [len_t] = tok;
    tok = strtok(NULL, delim) ;
    len_t++;
}
fprintf(stdout, "\nСтрока по токенам : \n");
for (int i = 0 ; i< len_t; ++i) {
    fprintf(stdout, "Токен № %d : %s \n", i+1, tokens[i]);
}



fprintf(stdout, "\nОтвет на задачу : \n");
for (int i = 0 ; i< len_t; ++i) {
    int num = atoi(tokens[i]);
    if (num == 0) {
        fprintf(stdout, "\nОшибка преобразования строки в целочисленый тип данных !");
        free(tokens);
        free(line);
        exit(2);
        
    }
    if (num > 10) {
        fprintf(stdout , "Число № %d : %d\n", i+1, num);
    }
} 



free(line);
free(tokens);
fprintf(stdout, "\nПрограмма завершена.");
return 0;
}