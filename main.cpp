// Лабораторна робота №3, варіант 3
// Програма з ЛР2, розбита на функції, з обробкою винятків (try, throw, catch)
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include "calc.h"
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    try {
        cout << "Обчислення виразу (варіант 3)" << endl;
        cout << "Введіть n (n > 3): ";
        int n = readInt(cin);
        cout << "Введіть початок проміжку a: ";
        double a = readDouble(cin);
        cout << "Введіть кінець проміжку b: ";
        double b = readDouble(cin);
        cout << "Введіть крок h: ";
        double h = readDouble(cin);

        checkValidParams(n, a, b, h);

        cout << endl << setw(10) << "x" << setw(20) << "y" << endl;
        int steps = (int)floor((b - a) / h + 1e-9);
        for (int k = 0; k <= steps; k++) {
            double x = a + k * h;
            cout << setw(10) << fixed << setprecision(2) << x
                 << setw(20) << setprecision(4) << calculate(x, n) << endl;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Помилка: " << e.what() << endl;
        return 1;
    }
    return 0;
}
