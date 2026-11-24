#include "calc.h"
#include <stdexcept>
#include <string>
using namespace std;

void checkValidParams(int n, double a, double b, double h) {
    if (n <= 3)
        throw invalid_argument("n повинно бути більше 3");
    if (h <= 0)
        throw invalid_argument("крок h повинен бути більше 0");
    if (a > b)
        throw invalid_argument("початок проміжку a не може бути більшим за b");
}

int readInt(istream& in) {
    string s;
    in >> s;
    size_t pos = 0;
    int value;
    try {
        value = stoi(s, &pos);
    }
    catch (...) {
        throw invalid_argument("введено не ціле число: \"" + s + "\"");
    }
    if (pos != s.size())
        throw invalid_argument("введено не ціле число: \"" + s + "\"");
    return value;
}

double readDouble(istream& in) {
    string s;
    in >> s;
    size_t pos = 0;
    double value;
    try {
        value = stod(s, &pos);
    }
    catch (...) {
        throw invalid_argument("введено не число: \"" + s + "\"");
    }
    if (pos != s.size())
        throw invalid_argument("введено не число: \"" + s + "\"");
    return value;
}

double calcNegative(int n) {
    double p = 1;
    for (int j = 2; j <= n - 2; j++)
        p *= (j + 1);
    return p;
}

double calcPositive(double x, int n) {
    double s = 0;
    for (int i = 0; i <= n - 1; i++) {
        double p = 1;
        for (int j = 0; j <= n - 1; j++)
            p *= (x + i + j * j);
        s += p;
    }
    return s;
}

double calculate(double x, int n) {
    if (n <= 3)
        throw invalid_argument("n повинно бути більше 3");
    if (x < 0)
        return calcNegative(n);
    return calcPositive(x, n);
}
