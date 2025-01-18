#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int K = 0;
int K_be = 0;

int main () {

//char buffer[100]; 
char input[100];
printf("Введите строку : ");
if (fgets(input, sizeof(input), stdin ) != NULL ){
    size_t len = strlen(input) ;
    if (len != 0 && input [len - 1] == '\n') {
        input[len -1 ] = '\0' ;// Заменяем элемент перехода на новую строку элементом окончания строки
    }
} 
    printf("\nИсходная строка : ");
    printf("%s", input);


char beggining [2]; // вместо массива под один символ лучше исспользовать переменную типа char
char ending [2];

beggining [0] = input[0];
for (int i = 0 ; i<strlen(input); ++i) {
    if (input[i] == ' ') {
        K++ ;// Считаем  кол - во слов в строке 
        ending[0] = input[i-1];
        if (ending [0] == beggining[0]) {
            K_be ++;
            beggining[0] = input[i+1];
        }
    }
    else {
        ending [0] = input[i];
        
        if (ending [0] == beggining[0]) {
            K_be = 1;
        }  
    }
}

if (strlen(input) == 0 ) {
    printf ("Проверьте корректность ввода ");
}

    printf("\nКоличество слов в строке всего : %d ", K );
    printf("\nКоличество слов, начинающихся и заканчивающихся на одну и ту же букву : %d", K_be);
    if (K_be == 0) {
    printf("\nСлов, начинающихся и заканчивающихся на одну и ту же букву, нет.");
        }
return 0;
}
