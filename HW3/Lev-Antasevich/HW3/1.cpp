// Задача 1. «Максимальное произведение двух чисел»

// Условие: Дан массив целых чисел (могут быть отрицательные). Найдите максимальное произведение двух чисел.

// Примеры:
// [1, 2, 3]          -> 6
// [1, 2, 3, 4]       -> 12
// [-1, -2, -3, 1]    -> 6
// [-10, -10, 5, 2]   -> 100

// Решение: жадный алгоритм — находим два максимальных и два минимальных числа.
// Максимальное произведение будет либо max1 * max2, либо min1 * min2.

#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

int maxProduct(const vector<int>& arr) {
    int n = arr.size();
    if (n < 2) return 0;

    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int min1 = INT_MAX;
    int min2 = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2) {
            max2 = arr[i];
        }

        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        } else if (arr[i] < min2) {
            min2 = arr[i];
        }
    }

    return max(max1 * max2, min1 * min2);
}

void runTests() {
    assert(maxProduct({1, 2, 3}) == 6);
    assert(maxProduct({1, 2, 3, 4}) == 12);
    assert(maxProduct({-1, -2, -3, 1}) == 6);
    assert(maxProduct({-10, -10, 5, 2}) == 100);
    assert(maxProduct({5}) == 0);
    assert(maxProduct({}) == 0);
    assert(maxProduct({-5, -4, -3, -2, -1}) == 20);
    assert(maxProduct({0, 1, 2, 3}) == 6);
    assert(maxProduct({-100, 1, 2, 3}) == 6);
    assert(maxProduct({-100, -200, 3, 4}) == 20000);
    cout << "Все тесты пройдены!" << endl;
}

int main() {
    runTests();

    vector<int> demo1 = {1, 2, 3};
    vector<int> demo2 = {-10, -10, 5, 2};
    cout << "maxProduct({1, 2, 3}) = " << maxProduct(demo1) << endl;
    cout << "maxProduct({-10, -10, 5, 2}) = " << maxProduct(demo2) << endl;

    return 0;
}