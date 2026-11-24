// Задача 1. «Максимальное произведение двух чисел»
// Тема: жадный выбор без сортировки, работа с краевыми случаями.

// Условие: Дан массив целых чисел (могут быть отрицательные).
// Найдите максимальное произведение двух чисел.

// Примеры: [1, 2, 3] -> 6 [1, 2, 3, 4] -> 12 [-1, -2, -3, 1] -> 6 [-10, -10, 5, 2] -> 100

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long maxProduct(vector<int>& nums) {
    long long max1 = LLONG_MIN, max2 = LLONG_MIN;
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;

    for (int x : nums) {
        if (x > max1) { max2 = max1; max1 = x; }
        else if (x > max2) { max2 = x; }

        if (x < min1) { min2 = min1; min1 = x; }
        else if (x < min2) { min2 = x; }
    }
    return max(max1 * max2, min1 * min2);
}

int main() {
    vector<vector<int>> tests = {
        {1, 2, 3},
        {1, 2, 3, 4},
        {-1, -2, -3, 1},
        {-10, -10, 5, 2}
    };

    for (auto& t : tests) {
        cout << maxProduct(t) << endl;
    }
    return 0;
}