#include <stdio.h>

int main() {
    const char *words[] = {"Привет", "Мир", "C"};
    
    for (int i = 0; i < 3; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
