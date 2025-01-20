#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {

fprintf(stdout, "\nВведите строку : \n");
char* line = NULL;
size_t size_line = 0;
ssize_t read = getline(&line, &size_line, stdin);
if (read == 0 ) {
    fprintf(stdout, "Ошибка чтения строки / пустая строка ");
    free (line);
    exit(1);
}
if (line[read - 1] == '\0' && read != 0) {
    line[read - 1] = '\n';
}

fprintf(stdout, "Введённая строка : %s", line);

char** tokens = NULL;
const char* delim = " ";
char* token = strtok (line, delim);
size_t size_tok = 0;

while (token != 0) {
    tokens = realloc (tokens, sizeof (char*) * (size_tok + 1));
    if (tokens == NULL) {
        fprintf(stdout, "\n\tОшибка выделения памяти под новый токен в массиве tokens\n");
        free(line);
        free (tokens) ;
        free (token);
        exit(2);
    }
    tokens[size_tok] = token;
                fprintf(stdout ,"token № %lu : %s\n", size_tok +1, token );
    token = strtok (NULL, delim);
    size_tok ++;
}
int k =0;
// удаляем из последовательности числа, кратные 5
fprintf(stdout , "Ответ на задачу : \n");
for  (int i = 0; i<size_tok; ++i) {
    if (atoi(&line[i]) % 5 != 0) {
        fprintf(stdout ,"%d  ", atoi(&line[i]));
        k++;

    }
}

if(k ==0) {
    fprintf (stdout, "\nЧисел, кратсных 5, нет ");

}
free (line);
free (tokens);
free (token);
return 0;
}
