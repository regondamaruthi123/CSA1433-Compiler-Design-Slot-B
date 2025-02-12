#include <stdio.h>

int main() {
    int a = 5, b = 10;
    int common_expr = a * b; 
    int result1 = common_expr + a;
    int result2 = common_expr - b;

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);

    return 0;
}
