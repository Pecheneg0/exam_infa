#include <stdio.h>


void increment (int *ukasatel) {
    (*ukasatel)++;
}
int main () {
    int a = -100 ; 
    increment(&a); 
    printf("a = %d\n", a );

return 0;
}