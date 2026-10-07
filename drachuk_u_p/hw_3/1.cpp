// Домашнее задание 3. Задача 1. «Максимальное произведение двух чисел»
// Тема: жадный выбор без сортировки, работа с краевыми случаями.

// Условие: Дан массив целых чисел (могут быть отрицательные).
// Найдите максимальное произведение двух чисел.

// Примеры:
// [1, 2, 3]         -> 6
// [1, 2, 3, 4]      -> 12
// [-1, -2, -3, 1]   -> 6
// [-10, -10, 5, 2]  -> 100

// Идея: максимальное произведение получается одним из двух способов:
//   1) два самых больших числа (max1 * max2);
//   2) два самых маленьких числа (min1 * min2), потому что минус на минус даёт плюс.
// Сортировка не нужна: за один проход находим 2 максимума и 2 минимума.
// Ответ: max(max1 * max2, min1 * min2).

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cassert>
using namespace std;

int maxProduct(const vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return 0; // краевой случай: нельзя выбрать два числа

    int max1 = INT_MIN, max2 = INT_MIN; // два самых больших
    int min1 = INT_MAX, min2 = INT_MAX; // два самых маленьких

    for (int i = 0; i < n; i++) {
        int x = arr[i];

        if (x > max1) {
            max2 = max1;
            max1 = x;
        } else if (x > max2) {
            max2 = x;
        }

        if (x < min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }
    return max(max1 * max2, min1 * min2);
}

void runTests() {
    // Примеры из условия
    assert(maxProduct({1, 2, 3}) == 6);
    assert(maxProduct({1, 2, 3, 4}) == 12);
    assert(maxProduct({-1, -2, -3, 1}) == 6);
    assert(maxProduct({-10, -10, 5, 2}) == 100);

    // Краевые случаи
    assert(maxProduct({}) == 0);
    assert(maxProduct({5}) == 0);
    assert(maxProduct({-3, 2}) == -6);
    assert(maxProduct({-5, -4}) == 20);
    assert(maxProduct({0, 0}) == 0);
    assert(maxProduct({-1, -2, -3}) == 6);

    cout << "Все тесты пройдены!" << endl;
}

int main() {
    runTests();
    cout << maxProduct({-10, -10, 5, 2}) << endl;
    return 0;
}

// Сложность: O(n) по времени, O(1) по памяти.