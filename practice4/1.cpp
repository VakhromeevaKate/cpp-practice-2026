// Задача 1. Обмен значений: три способа (ссылки)
// Условие. Напишите три версии функции swap: через указатели,
// через ссылки и через std::swap.
// Продемонстрируйте, что все три меняют местами значения двух переменных.

#include <iostream>
#include <utility>   // для std::swap

// Версия 1: через указатели
void swapPtr(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Версия 2: через ссылки (чище, без разыменований)
void swapRef(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int x = 1, y = 2;

    swapPtr(&x, &y);
    std::cout << "После swapPtr: x = " << x << ", y = " << y << "\n"; // 2, 1

    x = 10; y = 20;
    swapRef(x, y);
    std::cout << "После swapRef: x = " << x << ", y = " << y << "\n"; // 20, 10

    x = 100; y = 200;
    std::swap(x, y);
    std::cout << "После std::swap: x = " << x << ", y = " << y << "\n"; // 200, 100
    return 0;
}