#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

int main () {
    char input [100];
    char massive [100];
    int index =0 ;
printf("Введите строку : ");
scanf("%99s", input);
for (int i = 0 ; i< strlen(input) ; ++i) {
    printf("input[%d] = %c", i+1, input[i]);
    printf("\n");
}
for (int i = 1 ; i< strlen(input); ++i) {
    if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'u'|| input[i] == 'o' 
     ||input[i] ==  'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'U'|| input[i] == 'O') {
    continue;
    }
    if (isdigit(input[i])) {
        continue;
    }
    massive [index++] = input[i] ;
  
}
printf("\nИзменённая строка : \n"); 
for (int i = 0 ; i < strlen(massive) ; ++i) {
    printf("massive[%d] = %c \n", i+1, massive[i]);
}





return 0;
}