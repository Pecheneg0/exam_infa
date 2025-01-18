#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

int main () {
fprintf(stdout, "Введите строку : ");
char* line = NULL;
size_t size_l = 0;
ssize_t read = getline(&line, &size_l, stdin);
if (read == 0) {
    fprintf(stdout,"\nError, read is None");
    free (line);
    exit(1);
} 

if (read != 0 && line[read -1] == '\n') {
    line[read - 1] = '\0'; 
}

fprintf(stdout, "Исходная строка : %s \n", line);

char** tokens = NULL;
const char* delim = " ";
ssize_t size_tok = 0;
char* token = strtok(line, delim);

char minword [100], maxword[100];

while (token != 0) {
    tokens = realloc(tokens, sizeof(char*) * (size_tok + 1));
    if (tokens == NULL) {
        fprintf(stdout, "\nОшибка увеличения массива tokens\n ");
        free(line); 
        free(tokens);
        exit(2);
    }
    fprintf(stdout,"Token %zu: %s\n", size_tok+1, token);
    tokens[size_tok] = token;
    token = strtok(NULL, delim);
    ++size_tok;
}


strcpy(minword, tokens[0]);
strcpy(maxword, tokens[0]);
int minnumber = 0;
int maxnumber = 0;
for (int i = 1; i<size_tok; ++i) {
    if (strcmp(tokens[i], minword) < 0) {
        strcpy (minword, tokens[i]);
        minnumber = size_tok;
    }
    if (strcmp(tokens[i], maxword) >0 ) {
        strcpy(maxword, tokens[i]);
        maxnumber = size_tok;
    }
}

fprintf(stdout, "\n Мин. слово : %s\n Номер в списке : %d\n\n Макс. слово : %s\n Номер в списке : %d ", minword, minnumber, maxword, maxnumber );
return 0;
}