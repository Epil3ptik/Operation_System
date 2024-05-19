#include <stdio.h>
#include "factorial.h"

int main(){
    int n = 11;
    printf("Factorial of %d = %lld\n", n, factorial(n));
    return 0;
}
