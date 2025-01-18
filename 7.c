#include <stdio.h>
int main () {
char letter[] = "Pisymo schastya";
    for (int i =0; letter[i] != '\0'; ++i) {
    
        if (letter[i] == ' '){
            printf("blya, probel \n");
            letter[i] = '-';
        }
    
        printf("letter[%d] = %c \n",i, letter[i]);
    }

return 0;
}