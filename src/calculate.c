#include "calculate.h"

#include <stdio.h>
#include <limits.h>

// Implementasi fungsi-fungsi dasar matematika.
int sum(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        fprintf(stderr, "Error: Division by zero.\n");
        return 0;
    }
}

int calculate(int a, int b, int (*op)(int, int)) { return op(a, b); }
float circleArea(int radius) { return M_PI * radius * radius; }