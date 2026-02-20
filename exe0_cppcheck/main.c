#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMENTS 5

int multiplyNumbers(int x, int y) {
    int product = x * y;
    return product;
}

int main(void) {
    int a = NUM_ELEMENTS;
    int b = NUM_ELEMENTS; //uninitvar, legacyUninitvar
    int result = multiplyNumbers(a, b);

    printf("Result: %d\n", result);
    return 0;
}
