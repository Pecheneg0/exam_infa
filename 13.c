#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main () {
printf("\nВведите строку : ") ;
char input [100];
char buffer [10];
if (fgets (input, sizeof(input), stdin) != NULL) {
    size_t len = strlen(input);
    if ( len != 0 && input [len -1 ] == '\n') {
        input [len -1 ] = '\0';
    }
}


int K =0;
int buf_len = 0; 
printf("\nИсходная строка : %s" , input);
 
for (int i =0 ; input[i] != '\0' ; ++i) {

    if (isalpha(input[i]) || input[i] == '\n') {
        buffer[buf_len++] = input[i];
    }
    else {
        if (buf_len>0) {
            buffer [buf_len] = '\0';
            if (buf_len < 5) {
                printf("\nСлово : %s", buffer);
                K++;
            }
            buf_len = 0;
        }
       
    }
}

// Проверка для последнего слова без пробела в конце
if (buf_len>0) {
            buffer [buf_len] = '\0';
            if (buf_len < 5) {
                printf("\nСлово : %s", buffer);
                K++;
            }
            buf_len = 0;
        }

if (K == 0) {
    printf("\nСлов, сост. из менее 5 букв, нет ");
}
else {
    printf("\nКоличество слов сост. из менее 5 букв : %d", K);
}
return 0; 
}
