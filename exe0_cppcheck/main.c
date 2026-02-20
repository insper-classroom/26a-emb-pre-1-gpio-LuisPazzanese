#include <stdio.h>
#include <stdlib.h>

int multiplyNumbers(int x, int y) {
    int product = x * y;
    return product;
}

int main(void) {
    int result = multiplyNumbers(5,5);

    printf("Result: %d\n", result);
    return 0;
}
