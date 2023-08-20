#include <stdio.h>
#include "math_functions.h"

int main() {
    int32_t a = 10, b = 5;
    
    printf("Add: %ld\n", add(a, b));
    printf("Sub: %d\n", sub(a, b));
    printf("Mul: %ld\n", mul(a, b));
    printf("Sqrt64: %d\n", sqrt64(64));
    
    return 0;
}
