#include "stdio.h"

int foo(int a) {
    a = a + 1; // acessa variavel global
    return a;
}

void main(void) {
    int a = 0; // var global
    int b = 0; // var global

    b = foo(a);
    printf("Valor de b: %d\n", b);

}
