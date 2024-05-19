#include <stdio.h>
#include "factorial.h"

long long int factorial(int n){
    if(n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}