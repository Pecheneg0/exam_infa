#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main () {
    FILE *text_file;
    char buffer [200];
    char result [200];
    int index =0 ;

    text_file = fopen("text_e1.txt", "r");
    if (text_file == NULL) {
        printf("Ошибка чтения файла !");
        return 1 ;
    }
    if (fgets(buffer, sizeof(buffer), text_file )!= NULL) {
        printf("Исходный файл : %s\n", buffer);
    }
    fclose (text_file);

for (int i =0 ; i< strlen(buffer); ++i) {
    if (isdigit(buffer[i])) {
        continue;
    }
    if (buffer[i] == '!' ||buffer[i] == '?' || buffer[i] == '_' || buffer[i] == ' ' || buffer[i] == '/' ){
        continue;
    }
    result[index++] = buffer [i];
}

        printf("%s\n", result);

    
return 0;
}