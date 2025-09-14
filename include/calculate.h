#pragma once
#include <math.h>

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int divide(int a, int b);

int calculate(int a, int b, int (*op)(int, int));
float circleArea(int radius);