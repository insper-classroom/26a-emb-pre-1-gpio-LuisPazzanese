#include <stdio.h>
#include <stdlib.h>

int multiplyNumbers(int x, int y) {
    int product = x * y;
    return product;
}

int main(void) {
    int a = 5;
    int b = 5; //uninitvar, legacyUninitvar
    int result = multiplyNumbers(a, b);

    printf("Result: %d\n", result);
    return 0;
}
