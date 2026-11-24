// calc.h - функції для обчислення виразу (варіант 3)
#pragma once
#include <iostream>

// перевірка параметрів: n > 3, a <= b, h > 0
// якщо щось не так - кидає виняток std::invalid_argument
void checkValidParams(int n, double a, double b, double h);

// читає число з потоку, якщо введено не число - кидає виняток
int readInt(std::istream& in);
double readDouble(std::istream& in);

// добуток (j + 1) для j від 2 до n-2  (гілка x < 0)
double calcNegative(int n);

// сума добутків (x + i + j^2)  (гілка x >= 0)
double calcPositive(double x, int n);

// значення y(x) для заданого n
double calculate(double x, int n);
