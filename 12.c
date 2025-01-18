#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main () {
    char input [100];
printf("Введите строку : ");

if (fgets(input, sizeof(input), stdin ) != NULL) { 
    size_t len = strlen (input);
    if (len != 0 && input[len-1] == '\n') {
        input [len - 1] = '\0' ; // Теперь точно заканчивается строчка )
    }
}

int in_word  =0 ; // флаг, чтобы знать находимся ли в слове или нет 
int K = 0; // счётчик слов в строке 
int K_g = 0;
char begginning = '\0'; // символ в начале 1-го слова


printf("Исходная строка : %s\t", input);
for (int i = 0; i < strlen(input); ++i) {
    if (isalpha(input[i]) ) { // Проверяем, является ли симол буквой 
        if (!in_word) {
            K++;
            begginning = tolower(input[i]);
            if (begginning == 'a' || begginning == 'o' || begginning == 'e' || begginning == 'i' || begginning == 'u' ) {
                K_g++;
            }
            in_word = 1;
        }
    }
    else {

        in_word = 0;
    }
}

if (K_g == 0 ) {
    printf("\n Слов, начинающихся с гласных букв на латинице, нет ");
} 
printf("\nКоличество слов в строке %d", K);
printf("\nКоличество слов в строке, начинающихся с гласных букв на латинице : %d", K_g);


return 0;
}