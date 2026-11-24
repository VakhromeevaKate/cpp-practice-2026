//  Задача 1. «Максимальное произведение двух чисел» Тема: жадный выбор без сортировки, работа с краевыми случаями.

//Условие: Дан массив целых чисел (могут быть отрицательные). Найдите максимальное произведение двух чисел.

// максимальное произведение может получиться
// 1. из двух самых больших чисел
// 2. из двух самых маленьких отрицательных чисел
//
// будем искать два максимальных и два минимальных числа

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int maxProduct(const vector<int>& arr) {
    int n = arr.size();

    if (n < 2) return 0;

    int max1 = arr[0];
    int max2 = arr[1];

    int min1 = arr[0];
    int min2 = arr[1];

    if (max1 < max2) {
        swap(max1, max2);
    }

    if (min1 > min2) {
        swap(min1, min2);
    }

    for (int i = 2; i < n; i++) {
        // ищем два самых больших числа
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2) {
            max2 = arr[i];
        }

        // ищем два самых маленьких числа
        if (arr[i] < min1) {
            min2 = min1;
            min1 = arr[i];
        }
        else if (arr[i] < min2) {
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
    assert(maxProduct({-5, -4, -3}) == 20);
    assert(maxProduct({2, 3}) == 6);
    assert(maxProduct({-2, 0, 5}) == 0);

    cout << "accessed" << endl;
}


int main() {
    runTests();
    // Демонстрация
    vector<int> demo = {-10, -10, 5, 2};
    cout << "answer: " << maxProduct(demo) << endl;

    return 0;
}

