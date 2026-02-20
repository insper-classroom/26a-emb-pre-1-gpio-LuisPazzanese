#include "stdio.h"

int foo(int a) {
    a = a + 1; // acessa variavel global
    return a;
}

void main(void) {
    int a = 0; // var global
    int b = 0; // var global

    while (1) {
        foo(a);
        
        if (a > 5) {
            b = 1;
        }
    }
}
