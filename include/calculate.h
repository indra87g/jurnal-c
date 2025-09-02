#pragma once

int sum(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int calculate(int a, int b, int (*op)(int, int));