// Задача 1. Максимальное произведение двух чисел
// Жадный алгоритм без сортировки, O(n) времени, O(1) памяти.
// Идея: максимальное произведение даёт либо пара двух максимумов,
// либо пара двух минимумов (самых отрицательных).

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

long long maxProduct(const std::vector<long long>& nums) {
    if (nums.size() < 2) {
        std::cerr << "Need at least 2 numbers\n";
        return 0;
    }

    long long max1 = LLONG_MIN, max2 = LLONG_MIN;
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;

    for (long long v : nums) {
        // два максимума
        if (v > max1)      { max2 = max1; max1 = v; }
        else if (v > max2) { max2 = v; }

        // два минимума
        if (v < min1)      { min2 = min1; min1 = v; }
        else if (v < min2) { min2 = v; }
    }

    return std::max(max1 * max2, min1 * min2);
}

int main() {
    std::cout << maxProduct({1, 2, 3})          << "\n"; // 6
    std::cout << maxProduct({1, 2, 3, 4})       << "\n"; // 12
    std::cout << maxProduct({-1, -2, -3, 1})    << "\n"; // 6
    std::cout << maxProduct({-10, -10, 5, 2})   << "\n"; // 100
    return 0;
}