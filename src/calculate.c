#include <stdio.h>

int sum(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int div(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        return 1;
    }
}

int calculate(int a, int b, int (*op)(int, int)) { return op(a, b); }