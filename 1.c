#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a; // Указатель p хранит адрес переменной a

    printf("Значение a: %d\n", a);
    printf("Адрес a: %p\n", (void*)&a);
    printf("Значение через указатель: %d\n", *p);

    *p = 20; // Изменяем значение переменной a через указатель
    printf("Новое значение a: %d\n", a);

    return 0;
}
